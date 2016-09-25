#include <bits/stdc++.h>
using namespace std;

int Kadane_Algo(int *a, int *start, int *finish, int n) {
    *finish = -1;
    int curMax = a[0];
    int maxSoFar = a[0];
    for (int i = 1; i < n; ++i) {
        if (curMax + a[i] > a[i]) {
            curMax = curMax + a[i];
        }
        else {
            curMax = a[i];
        }
    }
}