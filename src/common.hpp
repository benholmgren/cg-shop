#pragma once

#include <CGAL/Exact_predicates_exact_constructions_kernel.h>
#include <CGAL/Boolean_set_operations_2.h>
#include "json.hpp"
#include <fstream>

using Kernel = CGAL::Exact_predicates_exact_constructions_kernel;
using Point = Kernel::Point_2;
using Line = CGAL::Line_2<Kernel>;
using Polygon = CGAL::Polygon_2<Kernel>;
using PolygonWithHoles = CGAL::Polygon_with_holes_2<Kernel>;

PolygonWithHoles open(const std::string& path);

void print_polygon(const Polygon& polygon);

void print_polygon(const PolygonWithHoles& polygon);
