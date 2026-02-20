# PerlinGen

Perlin Noise Voxel Terrain Generator

Tested on Macos.

## Dependencies
- CMake
- clang or gcc compiler
### Macos
```
brew install cmake
```
```
brew install gcc
```
- stb_perlin
Add the `stb_perlin` file to the include directory of you project.
## Build
- `cd` into root directory.
```
cd build
cmake ..
cmake --build
```
Or
- Add the `perlin_gen.h` file located in `generator/perlin_gen.h` to you project.
- `include` it in your file using `#include <perlin_gen.h>`.
- Use it using `PerlinGen::generate()`.
## Sources
- This code uses the `stb` and `glm` libraries.