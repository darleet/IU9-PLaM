//
// Created by darleet on 5/18/23.
//

#ifndef LAB9_POINT_H
#define LAB9_POINT_H

class Point {
public:
    Point(double, double, double);
    [[nodiscard]] double getX() const;
    [[nodiscard]] double getY() const;
    [[nodiscard]] double getZ() const;
    [[nodiscard]] double dist(const Point&) const;
    ~Point();
private:
    double x, y, z;
};

#endif //LAB9_POINT_H
