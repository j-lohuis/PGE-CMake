
# Pixel Game Engine CMake Script

This is a CMake script to help building with the [olcPixelGameEngine](https://github.com/OneLoneCoder/olcPixelGameEngine) including a example application.

Currently supported platforms are:
- Linux
- Windows
- Emscripten

# Building

## Linux

```
mkdir build && cd build
cmake ..
make
```

## Windows (nmake.exe + cl.exe)

```
# Setup the environment
# Located at the installation path of Visual Studio.
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Auxiliary\Build\vcvars64.bat"

mkdir build && cd build
cmake .. -G "NMake Makefiles"
nmake
```
Use `vcvars32.bat` for 32-Bit builds.

## Emscripten

### Note

For some reason running `em++` for the first time using CMake does not automatically install the requirements, so you have to run it once by yourself:

```
# Setup emscripten environment

mkdir build && cd build
em++ ../main.cpp -sALLOW_MEMORY_GROWTH=1 -sMAX_WEBGL_VERSION=2 -sMIN_WEBGL_VERSION=2 -sUSE_LIBPNG=1 -o main.html
```

You remove all generated files and build with CMake after the initial build has finished.

### Emscripten (Linux)

```
# Setup emscripten environment
source /install/path/of/emsdk/emsdk_env.sh

mkdir build && cd build
emcmake cmake ..
make
```

### Emscripten (Windows)
```
# Setup emscripten environment
"C:\install\path\of\emsdk\emsdk_env.bat"

# Setup the nmake environment
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Auxiliary\Build\vcvars64.bat"

mkdir build && cd build
emcmake cmake .. -G "NMake Makefiles"
nmake
```

### Running Emscripten

```
emrun main.html
```