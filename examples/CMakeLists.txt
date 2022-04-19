include_directories(${CMAKE_INSTALL_INCLUDEDIR})
set ( PROJECT_LINK_LIBS libEnumeration.a )
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib)


add_executable("Example" "Main.cpp")
target_link_libraries("Example" LINK_PUBLIC  ${PROJECT_NAME} ${PROJECT_LINK_LIBS})
