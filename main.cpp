#include "Polygon.h"

int main() {
    Polygon polygon;

    std::cin >> polygon;
    int no_of_points;
    std::cin >> no_of_points;
    for (int i = 0; i < no_of_points; ++i) {
        Point p;
        std::cin >> p;
        if (polygon.check_if_point_inside_polygon(p)) {
            std::cout << "yes" << std::endl;
        } else {
            std::cout << "no" << std::endl;
        }

    }

    return 0;
}


