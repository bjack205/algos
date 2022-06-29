cmake_minimum_required(VERSION 3.20)
list(APPEND CMAKE_MESSAGE_CONTEXT algos)
project(algos VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include useful modules
list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
include(CMakePrintHelpers)
include(Functions)

cmake_policy(SET CMP0077 NEW)

#############################################
# Dependencies
#############################################

# fmtlib
include(FetchContent)
FetchContent_Declare(fmt
  GIT_REPOSITORY https://github.com/fmtlib/fmt
  GIT_TAG b6f4ceaed0a0a24ccf575fab6c56dd50ccf6f1a9 # version 8.1.1
)
FetchContent_MakeAvailable(fmt)

# Eigen
FetchContent_Declare(eigen
  GIT_REPOSITORY https://gitlab.com/libeigen/eigen 
  GIT_TAG 3147391d946bb4b6c68edd901f2add6ac1f31f8c # version 3.4.0
)
set(BUILD_TESTING OFF CACHE BOOL "Build tests for Eigen" FORCE)
FetchContent_MakeAvailable(eigen)

# GoogleTest
FetchContent_Declare(googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
enable_testing()
include(GoogleTest)
include(CTest)

#############################################
# Build
#############################################

add_subdirectory(src)