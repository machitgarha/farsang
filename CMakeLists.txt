cmake_minimum_required(VERSION 3.0)

project(Gsler)

# Standards
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED true)

# Executables
file(GLOB_RECURSE SRC_FILES src/*.cpp)
add_executable(
    ${PROJECT_NAME}
    main.cpp
    ${SRC_FILES}
)

# Shared
target_link_libraries(
    ${PROJECT_NAME}
    gsl
    gslcblas
)

# Includes
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
