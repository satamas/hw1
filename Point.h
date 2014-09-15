#ifndef POINT
#define POINT

struct Point {
    int x;
    int y;

    friend std::istream &operator>>(std::istream &in, Point &point) {
        char tmp;
        in >> tmp;
        in >> point.x;
        in >> tmp;
        in >> point.y;
        in >> tmp;
        return in;
    }

    bool operator==(Point other) {
        return ((x == other.x) && (y = other.y));
    }
};

#endif