# Antrock
Simple game engine written in C++ & OpenGL.

## Cloning
This repo make use of github submodules which means that it is recommended to clone the repo with `--recursive` option enabled.

## LSP
I personally use clangd.
In order to have it setup as I do and make it work you need to create `.clangd` file with following content:
```yaml
CompileFlags:
  CompilationDatabase: "build"
```

## Building & requirements
I use **CMake** as the basis for the build procedure.
That means `cmake` and `g++/gcc` (or any other compiler) is all you need.

From root directory you can:
```bash
cd build
cmake ..
make
```

## Running
Compiled programmes should be contained inside of the `apps` directory.

From root directory you can:
```bash
#GNU/Linux or any other POSIX complient shell i guess
cd build/apps
./app

#Windows
cd build/apps
./app.exe
```

## Libraries used
tba

## Sources
tba
