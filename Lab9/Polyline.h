//
// Created by darleet on 5/18/23.
//

#ifndef LAB9_POLYLINE_H
#define LAB9_POLYLINE_H

#include <vector>
#include "Point.h"

using namespace std;

template<typename P>
class Polyline {
public:
    Polyline();
    Polyline<P>& operator<<(const P&);
    Polyline<P>& operator>>(const P&);
    P& operator[](int);
    [[nodiscard]] int count() const;
    double length();
    bool operator==(Polyline);
    bool operator!=(Polyline);
    bool operator<(Polyline);
    bool operator<=(Polyline);
    bool operator>(Polyline);
    bool operator>=(Polyline);
    ~Polyline();
private:
    vector <P> line;
    int counter;
};

#endif //LAB9_POLYLINE_H
