cmake_minimum_required(VERSION 3.22)

project(myLib VERSION 0.1 LANGUAGES CXX)

set(TARGET_NAME_LIB myLib)
add_library(${TARGET_NAME_LIB} INTERFACE)


target_include_directories(${TARGET_NAME_LIB} INTERFACE 
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include>
)

target_sources(${TARGET_NAME_LIB}
   INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/myLib/lobby.h>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src/lobby.cpp>
        $<INSTALL_INTERFACE:include/myLib/lobby.h>
        $<INSTALL_INTERFACE:src/lobby.cpp>
      )

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    "${PROJECT_BINARY_DIR}/myLibConfigVersion.cmake"
    VERSION 0.1
    COMPATIBILITY AnyNewerVersion
)

install(TARGETS ${TARGET_NAME_LIB}
    EXPORT myLibTargets
    LIBRARY DESTINATION lib COMPONENT Runtime
    ARCHIVE DESTINATION lib COMPONENT Development
    RUNTIME DESTINATION bin COMPONENT Runtime
    PUBLIC_HEADER DESTINATION include COMPONENT Development
    BUNDLE DESTINATION bin COMPONENT Runtime
)

include(CMakePackageConfigHelpers)
configure_package_config_file(
    "${PROJECT_SOURCE_DIR}/cmake/myLibConfig.cmake.in"
    "${PROJECT_BINARY_DIR}/myLibConfig.cmake"
    INSTALL_DESTINATION lib/cmake/myLib
)

install(EXPORT myLibTargets DESTINATION lib/cmake/myLib)
install(FILES "${PROJECT_BINARY_DIR}/myLibConfigVersion.cmake"
              "${PROJECT_BINARY_DIR}/myLibConfig.cmake"
        DESTINATION lib/cmake/myLib)
install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/ DESTINATION include/myLib)
install(DIRECTORY ${PROJECT_SOURCE_DIR}/src/ DESTINATION src)
