# CMakeLists
cmake_minimum_required(VERSION 3.5)

project(
  HugoCalc
  VERSION 1.0
  LANGUAGES C CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(GUI_SOURCE_FILES mainwindow.cpp mainwindow.h mainwindow.ui)

set(MATHLIB_SOURCE_FILES mathlib.cpp)
set(MATHLIB_HEADER_FILES mathlib.h)

set(PROF_SOURCE_FILES profiling.cpp)

# set(PROJECT_SOURCES main.cpp ${MATHLIB_HEADER_FILES} ${MATHLIB_SOURCE_FILES}
# ${GUI_SOURCE_FILES})

set(PROJECT_SOURCES main.cpp ${GUI_SOURCE_FILES})

# Fetch the package
find_package(Qt6 6.4.2 QUIET)

if(NOT Qt6_FOUND)
  # Initial message
  message(STATUS "Qt 6.4.2 not found. Downloading and configuring Qt...")

  # Download and extract archive of Qt 6.4.2
  set(QT_VERSION "6.4.2")
  set(QT_ARCHIVE_URL
      "https://download.qt.io/official_releases/qt/6.4/${QT_VERSION}/submodules/qtbase-everywhere-src-${QT_VERSION}.tar.xz"
  )
  set(QT_ARCHIVE_FILE
      "${CMAKE_CURRENT_BINARY_DIR}/qtbase-everywhere-src-${QT_VERSION}.tar.xz")
  set(QT_SOURCE_DIR
      "${CMAKE_CURRENT_BINARY_DIR}/qtbase-everywhere-src-${QT_VERSION}")
  message(STATUS "Downloading the package from the official repository...")
  file(
    DOWNLOAD ${QT_ARCHIVE_URL} ${QT_ARCHIVE_FILE}
    SHOW_PROGRESS
    EXPECTED_HASH
      SHA256=a88bc6cedbb34878a49a622baa79cace78cfbad4f95fdbd3656ddb21c705525d)
  message(STATUS "Unpacking the release...")
  execute_process(
    COMMAND ${CMAKE_COMMAND} -E tar xvf ${QT_ARCHIVE_FILE}
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    OUTPUT_QUIET)

  # Configure Qt (skip building of useless modules)
  set(QT_BUILD_DIR "${CMAKE_CURRENT_BINARY_DIR}/qt-build")
  file(MAKE_DIRECTORY ${QT_BUILD_DIR})
  message(STATUS "Configuring...")
  execute_process(COMMAND ${QT_SOURCE_DIR}/configure -prefix ${QT_BUILD_DIR}
                  WORKING_DIRECTORY ${QT_BUILD_DIR})

  # Check if system supports parallelization
  if(DEFINED ENV{NUMBER_OF_PROCESSORS})
    set(JOBS_OPTION "-j$ENV{NUMBER_OF_PROCESSORS}")
  elseif(DEFINED ENV{PROCESSOR_COUNT})
    set(JOBS_OPTION "-j$ENV{PROCESSOR_COUNT}")
  else()
    set(JOBS_OPTION "")
  endif()

  # Use -j option to compile if possible (qt is very big)
  if(JOBS_OPTION)
    message(STATUS "Compiling with parallelization...")
    execute_process(COMMAND ninja ${JOBS_OPTION}
                    WORKING_DIRECTORY ${QT_BUILD_DIR})
  else()
    message(STATUS "Compiling without parallelization...")
    execute_process(COMMAND ninja WORKING_DIRECTORY ${QT_BUILD_DIR})
  endif()

  # Set necessary environment variables to use Qt
  set(ENV{QTDIR} ${QT_BUILD_DIR})
  set(ENV{PATH} ${QT_BUILD_DIR}/bin:$ENV{PATH})

else()
  message(STATUS "Qt 6.4.2 found in the system.")
endif()

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
  qt_add_executable(${PROJECT_NAME} MANUAL_FINALIZATION ${PROJECT_SOURCES})
  # Define target properties for Android with Qt 6 as: set_property(TARGET
  # Hugocalc APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
  # ${CMAKE_CURRENT_SOURCE_DIR}/android) For more information, see
  # https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
  if(ANDROID)
    add_library(${PROJECT_NAME} SHARED ${PROJECT_SOURCES})
    # Define properties for Android with Qt 5 after find_package() calls as:
    # set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
  else()
    add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})
  endif()
endif()

target_link_libraries(${PROJECT_NAME} PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1. If
# you are developing for iOS or macOS you should consider setting an explicit,
# fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.${PROJECT_NAME})
endif()

set_target_properties(
  ${PROJECT_NAME}
  PROPERTIES ${BUNDLE_ID_OPTION} MACOSX_BUNDLE_BUNDLE_VERSION
             ${PROJECT_VERSION} MACOSX_BUNDLE_SHORT_VERSION_STRING
             ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR} MACOSX_BUNDLE
             TRUE WIN32_EXECUTABLE
             TRUE)

include(GNUInstallDirs)
install(
  TARGETS ${PROJECT_NAME}
  BUNDLE DESTINATION LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}/./target
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}/./target)

if(QT_VERSION_MAJOR EQUAL 6)
  qt_finalize_executable(${PROJECT_NAME})
endif()

# Output built files to ./target/
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/./target)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/./target)

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

# Download GTest
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

find_package(Doxygen 1.9.0)
if(DOXYGEN_FOUND)
  set(doxyfile ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile)
  add_custom_target(
    doc
    COMMAND ${DOXYGEN_EXECUTABLE} ${doxyfile}
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
    COMMENT "Generating API documentation with Doxygen"
    VERBATIM)
endif()

include_directories("profiling")
add_executable(prof profiling/profiling.cpp)

set(targets ${CMAKE_CURRENT_SOURCE_DIR}/build/target)

add_custom_target(
  profile
  COMMAND ${targets} ./prof
  WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
  VERBATIM)
add_custom_target(
  test
  COMMAND ${targets} ./test_mathlib/
  WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
  VERBATIM)
add_custom_target(
  run
  COMMAND ${targets} ../HugoCalc/
  WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
  VERBATIM)

# Ensures that we do an out of source build
macro(MACRO_ENSURE_OUT_OF_SOURCE_BUILD MSG)
  string(COMPARE EQUAL "${CMAKE_SOURCE_DIR}" "${CMAKE_BINARY_DIR}" insource)
  get_filename_component(PARENTDIR ${CMAKE_SOURCE_DIR} PATH)
  string(COMPARE EQUAL "${CMAKE_SOURCE_DIR}" "${PARENTDIR}" insourcesubdir)
  if(insource OR insourcesubdir)
    message(FATAL_ERROR "${MSG}")
  endif(insource OR insourcesubdir)
endmacro(MACRO_ENSURE_OUT_OF_SOURCE_BUILD)

macro_ensure_out_of_source_build(
  "${CMAKE_PROJECT_NAME} requires an out of source build.")

# Support for Visual Studio
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT
                                                            ${PROJECT_NAME})
