import XCTest
import SwiftTreeSitter
import TreeSitterTeal

final class TreeSitterTealTests: XCTestCase {
    func testCanLoadGrammar() throws {
        let parser = Parser()
        let language = Language(language: tree_sitter_teal())
        XCTAssertNoThrow(try parser.setLanguage(language),
                         "Error loading Teal grammar")
    }
}
