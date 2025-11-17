qt_add_executable(AIForgeStudio 
    main.cpp
    resources.qrc
)
target_link_libraries(AIForgeStudio PRIVATE 
    Qt6::Core 
    Qt6::Gui 
    Qt6::Qml 
    Qt6::Quick
    Qt6::QuickControls2
)
