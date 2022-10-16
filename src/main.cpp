#include "common.hpp"
#include "naive.hpp"

int main() {
    const auto input_polygon = open("examples/cheese102.instance.json");

    const auto cover = naive::run(input_polygon);

    write_polygons_to_file("build/output.txt", cover);

    return 0;
}
