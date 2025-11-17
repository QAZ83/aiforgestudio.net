# AI Forge Studio

GPU-accelerated development studio with Qt 6.8, CUDA 12, Vulkan 1.3

## Requirements
- Windows 10/11 64-bit
- NVIDIA GPU (Compute 7.5+)
- CUDA Toolkit 12.0+
- Qt 6.8+
- Vulkan SDK 1.3+
- Visual Studio 2022

## Quick Build
```batch
mkdir build && cd build
cmake .. -G "Visual Studio 17 2022" -A x64
cmake --build . --config Release
```

## Features
- GPU acceleration (CUDA/TensorRT)
- Vulkan rendering
- Qt 6.8 UI
- Python bindings
- Cloud AI via Workers

## License
MIT
