load("@rules_cc//cc:defs.bzl", "cc_library")

_platform_deps = ["@io_particle_device_os//:user"]

# TODO: Compute includes from deps/lib
def particle_library(name, deps = [], includes = [], textual_hdrs = []):
    cc_library(
        name = name,
        srcs = native.glob(["{}/src/*.{}".format(name, ext) for ext in ["c", "cc", "cpp"]]),
        hdrs = native.glob(["{}/src/*.h".format(name)]),
        visibility = ["//visibility:public"],
        deps = deps + _platform_deps,
        strip_include_prefix = "{}/src".format(name),
        includes = includes,
        textual_hdrs = textual_hdrs,
    )

def particle_project(name, libs):
    lib_deps = []
    lib_opts = []
    for lib in libs:
        lib_deps.append("//lib:{}".format(lib))
        lib_opts.append("-Ilib/{}/src".format(lib))

    cc_library(
        name = name,
        srcs = native.glob(["**/*.cpp"]),
        hdrs = native.glob(["**/*.h"]) + ["{}.cpp".format(name)],
        visibility = ["//visibility:public"],
        deps = _platform_deps + lib_deps,
        copts = lib_opts,
    )
