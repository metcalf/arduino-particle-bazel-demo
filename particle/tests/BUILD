load("@rules_cc//cc:defs.bzl", "cc_test")

cc_test(
    name = "tests",
    size = "small",
    srcs = glob(["**/*.cpp"]),
    deps = [
        "//src:particle-bazel-demo",
        "@com_google_googletest//:gtest_main",
    ],
)
