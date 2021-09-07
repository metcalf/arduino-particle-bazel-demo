load("//tools:particle.bzl", "particle_library")

particle_library(
    name = "Adafruit_GFX_RK",
    textual_hdrs = ["//lib:Adafruit_GFX_RK/src/glcdfont.c"],
)

particle_library(
    name = "Adafruit_SSD1306_RK",
    includes = ["lib/Adafruit_GFX_RK/src"],
    deps = ["//lib:Adafruit_GFX_RK"],
)
