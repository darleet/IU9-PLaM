#include <iostream>
#include "declaration.h"

using namespace std;

int main() {
    int my_coords[] = {3, 5, 8, 2, 4};
    unsigned my_time = 5;
    Path<int, unsigned> my_path = {my_coords, my_time};
    cout << "Длина первой траектории: " << my_path.calc_length() << endl;

    int my_coords2[] = {7, 2, 3, 4, 1, 0};
    unsigned my_time2 = 6;
    Path<int, unsigned> my_path2 = {my_coords2, my_time2};
    cout << "Длина второй траектории: " << my_path2.calc_length() << endl;

    Path<int, unsigned> new_path = my_path.add_path(my_path2);
    cout << "\nКоординаты новой траектории: " << new_path.print_coordinates() << endl;
    cout << "Длина новой траектории: " << new_path.calc_length() << endl;

    Path<int, unsigned> odd_path = new_path.form_odd();
    cout << "\nКоординаты нечетной траектории: " << odd_path.print_coordinates() << endl;
    cout << "Длина \"нечетной\" траектории: " << odd_path.calc_length() << endl;

    return 0;
}
