#include "Polygon.h"

bool Polygon::check_if_point_inside_polygon(Point point) {
    int number_of_intersections = 0;
    for (int i = 0; i < _vertices.size(); i++) {
        Point current = _vertices[i];
        Point next = _vertices[(i + 1) % _vertices.size()];

        if (current.y != point.y) {
            if ((current.y - point.y) * (next.y - point.y) < 0) {
                if (get_x_coord_of_line_point(current, next, point.y) >= point.x) {
                    ++number_of_intersections;
                }
            }
        } else {
            if (current.x > point.x) {
                Point prev = _vertices[(i - 1 + _vertices.size()) % _vertices.size()];
                if (next.y != point.y) {
                    if ((point.y - next.y) * (point.y - prev.y) < 0) {
                        ++number_of_intersections;
                    }
                } else if (next.x <= point.x) {
                    return true;
                } else {
                    Point next_after_next = _vertices[(i + 2) % _vertices.size()];
                    if ((next_after_next.y - next.y) * (point.y - prev.y) > 0) {
                        ++number_of_intersections;
                    } else if ((next_after_next.y - next.y) * (point.y - prev.y) == 0) {
                        std::cout << "Three points on one line";
                    }
                }
            } else if (current.x < point.x) {
                if (next.x >= point.x && next.y == point.y) {
                    return true;
                }
            } else {
                return true;
            }
        }
    }

    return number_of_intersections % 2 != 0;
}

std::istream &operator>>(std::istream &in, Polygon &polygon) {
    unsigned long no_of_vertices;
    in >> no_of_vertices;
    polygon._vertices.clear();
    polygon._vertices.reserve(no_of_vertices);

    //first two vertices
    Point point;
    in >> point;
    polygon._vertices.push_back(point);
    in >> point;
    polygon._vertices.push_back(point);


    for (int i = 2; i < no_of_vertices; ++i) {
        in >> point;
        //if three point are on one line we need to delete middle point
        if (point.y == polygon._vertices[polygon._vertices.size() - 1].y &&
                point.y == polygon._vertices[polygon._vertices.size() - 2].y) {
            polygon._vertices.pop_back();
        }
        polygon._vertices.push_back(point);
    }

    if (polygon._vertices[polygon._vertices.size() - 1].y == polygon._vertices[0].y &&
            polygon._vertices[polygon._vertices.size() - 1].y == polygon._vertices[1].y) {
        polygon._vertices.erase(polygon._vertices.begin(), polygon._vertices.begin() + 1);
    }

    if (polygon._vertices[polygon._vertices.size() - 1].y == polygon._vertices[0].y &&
            polygon._vertices[polygon._vertices.size() - 2].y == polygon._vertices[0].y) {
        polygon._vertices.pop_back();
    }

    return in;
}


Polygon::Polygon() :
        _vertices() {

}

int Polygon::get_x_coord_of_line_point(Point line_point_a, Point line_point_b, int y) {
    if (line_point_a.x == line_point_b.x) {
        return line_point_a.x;
    } else {
        double k = (double)(line_point_b.y - line_point_a.y) / (double)(line_point_b.x - line_point_a.x);
        return (int) (line_point_a.x + (y - line_point_a.y) / k);
    }
}
