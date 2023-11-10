cmake_minimum_required(VERSION 3.0.0)
project(base VERSION 0.1.0 LANGUAGES C CXX)

set(EXEC_NAME meow)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SRC_FILES "src/*.cpp")

add_subdirectory(dependencies/cpr)
set(ENABLE_CXX, ON)

add_executable(meow ${SRC_FILES})

target_include_directories(meow PRIVATE dependencies/cpr/include)

target_link_libraries(meow PRIVATE cpr)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
