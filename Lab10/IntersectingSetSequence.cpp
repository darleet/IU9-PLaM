//
// Created by darleet on 5/16/23.
//

#include <algorithm>
#include "IntersectingSetSequence.h"

template<typename T>
void IntersectingSetSequence<T>::add_set(set<T> added_set) {
    sets.push_back(added_set);
    if (sets.size() > 1) {
        set<T> intersection;
        insert_iterator<set<T>> intersect_iterate(intersection, intersection.begin());
        set<T> previous_set = sets[sets.size() - 2];
        set<T> next_set = sets[sets.size() - 1];
        set_intersection(previous_set.begin(), previous_set.end(),
                         next_set.begin(), next_set.end(),
                         intersect_iterate);
        intersections.push_back(intersection);
    }
}

template<typename T>
ConstIterator<T> IntersectingSetSequence<T>::begin() const {
    return ConstIterator<T>(intersections.begin());
}

template<typename T>
ConstIterator<T> IntersectingSetSequence<T>::end() const {
    return ConstIterator<T>(intersections.end());
}

template<typename T>
IntersectingSetSequence<T>::IntersectingSetSequence() = default;

template<typename T>
IntersectingSetSequence<T>::~IntersectingSetSequence() = default;

template class IntersectingSetSequence<int>;