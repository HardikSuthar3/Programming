//
// Created by Hardik on 03/07/16.
//


#include <iostream>
#include <array>
using namespace std;

void MinJump() {
    int n;
    cin >> n;
    int *jumps = new int[n];
    int *a = new int[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    jumps[0] = 0;

    for (int i = 1; i < n; i++) {
        jumps[i] = INT_MAX;
        for (int j = 0; j < i; ++j) {
            if (jumps[j] + 1 < jumps[i] && j + a[j] >= i) {
                jumps[i] = jumps[j] + 1;
            }
        }
    }

    cout << jumps[n - 1];
}


