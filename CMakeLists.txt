cmake_minimum_required(VERSION 3.24)
project(AIForgeStudio VERSION 1.0.0 LANGUAGES CXX)

# Standards
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Qt Configuration
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Find packages
find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets Qml Quick QuickControls2 OpenGL)
find_package(Vulkan 1.3 QUIET)
if(Vulkan_FOUND)
    message(STATUS "Vulkan found: ${Vulkan_VERSION}")
endif()

# Skip CUDA for now - requires proper Visual Studio integration
# find_package(CUDAToolkit 12.0 QUIET)
# if(CUDAToolkit_FOUND)
#     enable_language(CUDA)
#     set(CMAKE_CUDA_STANDARD 17)
#     set(CMAKE_CUDA_ARCHITECTURES "75;86;89")
#     message(STATUS "CUDA Toolkit found: ${CUDAToolkit_VERSION}")
# else()
#     message(WARNING "CUDA Toolkit not found - CUDA features will be disabled")
# endif()

# Windows specific
if(WIN32)
    add_definitions(-DWIN32_LEAN_AND_MEAN -DNOMINMAX -DUNICODE)
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>DLL")
endif()

# Add subdirectories
add_subdirectory(src)
add_subdirectory(apps)
