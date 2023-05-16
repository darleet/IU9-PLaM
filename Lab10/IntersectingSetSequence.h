//
// Created by darleet on 5/16/23.
//

#ifndef LAB10_INTERSECTINGSETSEQUENCE_H
#define LAB10_INTERSECTINGSETSEQUENCE_H

#include "ConstIterator.h"

template<typename T>
class IntersectingSetSequence {
public:
    IntersectingSetSequence();
    ~IntersectingSetSequence();

    const set<T>& operator[](int i) { return sets[i]; };
    void add_set(set<T> added_set);
    [[nodiscard]] ConstIterator<T> begin() const;
    [[nodiscard]] ConstIterator<T> end() const;

    vector <set<T>> sets;
    vector <set<T>> intersections;
};

#endif //LAB10_INTERSECTINGSETSEQUENCE_H
