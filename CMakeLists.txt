cmake_minimum_required(VERSION 3.0.0)
project(base VERSION 0.1.0 LANGUAGES C CXX)

set(EXEC_NAME meow)

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
