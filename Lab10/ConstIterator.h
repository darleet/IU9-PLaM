//
// Created by darleet on 5/16/23.
//

#ifndef LAB10_CONSTITERATOR_H
#define LAB10_CONSTITERATOR_H

#include <set>
#include <vector>

using namespace std;

template<typename T>
class ConstIterator {
public:
    using reference = const set<T> &;
    using pointer = const set<T> *;

    explicit ConstIterator(const typename vector<set<T>>::const_iterator& it) : ptr_(it) {};
    ~ConstIterator();

    reference operator*() const;
    pointer operator->() const;
    ConstIterator& operator++();
    ConstIterator operator++(int);
    ConstIterator& operator--();
    ConstIterator operator--(int);
    bool operator==(const ConstIterator& other) const;
    bool operator!=(const ConstIterator& other) const;

private:
    typename vector<set<T>>::const_iterator ptr_;
};

#endif //LAB10_CONSTITERATOR_H
