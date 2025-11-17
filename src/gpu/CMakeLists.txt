add_library(aiforge_gpu kernels.cu)
target_link_libraries(aiforge_gpu CUDA::cudart)