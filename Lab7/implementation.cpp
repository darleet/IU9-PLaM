//
// Created by darleet on 4/17/23.
//

#include <iostream>
#include <cstring>
#include "declaration.h"

using namespace std;

// Constructor of Interval_Set
Interval_Set::Interval_Set() {
    this->size = 1;
    this->counter = 0;
    this->set = (Interval *)malloc(sizeof(Interval));
}

Interval &Interval_Set::operator[](int index) {
    if (index >= this->size) {
        cout << "Array index out of range";
        exit(-1);
    }
    return set[index];
}

void Interval_Set::add_interval(Interval &new_interval) {
    // Double the allocated memory if size <= counter
    if (this->size <= this->counter) {
        Interval *new_set = (Interval *)malloc(sizeof(Interval) * this->size * 2);
        memcpy(new_set, this->set, size * sizeof(Interval));
        free(this->set);
        this->set = new_set;
        this->size *= 2;
    }
    this->set[this->counter] = new_interval;
    this->counter++;
}

Interval_Set::~Interval_Set() {
    free(this->set);
}

bool Interval_Set::has_x(int x) {
    for (int i = 0; i < this->counter; i++) {
        Interval temp_interval = this->set[i];
        if (temp_interval.has_x(x)) {
            return true;
        }
    }
    return false;
}

unsigned Interval_Set::get_counter() const {
    return this->counter;
}

Interval_Set Interval_Set::get_bigger_delta(int delta) {
    Interval_Set new_set;
    for (int i = 0; i < this->counter; i++) {
        Interval temp_interval = this->set[i];
        if (temp_interval.get_delta() > delta) {
            new_set.add_interval(temp_interval);
        }
    }
    return new_set;
}

// Constructor of Interval
Interval::Interval(int a_, int b_) {
    this->a = a_;
    this->b = b_;
}

int Interval::get_delta() const {
    return (this->b - this->a);
}

bool Interval::has_x(int x) const {
    return (x > this->a && x < this->b);
}

int Interval::get_a() const {
    return this->a;
}

int Interval::get_b() const {
    return this->b;
}

std::ostream &operator<<(ostream &stream, const Interval& interval_inst) {
    stream << "(" << interval_inst.get_a() << ", ";
    stream << interval_inst.get_b() << ")";
    return stream;
}

Interval::~Interval() = default;


