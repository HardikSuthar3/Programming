//
// Created by Hardik on 16/06/16.
//


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class activity {
 public:
    int start;
    int finish;
};

class comparator {
 public:
    bool operator()(activity *a, activity *b) {
        return a->finish < b->finish;
    }
};

bool myFun(activity *a, activity *b) {
    return a->finish < b->finish;
}

/*
6
1 2 3 4 0 6 5 7 8 9 5 9
 */

int ActivitySelection() {

    vector<activity *> v;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        activity *a = new activity;
        cin >> a->start >> a->finish;
        v.push_back(a);
    }

    sort(v.begin(), v.end(), myFun);

    int count = 1;
    activity *current, *next;
    current = v[0];
    cout << current->start << ' ';
    for (int i = 1; i < n; i++) {
        next = v[i];
        if (current->finish < next->start) {
            current = next;
            cout << current->start << ' ';
            count++;
        }
    }

    cout << endl << count << endl;
}