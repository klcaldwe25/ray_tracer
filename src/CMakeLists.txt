set(BINARY ${CMAKE_PROJECT_NAME})

set(CMAKE_CXX_FLAGS "-std=c++0x")

file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.h *.cpp)

set(SOURCES ${SOURCES})

add_executable(${BINARY}_run ${SOURCES})

add_library(${BINARY}_lib STATIC ${SOURCES})