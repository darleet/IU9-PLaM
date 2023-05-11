//
// Created by darleet on 4/17/23.
//

#ifndef LAB7_DECLARATION_H
#define LAB7_DECLARATION_H

class Interval {
private:
    int a, b;
public:
    Interval(int, int);

    // Method overloads cout
    friend std::ostream& operator<< (std::ostream& stream, const Interval& interval_inst);
    // Method returns delta between a and b
    int get_delta() const;
    // Method checks if x is in the Interval
    bool has_x(int) const;

    int get_a() const;
    int get_b() const;

    ~Interval();
};

class Interval_Set {
private:
    unsigned size;
    unsigned counter;
    Interval *set;
public:
    Interval_Set();

    // Overload of operator
    Interval &operator[] (int);

    unsigned get_counter() const;

    // Adding an interval
    void add_interval(Interval &new_interval);
    // Method checks if x in the set
    bool has_x(int);

    Interval_Set get_bigger_delta(int);

    ~Interval_Set();
};

#endif //LAB7_DECLARATION_H
