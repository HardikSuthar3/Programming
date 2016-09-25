#include <bits/stdc++.h>
using namespace std;

int LIS() {
// Input Read
    int n;
    cin >> n;
    vector<int> a;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.push_back(x);
    }

    // Input End

    // Sol Begins
    int cur_len = 1;
    int maxlen = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] > a[i - 1])
            cur_len++;
        else
            cur_len = 1;
        maxlen = max(maxlen, cur_len);
    }
    cout << maxlen;
    // Sol Ends
}