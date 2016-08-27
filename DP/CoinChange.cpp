//
// Created by Hardik on 23/06/16.
//

#include <iostream>

using namespace std;


void CoinChange() {
    int n, m;

    cin >> n >> m;
    int *s = new int[m];

    for (int i = 0; i < m; i++) {
        cin >> s[i];
    }

    long long **t, x, y;
    t = new long long *[n + 1];
    t[0] = new long long[m];
    for (int i = 0; i < m; i++) {
        t[0][i] = 1;
    }


    for (int i = 1; i <= n; ++i) {
        t[i] = new long long[m];
        for (int j = 0; j < m; ++j) {
            x = (i - s[j] >= 0) ? t[i - s[j]][j] : 0; // If Coin is Included
            y = (j >= 1) ? t[i][j - 1] : 0; // If Coin is not included
            t[i][j] = x + y;
        }
    }
    delete[] s;
    cout << t[n][m - 1] << endl;
}


void CoinChange2() {
    int n, m;

    cin >> n >> m;
    int *s = new int[m];

    for (int i = 0; i < m; i++) {
        cin >> s[i];
    }

    long long **t, x, y;
    t = new long long *[n + 1];
    t[0] = new long long[m];
    for (int i = 0; i < m; i++) {
        t[0][i] = 1;
    }


    for (int i = 1; i <= n; ++i) {
        t[i] = new long long[m];
        for (int j = 0; j < m; ++j) {
            x = (i - s[j] >= 0) ? t[i - s[j]][j] : 0; // If Coin is Included
            y = (j >= 1) ? t[i][j - 1] : 0; // If Coin is not included
            t[i][j] = x + y;
        }
    }
    delete[] s;
    cout << t[n][m - 1] << endl;
}