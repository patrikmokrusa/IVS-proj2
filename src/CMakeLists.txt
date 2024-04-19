# CMakeLists

cmake_minimum_required(VERSION 3.16)
project(HugoCalc LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES mathlib.cpp calc.cpp)

set(HEADER_FILES mathlib.h)

# Output built files to ./build/
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/./build)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/./build)

add_executable(${PROJECT_NAME} ${HEADER_FILES} ${SOURCE_FILES})

if(CMAKE_COMPILER_IS_GNUCXX)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0 -fprofile-arcs")
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -O0 -fprofile-arcs")
  set(POSITION_INDEPENDENT_CODE ON)
endif()

if(MSVC)
  target_compile_options(${PROJECT_NAME} PRIVATE /W3)
else()
  target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -pedantic)
endif()

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt
    ON
    CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Test targets
include(GoogleTest)

include_directories("test")

add_executable(test_mathlib test/test_mathlib.cpp)
target_link_libraries(test_mathlib gtest_main gmock_main)
gtest_discover_tests(test_mathlib)

find_package(Doxygen 1.8.0)
if(DOXYGEN_FOUND)
  set(doxyfile ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile)
  add_custom_target(
    doc
    COMMAND ${DOXYGEN_EXECUTABLE} ${doxyfile}
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
    COMMENT "Generating API documentation with Doxygen"
    VERBATIM)
endif()

add_custom_target(clean-cmake-files COMMAND ${CMAKE_COMMAND} -P clean-all.cmake)

# clean-all.cmake
set(cmake_generated
    ${CMAKE_BINARY_DIR}/CMakeCache.txt ${CMAKE_BINARY_DIR}/cmake_install.cmake
    ${CMAKE_BINARY_DIR}/Makefile ${CMAKE_BINARY_DIR}/CMakeFiles)

foreach(file ${cmake_generated})

  if(EXISTS ${file})
    file(REMOVE_RECURSE ${file})
  endif()

endforeach(file)

# Clean-all
add_custom_target(
  clean-all
  COMMAND ${CMAKE_BUILD_TOOL} clean
  COMMAND ${CMAKE_COMMAND} -P clean-all.cmake)

# Support for Visual Studio
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT
                                                            ${PROJECT_NAME})
