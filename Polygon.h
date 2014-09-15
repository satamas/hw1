#include <vector>
#include <iostream>
#include "Point.h"

#ifndef POLYGON
#define POLYGON

class Polygon {
public:
    Polygon();

    bool check_if_point_inside_polygon(Point point);

    friend std::istream &operator>>(std::istream &in, Polygon &polygon);

private:

    int get_x_coord_of_line_point(Point line_point_a, Point line_point_b, int y);
    std::vector<Point> _vertices;
};

#endif