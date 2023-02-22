// swift-tools-version: 5.7
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "QuickBloxSDK",
    platforms: [
        .iOS(.v13)
    ],
    products: [
        .library(
            name: "QuickBloxSDK",
            targets: ["QuickBloxSDK"]),
    ],
    dependencies: [
    ],
    targets: [
        .binaryTarget(
            name: "QuickBloxSDK",
            path: "Framework/Quickblox.xcframework"
        ),
    ]
)
