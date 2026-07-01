# Snake Game with Raylib

A simple Snake game implemented in C++ using the Raylib graphics library.

## Prerequisites

- CMake 3.20 or newer
- A C++20-capable compiler toolchain
- On Windows, use a Developer Command Prompt for Visual Studio or a terminal with MinGW tools available

## Build and Run

From the project root:

1. Create and enter the build directory:
   ```powershell
   mkdir build
   cd build
   ```
2. Generate the build files. Use one of these commands depending on your toolchain:
   - For Visual Studio 2022:
     ```powershell
     cmake -G "Visual Studio 17 2022" ..
     ```
   - For Visual Studio 2019:
     ```powershell
     cmake -G "Visual Studio 16 2019" ..
     ```
   - For MinGW Makefiles:
     ```powershell
     cmake -G "MinGW Makefiles" ..
     ```

3. Build the project:
   ```powershell
   cmake --build .
   ```

4. Run the game executable from the build directory:
   ```powershell
   .\GameOfSnake.exe
   ```

## Notes

- This project uses CMake `FetchContent` to download and build Raylib automatically.
- If CMake selects `NMake Makefiles` and `nmake` is not available, choose one of the explicit generators above.
- The executable name is `GameOfSnake.exe`.
