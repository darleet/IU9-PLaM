//
// Created by darleet on 5/18/23.
//

#include "Polyline.h"

template<typename P>
Polyline<P>::Polyline() = default;

template<typename P>
Polyline<P> &Polyline<P>::operator<<(const P &p) {
    this->line.insert(this->line.begin(), p);
    this->counter++;
    return *this;
}

template<typename P>
Polyline<P> &Polyline<P>::operator>>(const P &p) {
    this->line.push_back(p);
    this->counter++;
    return *this;
}

template<typename P>
P &Polyline<P>::operator[](int pos) {
    return this->line[pos];
}

template<typename P>
int Polyline<P>::count() const {
    return this->counter;
}

template<typename P>
double Polyline<P>::length() {
    double line_length = 0;
    for (int i = 0; i < this->counter - 1; i++) {
        Point p1 = this->line[i];
        Point p2 = this->line[i+1];
        line_length += p1.dist(p2);
    }
    return line_length;
}

template<typename P>
bool Polyline<P>::operator==(Polyline<P> other) {
    return this->length() == other.length();
}

template<typename P>
bool Polyline<P>::operator!=(Polyline<P> other) {
    return this->length() != other.length();
}

template<typename P>
bool Polyline<P>::operator<(Polyline<P> other) {
    return this->length() < other.length();
}

template<typename P>
bool Polyline<P>::operator<=(Polyline<P> other) {
    return this->length() <= other.length();
}

template<typename P>
bool Polyline<P>::operator>(Polyline<P> other) {
    return this->length() > other.length();
}

template<typename P>
bool Polyline<P>::operator>=(Polyline<P> other) {
    return this->length() >= other.length();
}

template<typename P>
Polyline<P>::~Polyline() = default;

template class Polyline<Point>;
