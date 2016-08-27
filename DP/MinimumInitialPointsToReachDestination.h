#include<iostream>

using namespace std;

/*
-2 -3   3
-5 -10  1
10  30 -5
 */

void MinimumInitialPointsToREachDEstination() {
    int m, n;
    cin >> m >> n;

    m = m + 2;
    n = n + 2;
    int **C = new int *[m];
    int **a = new int *[m];
    for (int i = 0; i < m; ++i) {
        C[i] = new int[n];
        a[i] = new int[n];
    }
    for (int i = 1; i < m - 1; ++i) {
        for (int j = 1; j < n - 1; ++j) {
            cin >> a[i][j];
        }
    }

    // Initialise Outer boundries

    fill(C[0], C[0] + m, INT_MIN);
    fill(C[n - 1], C[n - 1] + m, INT_MIN);

    for (int i = 1; i < n - 1; ++i) {
        C[i][0] = INT_MIN;
        C[i][m - 1] = INT_MIN;
    }

    C[n - 2][m - 1] = 0;
    C[n - 1][m - 2] = 0;


    for (int i = m - 2; i > 0; --i) {
        for (int j = n - 2; j > 0; --j) {
            int tmp = a[i][j] + max(C[i + 1][j], C[i][j + 1]);
            C[i][j] = (tmp >= 0) ? 0 : tmp;
        }
    }

    cout << -1 * C[1][1] + 1;
}


