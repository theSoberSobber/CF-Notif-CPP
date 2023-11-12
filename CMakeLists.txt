cmake_minimum_required(VERSION 3.0.0)
project(base VERSION 0.1.0 LANGUAGES C CXX)

set(EXEC_NAME meow)

<<<<<<< HEAD
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
=======
add_executable(meow src/main.cpp src/popup.cpp)

add_subdirectory(lib/cpr)
add_subdirectory(lib/json)

target_link_libraries(meow cpr winmm.lib nlohmann_json::nlohmann_json)

if(WIN32)
  add_custom_command(
    TARGET meow POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    $<TARGET_FILE:CURL::libcurl>
    $<TARGET_FILE:cpr>
    $<TARGET_FILE_DIR:meow>
  )
endif()
>>>>>>> 328ffe09e7ebca16fc0c055141dfae3d5af216ee
