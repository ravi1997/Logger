add_library("${PROJECT_NAME}" STATIC "")
add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS "${PROJECT_NAME}")

target_include_directories("${PROJECT_NAME}" PUBLIC
	"$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
	"$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>" #SymbolTable_export.h
	"$<INSTALL_INTERFACE:include>" #${CMAKE_INSTALL_PREFIX}/include
)

if(NOT BUILD_SHARED_LIBS)
	set(STATIC_POSTFIX "-s")
	set_target_properties("${PROJECT_NAME}" PROPERTIES 
	COMPILE_FLAGS -DSYMBOLTABLE_STATIC_DEFINE)
endif()

#Rename target SYMBOLTABLE
set_target_properties("${PROJECT_NAME}" PROPERTIES
	DEBUG_POSTFIX "${STATIC_POSTFIX}-d" 
	RELEASE_POSTFIX "${STATIC_POSTFIX}"
	MINSIZEREL_POSTFIX "${STATIC_POSTFIX}-mr"
	RELWITHDEBINFO_POSTFIX "${STATIC_POSTFIX}-rd"
)

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include")
link_directories(${CMAKE_INSTALL_LIBDIR})

add_library(Property STATIC IMPORTED)
set_target_properties(Property PROPERTIES IMPORTED_LOCATION ${CMAKE_INSTALL_LIBDIR}/libProperty.a)

set ( PROJECT_LINK_LIBS ${PROJECT_LINK_LIBS} libLogger.a )

target_link_libraries(${PROJECT_NAME} LINK_PUBLIC ${PROJECT_LINK_LIBS})



include(GNUInstallDirs)
install(TARGETS ${PROJECT_NAME}
		ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        PUBLIC_HEADER
          DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME}
)
add_subdirectory("include")
add_subdirectory("source")