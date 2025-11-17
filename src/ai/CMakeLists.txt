add_library(aiforge_ai 
    OllamaClient.cpp
    OllamaClient.h
)

target_link_libraries(aiforge_ai PUBLIC
    Qt6::Core
    Qt6::Network
)

target_include_directories(aiforge_ai PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
