# YAMPL-EXAMPLE
if (NOT DEFINED WITH_PLUGIN_EXAMPLE OR WITH_PLUGIN_EXAMPLE)	    
    # Declare the plugin as a shared library
    add_library(yampl-example SHARED
	    ${CMAKE_CURRENT_LIST_DIR}/src/PluginMain.cpp
        ${YAMPL_PLUGIN_COMMON_SRCS}
    )
    
    # Include directories
    target_include_directories(yampl-example PRIVATE ${CMAKE_CURRENT_LIST_DIR}/include)

    # Output directory
    set_target_properties(yampl-example
            PROPERTIES
            LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/plugins/yampl-example"
    )

    # Install
    install(TARGETS yampl-example
            LIBRARY DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/plugins/yampl-example"
    )
endif()
