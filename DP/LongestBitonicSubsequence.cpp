//
// Created by Hardik on 29/06/16.
//

#include <iostream>
#include <string>

using namespace std;

void LBS() {
    int n;
    cin >> n;

    int *a = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int *lis, *lds;
    lis = new int[n];
    lds = new int[n];

    for (int i = 0; i < n; i++) {
        lis[i] = lds[i] = 1;
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i] && lis[i] < lis[j] + 1) {
                lis[i] = lis[j] + 1;
            }
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        for (int j = i; j < n; ++j) {
            if (a[j] < a[i] && lds[j] + 1 > lds[i]) {
                lds[i] = lds[j] + 1;
            }
        }
    }

    int maxValue = INT_MIN;

    for (int i = 0; i < n; i++) {
        if (lis[i] + lds[i] > maxValue) {
            maxValue = lis[i] + lds[i] - 1;
        }
    }

    cout << maxValue;
}