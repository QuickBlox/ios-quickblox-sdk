// swift-tools-version: 5.7
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "Quickblox",
    platforms: [
        .iOS(.v13)
    ],
    products: [
        .library(
            name: "Quickblox",
            targets: ["Quickblox"]),
    ],
    dependencies: [
    ],
    targets: [
        .binaryTarget(
            name: "Quickblox",
            path: "Quickblox.xcframework"
        ),
    ]
)
