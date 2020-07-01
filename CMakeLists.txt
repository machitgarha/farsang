cmake_minimum_required(VERSION 3.0)

# Set include and library path for OS X
if (APPLE)
    link_directories(/usr/local/lib)
    set(USER_INCLUDE /usr/local/include)
endif()

project(
    Farsang
    DESCRIPTION "GSL (i.e. GNU Scientific Library) with C++ taste"
)

# Standards
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED true)

# Source files
add_library(
    ${PROJECT_NAME} SHARED
    src/error-handler.cpp
    src/exception.cpp
    src/random-generator.cpp
    src/random-distribution/gamma.cpp
    src/random-distribution/gaussian.cpp
    src/random-distribution/poisson.cpp
    src/random-distribution/random-distribution.cpp
)

# GSL
target_link_libraries(
    ${PROJECT_NAME}
    gsl
    gslcblas
)

# Includes
target_include_directories(
    ${PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${USER_INCLUDE}
)
