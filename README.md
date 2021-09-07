# Demo of unit testing Arduino and Particle projects using Bazel and Google Test

This project demonstrates using Google Test to write unit tests for Particle/Arduino projects using Bazel for builds.

Issues/Notes:
* Arduino support isn't implemented yet.
* This does not support translating ".ino" files to ".cpp" so your project will need to use vanilla cpp files.
* I've only tested this on an M1 mac running macOS 11.5. YMMV on other platforms.

# Usage

## Particle

```
cd particle
bazel test --test_output=errors tests/...
```
