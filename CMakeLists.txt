cmake_minimum_required(VERSION 3.24)
project(AIForgeStudio VERSION 1.0.0 LANGUAGES CXX CUDA)

# Standards
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CUDA_STANDARD 17)
set(CMAKE_CUDA_ARCHITECTURES "75;86;89")

# Qt Configuration
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Find packages
find_package(Qt6 6.8 REQUIRED COMPONENTS Core Gui Widgets OpenGL)
find_package(Vulkan 1.3 REQUIRED)
find_package(CUDAToolkit 12.0 REQUIRED)

# Windows specific
if(WIN32)
    add_definitions(-DWIN32_LEAN_AND_MEAN -DNOMINMAX -DUNICODE)
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>DLL")
endif()

# Add subdirectories
add_subdirectory(src)
add_subdirectory(apps)
