//
// Created by Hardik on 25/06/16.
//


#include <iostream>
#include <algorithm>

using namespace std;

int _01KnapSack() {
    int n, W; // Number of items and weights
    cin >> n >> W;
    int *value = new int[n];
    int *weight = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> value[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> weight[i];
    }

    int **t;
    t = new int *[n + 1];
    for (int j = 0; j <= n; ++j) {
        t[j] = new int[W + 1];
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            if (i == 0 || j == 0) {
                t[i][j] = 0;
            }
            else {
                t[i][j] = max(t[i - 1][j], t[i - 1][j - weight[i]] + value[i]);
            }
        }
    }
    cout << t[n][W];
    return 0;
}
