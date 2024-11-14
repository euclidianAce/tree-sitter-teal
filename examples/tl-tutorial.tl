--[[  Your first Teal program ]]

local function add(a: number, b: number): number
   return a + b
end

local s = add(1,2)
print(s)


local addsub = {}

function addsub.add(a: number, b: number): number
   return a + b
end

function addsub.sub(a: number, b: number): number
   return a - b
end

return addsub




--[[  Types in Teal ]]

-- an enum: a set of accepted strings
local enum State
   "open"
   "closed"
end

-- a record: a table with a known set of fields
local record Point
   x: number
   y: number
end

-- an interface: an abstract record type
local interface Character
   sprite: Image
   position: Point
   kind: string
end

-- records can implement interfaces, using a type-identifying `where` clause
local record Spaceship
   is Character
   where self.kind == "spaceship"

   weapon: Weapons
end

-- a record can also declare an array interface, making it double as a record and an array
local record TreeNode<T>
   is {TreeNode<T>}

   item: T
end

-- a userdata record: a record which is implemented as a userdata
local record File
   is userdata

   status: function(): State
   close: function(File): boolean, string
end




--[[  Local variables ]]

local x -- Error! What is this?


local s: string
local r, g, b: number, number, number
local ok: boolean


local s = "hello"
local r, g, b = 0, 128, 128
local ok = true




--[[  Arrays ]]

local values: {number}
local names = {"John", "Paul", "George", "Ringo"}


local prices: {number} = {}


local lengths = {}
for i, n in ipairs(names) do
   table.insert(lengths, #n) -- this makes the  lengths table a {number}
end


local sizes: {number} = {34, 36, 38}
sizes[#sizes + 1] = true as number -- this does not perform a conversion! it will just stop tl from complaining!
local sum = 0
for i = 1, #sizes do
   sum = sum + sizes[i] -- will crash at runtime!
end




--[[  Tuples ]]

-- Tuples of type {string, integer} containing names and ages
local p1 = { "Anna", 15 }
local p2 = { "Bob", 37 }
local p3 = { "Chris", 65 }


local age_of_p1: number = p1[2] -- no type errors here
local nonsense = p1[3] -- error! index 3 out of range for tuple {1: string, 2: integer}


local my_number = math.random(1, 2)
local x = p1[my_number] -- => x is a string | number union
if x is string then
   print("Name is " .. x .. "!")
else
   print("Age is " .. x)
end


local p4: {string, integer} = { "Delilah", 32, false } -- error! expected maximum length of 2, got 3


local array_of_union: {string | number} = {1, 2, "hello", "hi"}


local tuple_of_nums: {number, number} = {1, 2}




--[[  Maps ]]

local populations: {string:number}
local complicated: {Object:{string:{Point}}} = {}
local modes = { -- this is {boolean:number}
   [false] = 127,
   [true] = 230,
}


local is_vowel: {string:boolean} = {
   a = true,
   e = true,
   i = true,
   o = true,
   u = true,
}




--[[  Records ]]

local type Point = record
   x: number
   y: number
end


local record Point
   x: number
   y: number
end


local p: Point = { x = 100, y = 100 }


local record Vector
   x: number
   y: number
end

local v1: Vector = { x = 100, y = 100 }
local p2: Point = v1 -- Error!


local p2 = v1 as Point -- Teal goes "ok, I'll trust you..."


function Point.new(x: number, y: number): Point
   local self: Point = setmetatable({}, { __index = Point })
   self.x = x or 0
   self.y = y or 0
   return self
end

function Point:move(dx: number, dy: number)
   self.x = self.x + dx
   self.y = self.y + dy
end


local record Obj
   location: Point
   draw: function(Obj)
end


local record Node is {Node}
   weight: number
   name: string
end


local record http

   record Response
      status_code: number
   end

   get: function(string): Response
end

return http


local http = require("http")

local x: http.Response = http.get("http://example.com")
print(x.status_code)




--[[  Interfaces ]]

local record MyConcreteRecord
   a: string
   x: integer
   y: integer
end

MyConcreteRecord.a = "this works"

local obj: MyConcreteRecord = { x = 10, y = 20 } -- this works too


local interface MyAbstractInterface
   a: string
   x: integer
   y: integer
   my_func: function(self, integer)
   another_func: function(self, integer, self)
end

MyAbstractInterface.a = "this doesn't work" -- error!

local obj: MyAbstractInterface = { x = 10, y = 20 } -- this works

-- error! this doesn't work
function MyAbstractInterface:my_func(n: integer)
end

-- however, this works
obj.my_func = function(self: MyAbstractInterface, n: integer)
end


local record MyRecord is MyAbstractInterface
   b: string
end

local r: MyRecord = {}
r.b = "this works"
r.a = "this works too because 'a' comes from MyAbstractInterface"


-- the following function complies to the type declared for `another_func`
-- in MyAbstractInterface, because MyRecord is the `self` type in this context
function MyRecord:another_func(n: integer, another: MyRecord)
   print(n + self.x, another.b)
end


local interface Shape
   x: number
   y: number
end

local interface Colorful
   r: integer
   g: integer
   b: integer
end

local interface SecondPoint
   x2: number
   y2: number
   get_distance: function(self): number
end

local record Line is Shape, SecondPoint
end

local record Square is Shape, SecondPoint, Colorful
   get_area: function(self): number
end

--[[
-- this produces a record with these fields,
-- but Square also satisfies `Square is Shape`,
-- `Square is SecondPoint`, `Square is Colorful`
local record Square
   x: number
   y: number
   x2: number
   y2: number
   get_distance: function(self): number
   r: integer
   g: integer
   b: integer
   get_area: function(self): number
end
]]




--[[  Generics ]]

local function keys<K,V>(xs: {K:V}):{K}
   local ks = {}
   for k, v in pairs(xs) do
      table.insert(ks, k)
   end
   return ks
end

local s = keys({ a = 1, b = 2 }) -- s is {string}


local type Tree = record<X>
   {Tree<X>}
   item: X
end

local t: Tree<number> = {
   item = 1,
   { item = 2 },
   { item = 3, { item = 4 } },
}


local function largest_shape<S is Shape>(shapes: {S}): S
   local max = 0
   local largest: S
   for _, s in ipairs(shapes) do
      if s.area >= max then
         max = s.area
         largest = s
      end
   end
   return largest
end




--[[  Metamethods ]]

local type Rec = record
   x: number
   metamethod __call: function(Rec, string, number): string
   metamethod __add: function(Rec, Rec): Rec
end

local rec_mt: metatable<Rec>
rec_mt = {
   __call = function(self: Rec, s: string, n: number): string
      return tostring(self.x * n) .. s
   end,
   __add = function(a: Rec, b: Rec): Rec
      local res: Rec = setmetatable({}, rec_mt)
      res.x = a.x + b.x
      return res
   end,
}

local r: Rec = setmetatable({ x = 10 }, rec_mt)
local s: Rec = setmetatable({ x = 20 }, rec_mt)

r.x = 12
print(r("!!!", 1000)) -- prints 12000!!!
print((r + s).x)      -- prints 32




--[[  Enums ]]

local type Direction = enum
   "north"
   "south"
   "east"
   "west"
end


local enum Direction
   "north"
   "south"
   "east"
   "west"
end




--[[  Functions ]]

local type Comparator = function<T>(T, T): boolean

local function mysort<A>(arr: {A}, cmp?: Comparator<A>)
   -- ...
end


f: function(function(? string):(number, number), number)


local function allwords(): (function(): string)
   local line = io.read()
   local pos = 1
   return function(): string
      while line do
         local s, e = line:find("%w+", pos)
         if s then
            pos = e + 1
            return line:sub(s, e)
         else
            line = io.read()
            pos = 1
         end
      end
      return nil
   end
end

for word in allwords() do
   print(word)
end




--[[ # Variadic functions ]]

local function test(...: number)
   print(...)
end

test(1, 2, 3)


local function test(...: number): number...
   return ...
end

local a, b, c = test(1, 2, 3)


local s = { 1234, "ola" }
local a, b = table.unpack(s) as (number, string)

print(a + 1)      -- `a` has type number
print(b:upper())  -- `b` has type string




--[[  Union types ]]

local a: string | number | MyRecord
local b: {boolean} | MyEnum
local c: number | {string:number}


local a: string | number | MyRecord

if a is string then
   print("Hello, " .. a)
elseif a is number then
   print(a + 10)
else
   print(a.my_record_field)
end


local a: string | number

local x: number = a is number and a + 1 or 0




--[[  Variable attributes ]]



--[[ # Const variables ]]

local xs <const> = {1,2,3}
xs[1] = 999 -- ok! the array is not frozen
xs = {} -- Error! can't replace the array in variable xs




--[[ # To-be-closed variables ]]

local contents = {}
for _, name in ipairs(filenames) do
   local f <close> = assert(io.open(name, "r"))
   contents[name] = f:read("*a")
   -- no need to call f:close() because files have a __close metamethod
end




--[[ # Total variables ]]

local degrees <total>: {Direction:number} = {
   ["north"] = 0,
   ["west"] = 90,
   ["south"] = 180,
   ["east"] = 270,
}

-- if you later update the `Direction` enum to add new directions
-- such as "northeast" and "southwest", the above declaration of
-- `degrees` will issue a compile-time error, because the table
-- above is no longer total!


local record Color
   red: integer
   green: integer
   blue: integer
end

local teal_color <total>: Color = {
   red = 0,
   green = 128,
   blue = 128,
}

-- if you later update the `Color` record to add a new component
-- such as `alpha`, the above declaration of `teal_color`
-- will issue a compile-time error, because the table above
-- is no longer total!


local vertical_only <total>: {Direction:MotionCallback} = {
   ["north"] = move_up,
   ["west"] = nil,
   ["south"] = move_down,
   ["east"] = nil,
}

-- This declaration is fine: the map is still total, as we are
-- explicitly mentioning which cases are left empty in it.




--[[  Global variables ]]

global n: number

global m: {string:boolean} = {}

global hi = function(): string
   return "hi"
end

global function my_function()
   print("I am a global function")
end


-- mymod.tl
local mymod = {}

global type MyPoint = record
   x: number
   y: number
end

return mymod


-- main.tl
local mymod = require("mymod")

local function do_something(p: MyPoint)
   -- ...
end


-- person.tl
local person = {}

global type Building

global record Person
   residence: Building
end

return person


-- building.tl
local building = {}

global type Person

global record Building
   owner: Person
end

return building


-- main.tl
local person = require("person")
local building = require("building")

local b: Building = {}
local p: Person = { residence = b }

b.owner = p

