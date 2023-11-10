cmake_minimum_required(VERSION 3.0.0)
project(base VERSION 0.1.0 LANGUAGES C CXX)

set(EXEC_NAME meow)

file(GLOB_RECURSE SRC_FILES "src/*.cpp")

add_executable(meow ${SRC_FILES})

# set(EXTERNAL_LIB_HEADERS lib/cpr/include)

# target_include_directories(meow PRIVATE ${EXTERNAL_LIB_HEADERS})

add_subdirectory(lib/cpr)

target_link_libraries(meow cpr)

if(WIN32)
  add_custom_command(
    TARGET meow POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    $<TARGET_FILE:CURL::libcurl>
    $<TARGET_FILE:cpr>
    $<TARGET_FILE_DIR:meow>
  )
endif()

