#include <bits/stdc++.h>

using namespace std;

void MaximumRectangleSumin2DMatrix() {
    int r, c;
    cin >> r >> c;
    int **a = new int *[r];
    for (int i = 0; i < r; i++) {
        a[i] = new int[c];
        for (int j = 0; j < c; ++j) {
            cin >> a[i][j];
        }
    }

    int maxSum = INT_MIN;
    int finalLeft, finalRight, finalTop, finalBottom;
    int sum;
    int *t = new int[r], start, finish;

    for (int left = 0; left < c; ++left) {
        for (int i = 0; i < r; ++i) {
            t[i] = 0;
        }
        for (int right = left; right < c; ++right) {

            for (int i = 0; i < r; ++i) {
                t[i] += a[i][right];
            }
            sum = kadane(t, &start, &finish, r);
            // update maxSum and other output values
            if (sum > maxSum) {
                maxSum = sum;
                finalLeft = left;
                finalRight = right;
                finalTop = start;
                finalBottom = finish;
            }
        }
    }


    cout << "(" << finalTop << "," << finalLeft << ") ->" << "(" << finalBottom << "," << finalRight
         << ") ->" << endl;
    cout << maxSum;
}