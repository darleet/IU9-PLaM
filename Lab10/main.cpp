#include <iostream>
#include <set>
#include "IntersectingSetSequence.h"
using namespace std;


int main() {
    set<int> set1 = {1, 2, 3, 4};
    set<int> set2 = {2, 3, 4, 5};
    set<int> set3 = {5, 6, 7, 8};

    IntersectingSetSequence<int> sequence;
    sequence.add_set(set1);
    sequence.add_set(set2);
    sequence.add_set(set3);

    for (const auto& el : sequence) {
        for (auto x : el) {
            cout << x << ' ';
        }
        cout << endl;
    }

    cout << endl;
    set<int> set4 = {8, 9, 10, 11};
    sequence.add_set(set4);

    for (const auto& el : sequence) {
        for (auto x : el) {
            cout << x << ' ';
        }
        cout << endl;
    }

    return 0;
}


