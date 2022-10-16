cmake_minimum_required(VERSION 3.10)

project(cg-shop-challenge)

add_executable(
    cg-shop-challenge

    src/common.cpp
    src/main.cpp
    src/naive.cpp
)

set_property(TARGET cg-shop-challenge PROPERTY CXX_STANDARD 20)

find_package(CGAL REQUIRED COMPONENTS Core)
target_link_libraries(cg-shop-challenge PRIVATE CGAL::CGAL CGAL::CGAL_Core)
