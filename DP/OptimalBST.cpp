//
// Created by Hardik on 10/07/16.
//


#include <iostream>

using namespace std;

int OptBST() {
    int n;
    cin >> n;
    int *freq = new int[n];
    int **sol = new int *[n];
    for (int i = 0; i < n; ++i) {
        sol[i] = new int[n];
        cin >> freq[i];
    }

    for (int i = 0; i < n; i++) {
        sol[i][i] = freq[i];
    }

    for (int len = 2; len <= n; len++) {
        for (int i = 0; i < n - len + 1; i++) {
            int j = i + len - 1;
            int minVal = INT_MAX;
            for (int k = i; k <= j; k++) {
                int tmp = (k > i) ? sol[i][k - 1] : 0 + (k < j) ? sol[k + 1][j] : 0;
                if (tmp < minVal)
                    minVal = tmp;
            }

            sol[i][j] = minVal;
            for (int k = i; k <= j; k++) {
                sol[i][j] += freq[k];
            }
        }
    }

    cout << sol[0][n - 1];
}
