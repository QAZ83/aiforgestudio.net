set(MONITOR_SOURCES
    GPUMonitor.cpp
)

set(MONITOR_HEADERS
    GPUMonitor.h
)

add_library(gpu_monitor STATIC
    ${MONITOR_SOURCES}
    ${MONITOR_HEADERS}
)

target_include_directories(gpu_monitor PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(gpu_monitor PUBLIC
    Qt6::Core
)

# TODO: Add NVML linking when CUDA SDK is properly configured
# if(CUDAToolkit_FOUND)
#     target_link_libraries(gpu_monitor PUBLIC
#         CUDA::nvml
#     )
# endif()
