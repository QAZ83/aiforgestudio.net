add_subdirectory(monitor)

add_library(aiforge_gpu kernels.cu)

target_link_libraries(aiforge_gpu 
    PUBLIC
    gpu_monitor
)

# TODO: Uncomment when CUDA is properly configured
# target_link_libraries(aiforge_gpu CUDA::cudart)
