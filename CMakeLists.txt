cmake_minimum_required(VERSION 3.8)

project(kalkulacka)

file(GLOB_RECURSE HEADERS "*.h" "*.hpp")

set(SOURCES main.cpp)
add_subdirectory(src)
add_subdirectory(test)

set(CMAKE_CXX_STANDARD 11)

add_executable(${PROJECT_NAME}
                ${SOURCES} ${HEADERS})
                
target_link_libraries(${PROJECT_NAME} hdf5)