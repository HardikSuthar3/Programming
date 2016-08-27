//
// Created by Hardik on 06/07/16.
//

#include <iostream>
#include <string>

using namespace std;

void LPS() {
    string str;
    cin >> str;
    const int n = str.length();

    int **L = new int *[n];
    for (int i = 0; i < n; ++i) {
        L[i] = new int[n];
        L[i][i] = 1;
    }

    for (int len = 2; len <= n; ++len) {
        for (int i = 0; i < n - len + 1; ++i) {
            int j = i + len - 1;
            if (str[i] == str[j] && len == 2) {
                L[i][j] = 2;
            }
            else if (str[i] == str[j]) {
                L[i][j] = L[i + 1][j - 1] + 2;
            }
            else {
                L[i][j] = max(L[i + 1][j], L[i][j - 1]);
            }
        }
    }

    cout << "  ";
    for (int i = 0; i < n; ++i) {
        cout << str[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < n; ++i) {
        cout << str[i] << " ";
        for (int j = 0; j < n; ++j) {
            cout << L[i][j] << " ";
        }
        cout << endl;
    }
}