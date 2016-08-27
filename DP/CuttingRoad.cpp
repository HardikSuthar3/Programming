//
// Created by Hardik on 29/06/16.
//

#include <iostream>

using namespace std;

void CuttingRoad() {
    int len;
    cin >> len;
    int *price = new int[len];
    for (int i = 0; i < len; i++) {
        cin >> price[i];
    }

    int *sol = new int[len + 1];
    sol[0] = 0;
    int maxVal = INT_MIN;

    for (int i = 1; i <= len; ++i) {
        maxVal = INT_MIN;
        for (int j = 0; j < i; ++j) {
            maxVal = max(maxVal, sol[i - j - 1] + price[j]);
        }
        sol[i] = maxVal;
    }
    cout << sol[len];
}
