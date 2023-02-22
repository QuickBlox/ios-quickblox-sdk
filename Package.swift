// swift-tools-version: 5.7
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "QuickbloxSDK",
    platforms: [
        .iOS(.v13)
    ],
    products: [
        .library(
            name: "QuickbloxSDK",
            targets: ["QuickbloxSDK", "Quickblox"]),
    ],
    dependencies: [
    ],
    targets: [
        .target(
            name: "QuickbloxSDK",
            dependencies: []),
        .binaryTarget(
            name: "Quickblox",
            path: "Framework/Quickblox.xcframework"
        ),
    ]
)
