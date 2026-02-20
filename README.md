# PerlinGen

Perlin Noise Voxel Terrain Generator.

Tested on Macos.

There are two versions of this repository, the first one is using it directly in your project via the `perlin_gen.h` file and the second one is building it and creating an `.obj` file to import into your project.

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
## Build
- `cd` into root directory.
```
cd build
cmake ..
cmake --build
```
Or
- Add the `perlin_gen.h` file located in `generator/perlin_gen.h` to your project.
- `include` it in your file using `#include <perlin_gen.h>`.
- Use it: `PerlinGen::generate()`.
## Sources
- This code uses the `stb` and `glm` libraries.
## Future Updates
- Add parameter tweaking.