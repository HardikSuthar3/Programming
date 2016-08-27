//
// Created by Hardik on 16/06/16.
//
#include <iostream>

using namespace std;

/*
3 3
1 2 3
4 8 2
1 5 3
*/
void MinCostPath() {
    int n, m;
    cin >> n >> m;
    int **cst = new int *[n];
    for (int i = 0; i < n; i++) {
        cst[i] = new int[m];
        for (int j = 0; j < m; ++j) {
            cin >> cst[i][j];
        }
    }

    int **minCst = new int *[n];

    for (int i = 0; i < n; ++i) {
        minCst[i] = new int[m];
    }
    // Initializing the cost of first row and column
    minCst[0][0] = cst[0][0];
    for (int i = 1; i < n; i++) {
        minCst[i][0] = minCst[i - 1][0] + cst[i][0];

    }

    for (int i = 1; i < m; i++) {
        minCst[0][i] = minCst[0][i - 1] + cst[0][i];
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            minCst[i][j] = min(minCst[i - 1][j - 1], min(minCst[i - 1][j], minCst[i][j - 1])) + cst[i][j];
        }
    }

    cout << endl << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << minCst[i][j] << " ";
        }
        cout << endl;
    }
}
