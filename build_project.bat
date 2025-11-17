@echo off
echo ========================================
echo Building AI Forge Studio
echo ========================================
echo.

cd /d C:\Users\hamad\aiforgestudio.net

echo Cleaning build folder...
if exist build rmdir /s /q build
echo.

echo Configuring with CMake (Visual Studio 2022)...
cmake -B build -G "Visual Studio 17 2022" -A x64 ^
    -DCMAKE_PREFIX_PATH="C:/Qt/6.8.3/msvc2022_64"

if %ERRORLEVEL% NEQ 0 (
    echo.
    echo ERROR: CMake configuration failed!
    pause
    exit /b 1
)

echo.
echo Building project...
cmake --build build --config Release --parallel 8

if %ERRORLEVEL% NEQ 0 (
    echo.
    echo ERROR: Build failed!
    pause
    exit /b 1
)

echo.
echo ========================================
echo Build completed successfully!
echo ========================================
echo.
echo Executable location: build\Release\AIForgeStudio.exe
echo.
pause
