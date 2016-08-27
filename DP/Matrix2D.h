#include <iostream>


using namespace std;


int kadane(int *a, int n, int *first, int *second) {
    int curMax, localIndex, maxSofar;
    curMax = maxSofar = a[0];
    localIndex = 0;

    *first = *second = 0;
    for (int i = 1; i < n; ++i) {
        if (curMax + a[i] < a[i]) {
            curMax = a[i];
            localIndex = i;
        }
        else {
            curMax = curMax + a[i];
        }
        if (maxSofar < curMax) {
            maxSofar = curMax;
            *first = localIndex;
            *second = i;
        }
    }

    return maxSofar;
}


int FindMax() {
    // Read the Data
    int row, col;
    cin >> row >> col;
    int **a = new int *[row];
    for (int i = 0; i < row; i++) {
        a[i] = new int[col];
        for (int j = 0; j < col; j++) {
            cin >> a[i][j];
        }
    }

    int finalBottom, finalLeft;
    int finalTop, finalRight;
    int maxSum = INT_MIN;

    for (int left = 0; left < col; ++left) {
        int *tmp = new int[row];
        for (int i = 0; i < row; ++i) {
            tmp[i] = 0;
        }
        for (int right = left; right < col; ++right) {
            for (int i = 0; i < row; i++) {
                tmp[i] += a[i][right];
            }

            int localTop, localBottom;
            int sum = kadane(tmp, row, &localTop, &localBottom);
            if (sum > maxSum) {
                maxSum = sum;
                finalTop = localTop;
                finalBottom = localBottom;
                finalLeft = left;
                finalRight = right;
            }
        }
    }

    cout << "(" << finalTop << "," << finalLeft << ") ->" << "(" << finalBottom << "," << finalRight
         << ") ->" << endl;
    cout << maxSum;
}