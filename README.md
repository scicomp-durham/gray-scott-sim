## Build Instructions
### With Docker
1. run `docker build -t YOUR_IMAGE_NAME:TAG .`

### Local environment (need CMake)
1. create and navigate to build directory (e.g. /build)
2. run `cmake ..`
3. run `make` or `cmake --build .` to build
4. run `make clean` to clean up build file