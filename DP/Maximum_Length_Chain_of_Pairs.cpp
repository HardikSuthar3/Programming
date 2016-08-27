//
// Created by Hardik on 02/07/16.
//
#include <iostream>
#include <vector>
using namespace std;


void MLCP() {
    int n;
    cin >> n;

    vector<pair<int, int>>
            element;
    for (int i = 0; i < n; ++i) {
        pair<int, int> p;
        cin >> p.first;
        cin >> p.second;
        element.push_back(p);
    }

    sort(element.begin(), element.end(), [](pair<int, int> &a, pair<int, int> &b) -> bool {
        return a.first < b.first;
    });


    int *LIS = new int[n];

    for (int i = 0; i < n; ++i) {
        LIS[i] = 1;
    }

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (element[j].second <= element[i].first && LIS[i] < LIS[j] + 1) {
                LIS[i] = LIS[j] + 1;
            }
        }
    }

    int maxVal = LIS[0];
    for (int i = 1; i < n; i++) {
        if (maxVal < LIS[i]) {
            maxVal = LIS[i];
        }
    }

    cout << maxVal;
}
