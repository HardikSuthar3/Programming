//
// Created by Hardik on 24/06/16.
//


#include<iostream>

using namespace std;


void MatrixChain() {
    int n;
    long q;
    cin >> n;

    long **mat = new long *[n];
    int *p = new int[n];

    for (int i = 0; i < n; i++) {
        mat[i] = new long[n];
        cin >> p[i];
        mat[i][i] = 0;
    }


    for (int L = 2; L < n; L++) {
        for (int i = 1; i <= n - L + 1; i++) {
            int j = i + L - 1;
            mat[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < mat[i][j])
                    mat[i][j] = q;
            }
        }
    }

    cout << mat[1][n - 1];

}

