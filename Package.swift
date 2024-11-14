// swift-tools-version:5.3
import PackageDescription

let package = Package(
    name: "TreeSitterTeal",
    products: [
        .library(name: "TreeSitterTeal", targets: ["TreeSitterTeal"]),
    ],
    dependencies: [
        .package(url: "https://github.com/ChimeHQ/SwiftTreeSitter", from: "0.8.0"),
    ],
    targets: [
        .target(
            name: "TreeSitterTeal",
            dependencies: [],
            path: ".",
            sources: [
                "src/parser.c",
                "src/scanner.c",
            ],
            resources: [
                .copy("queries")
            ],
            publicHeadersPath: "bindings/swift",
            cSettings: [.headerSearchPath("src")]
        ),
        .testTarget(
            name: "TreeSitterTealTests",
            dependencies: [
                "SwiftTreeSitter",
                "TreeSitterTeal",
            ],
            path: "bindings/swift/TreeSitterTealTests"
        )
    ],
    cLanguageStandard: .c11
)
