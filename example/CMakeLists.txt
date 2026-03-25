file(GLOB CORE_SOURCES "${PROJECT_SOURCE_DIR}/src/*.cpp")

add_executable(example_demo Main.cpp ${CORE_SOURCES})