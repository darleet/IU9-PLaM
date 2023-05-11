#include <iostream>
#include "declaration.h"

using namespace std;

int main() {
    Interval_Set my_set;
    Interval interval1 = {3, 7};
    Interval interval2 = {-6, 2};
    Interval interval3 = {6, 8};

    my_set.add_interval(interval1);
    my_set.add_interval(interval2);
    my_set.add_interval(interval3);

    cout << "Кол-во интервалов: " << my_set.get_counter() << endl;

    cout << my_set[0] << endl;
    cout << my_set[1] << endl;
    cout << my_set[2] << endl;

    if (my_set.has_x(2)) {
        cout << "2 присутствует в множестве интервалов." << endl;
    } else {
        cout << "2 не присутствует в множестве." << endl;
    }

    if (my_set.has_x(4)) {
        cout << "4 присутствует в множестве интервалов." << endl;
    } else {
        cout << "4 не присутствует в множестве." << endl;
    }

    cout << endl;
    Interval_Set new_subset = my_set.get_bigger_delta(3);
    cout << "Подмножество, где дельта превышает 3:" << endl;

    for (int i = 0; i < new_subset.get_counter(); i++) {
        cout << new_subset[i] << endl;
    }

    return 0;
}
