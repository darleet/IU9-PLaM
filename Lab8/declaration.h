//
// Created by darleet on 4/17/23.
//

#ifndef LAB8_DECLARATION_H
#define LAB8_DECLARATION_H

#include <cmath>
#include <vector>

using namespace std;

template<typename T, typename N>
class Path {
private:
    N fin_time;
    vector<T> coordinates;
public:
    Path(T *, N);

    N get_fin_time() const;
    vector<T> get_coordinates();

    string print_coordinates();

    // Path length calculation
    unsigned calc_length();
    // Adding new path
    Path<T, N> add_path(Path);
    // Forming an odd path
    Path<T, N> form_odd();

    ~Path();
};

template<typename T, typename N>
Path<T, N>::Path(T *coordinates_, N fin_time_) {
    for (int i = 0; i < fin_time_; i++) {
        this->coordinates.push_back(coordinates_[i]);
    }
    this->fin_time = fin_time_;
}

template<typename T, typename N>
unsigned Path<T, N>::calc_length() {
    T length = 0;
    for (N i = 1; i < this->fin_time; i++) {
        T el1 = this->coordinates[i];
        T el2 = this->coordinates[i-1];
        T delta = (T)(this->coordinates[i] - this->coordinates[i-1]);
        length += (T)sqrt(pow(delta, 2) + 1);
    }
    return length;
}

template<typename T, typename N>
Path<T, N> Path<T, N>::add_path(Path second_path) {
    N total_time = this->fin_time + second_path.get_fin_time();
    T total_coordinates[total_time];

    N counter = 0;

    while (counter < this->fin_time) {
        total_coordinates[counter] = this->coordinates[counter];
        counter++;
    }

    for (int i = 0; i < second_path.get_fin_time(); i++) {
        total_coordinates[counter] = second_path.get_coordinates()[i];
        counter++;
    }

    return Path<T, N> {total_coordinates, total_time};
}

template<typename T, typename N>
N Path<T, N>::get_fin_time() const {
    return this->fin_time;
}

template<typename T, typename N>
vector<T> Path<T, N>::get_coordinates() {
    return this->coordinates;
}

template<typename T, typename N>
Path<T, N> Path<T, N>::form_odd() {
    if (this->fin_time % 2 == 0) {
        cout << "Unable to form an odd path: it's even." << endl;
    } else {
        N total_time = this->fin_time / 2 + 1;
        T total_coordinates[total_time];

        N counter = 0;

        for (N i = 0; i < this->fin_time; i += 2) {
            total_coordinates[counter] = this->coordinates[i];
            counter++;
        }

        return Path<T, N> {total_coordinates, total_time};
    }
}

template<typename T, typename N>
string Path<T, N>::print_coordinates() {
    string new_return;
    new_return.append("(");
    for (T el : this->coordinates) {
        new_return.append(" " + to_string(el));
    }
    new_return.append(" )");
    return new_return;
}

template<typename T, typename N>
Path<T, N>::~Path() = default;

#endif //LAB8_DECLARATION_H
