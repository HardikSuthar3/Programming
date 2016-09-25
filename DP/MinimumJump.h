#include <bits/stdc++.h>

using namespace std;

void MinimumJump() {
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int *J = new int[n];
    J[0] = 0;

    for (int i = 1; i < n; i++) {
        J[i] = INT_MAX;
        for (int j = 0; j < i; j++) {

            if (j + a[j] >= i && 1 + J[j] < J[i]) {
                J[i] = 1 + J[j];
            }
        }
    }

    cout << J[n - 1];
}