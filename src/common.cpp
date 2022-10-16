#include "common.hpp"

PolygonWithHoles open(const std::string& path) {
    std::ifstream f(path);
    auto data = nlohmann::json::parse(f);

    PolygonWithHoles polygon;
    polygon.outer_boundary().container().reserve(data["outer_boundary"].size());

    for (const auto v : data["outer_boundary"]) {
        double x = v["x"];
        double y = v["y"];
        polygon.outer_boundary().push_back(Point(x, y));
    }

    for (const auto hole : data["holes"]) {
        Polygon p_hole;
        p_hole.container().reserve(hole.size());

        for (const auto v : hole) {
            double x = v["x"];
            double y = v["y"];
            p_hole.push_back(Point(x, y));
        }

        polygon.holes().emplace_back(p_hole);
    }

    return polygon;
}

void print_polygon(const Polygon& polygon) {
    for (const auto v : polygon.vertices()) {
        std::cout << v.x() << " " << v.y() << std::endl;
    }
}

void print_polygon(const PolygonWithHoles& polygon) {
    for (const auto v : polygon.outer_boundary().vertices()) {
        std::cout << v.x() << " " << v.y() << std::endl;
    }

    std::cout
        << std::endl
        << "number of holes: "
        << polygon.number_of_holes()
        << std::endl;

    for (const auto& hole : polygon.holes()) {
        std::cout << std::endl;
        for (const auto v : hole.vertices()) {
            std::cout << v.x() << " " << v.y() << std::endl;
        }
    }
}
