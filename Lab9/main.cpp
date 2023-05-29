#include <iostream>
#include "Polyline.h"
#include "Point.h"

using namespace std;

int main() {
    Polyline<Point> my_polyline;

    Point p1 {1., 4., 2.};
    Point p2 {7., -4., -8.};
    Point p3 {4., -1., 0.};

    my_polyline>>p1;
    my_polyline<<p2;
    my_polyline>>p3;

    cout << "Первая ломаная" << endl;
    cout << "Кол-во точек: " << my_polyline.count() << endl;
    cout << "Длина: " << my_polyline.length() << endl;
    cout << endl;

    Polyline<Point> another_polyline;

    another_polyline<<p1;
    another_polyline<<p2;
    another_polyline<<p3;

    cout << "Вторая ломаная" << endl;
    cout << "Кол-во точек: " << another_polyline.count() << endl;
    cout << "Длина: " << another_polyline.length() << endl;
    cout << endl;

    if (my_polyline != another_polyline) {
        cout << "Ломаные не равны!" << endl;
    }

}
