@echo off
mkdir build 2>nul
cd build
cmake .. -G "Visual Studio 17 2022" -A x64 -DQt6_DIR="C:\Qt\6.8.0\msvc2022_64"
cmake --build . --config Release -j8
pause