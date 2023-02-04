# Specify minimum supported cmake version
cmake_minimum_required(VERSION 3.5)

# set the project (solution) name
project(Laterem)

# Add SFML to build
set( BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE )
add_subdirectory("ext/SFML-2.5.1")


file(GLOB INC_FILES "include/*.h")
file(GLOB SRC_FILES "src/*.cpp")

# SFML
include_directories("ext/SFML-2.5.1/include")
include_directories("ext/box2d-lite/include")
include_directories("include")

add_executable(laterem ${SRC_FILES} ${INC_FILES})
target_link_libraries(laterem sfml-system sfml-graphics sfml-audio)