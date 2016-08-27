//
// Created by Hardik on 06/07/16.
//

#include "iostream"

using namespace std;

void LargestSum() {
    int n;
    cin >> n;
    int *data = new int[n];
    for (int i = 0; i < n; ++i) {
        cin >> data[i];
    }

    // Alocating Memory
    int **largestSum = new int *[n];
    for (int j = 0; j < n; ++j) {
        largestSum[j] = new int[n];
    }
    int maxSofar = INT_MIN;

    /*if (data[0] > 0) {
        largestSum[0] = data[0];
    } else {
        largestSum[0] = 0;
    }*/

    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            if (j == i) {
                largestSum[i][j] = data[i];
            }
            else {
                largestSum[i][j] = largestSum[i][j - 1] + data[j];
            }
            maxSofar = max(largestSum[i][j], maxSofar);
        }
    }

    cout << maxSofar;
}


void LargestSum_short() {
    int n;
    cin >> n;
    int *data = new int[n];
    for (int i = 0; i < n; ++i) {
        cin >> data[i];
    }

    int cur, allMax;
    cur = allMax = data[0];
    for (int i = 1; i < n; i++) {
        cur = max(data[i], cur + data[i]);
        cout << cur << " ";
        allMax = max(cur, allMax);
    }
    cout << "\n\n\n\n";
    cout << allMax;
}

