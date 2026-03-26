file(GLOB CORE_SOURCES "${PROJECT_SOURCE_DIR}/src/*.cpp")

file(GLOB CLI_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

set(INCLUDES_CLI ${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${INCLUDES_CLI})

add_executable(cli_app Main.cpp ${CLI_SOURCES} ${CORE_SOURCES})