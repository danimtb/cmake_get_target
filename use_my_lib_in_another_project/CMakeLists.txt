cmake_minimum_required(VERSION 3.22)
project(project VERSION 1.0.0
  DESCRIPTION project
  LANGUAGES CXX
  ) 
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
add_executable(project src/main.cpp)
find_package(myLib CONFIG REQUIRED)
target_link_libraries(project myLib) 
target_compile_definitions(project PRIVATE INCLUDE_PATH_TO_GAME_OPTION="${PROJECT_SOURCE_DIR}/src/gameOption.h") 
# replace with the path to gameOption. If game option is in an installed library we could write here for example: "GameOptionLibrary/gameOption.h"