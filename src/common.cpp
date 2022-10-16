#include "common.hpp"
#include "json.hpp"
#include <fstream>

using json = nlohmann::json;

PolygonWithHoles open(const std::string& path) {
    std::ifstream f(path);
    const auto data = json::parse(f);

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

void write_polygons_to_file(const std::string& path, std::span<const Polygon> polygons) {
    std::ofstream f(path);
    json data;

    for (const auto& p : polygons) {
        json p_data;

        for (const auto v : p) {
            p_data.push_back({{"x", to_double(v.x())}, {"y", to_double(v.y())}});
        }

        data.push_back(p_data);
    }

    f << data.dump();
}
