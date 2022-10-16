cmake_minimum_required(VERSION 3.10)

project(cgal_learning)

add_executable(
    cgal_learning

    src/common.cpp
    src/main.cpp
    src/naive.cpp
)

find_package(CGAL REQUIRED COMPONENTS Core)
target_link_libraries(cgal_learning PRIVATE CGAL::CGAL CGAL::CGAL_Core)
