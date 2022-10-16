#include "common.hpp"
#include "naive.hpp"

int main() {
    const auto input_polygon = open("../examples/cheese102.instance.json");

    const auto cover = naive::run(input_polygon);

    for (const auto& polygon : cover) {
        print_polygon(polygon);
    }

    return 0;
}
