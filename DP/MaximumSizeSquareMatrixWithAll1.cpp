//
// Created by Hardik on 04/07/16.
//

#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;


int MinMatWithAllOne() {
    int n, m;
    cin >> n >> m;
    int **a = new int *[n];
    for (int i = 0; i < n; ++i) {
        a[i] = new int[n];
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
    int **b = new int *[n];
    int maxElement = INT_MIN;
    for (int i = 0; i < n; ++i) {
        b[i] = new int[n];
        for (int j = 0; j < m; ++j) {
            if (i == 0 || j == 0) {
                b[i][j] = a[i][j];
            }
            else {
                if (a[i][j] == 1) {
                    b[i][j] = 1 + min(b[i - 1][j - 1], min(b[i - 1][j], b[i][j - 1]));
                }
                else {
                    b[i][j] = 0;
                }
            }

            if (maxElement < b[i][j])
                maxElement = b[i][j];
        }
    }
    cout << maxElement;
}


