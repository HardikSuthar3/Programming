//
// Created by Hardik on 04/07/16.
//

/*
 * Ugly number is the number whose only prime factors are 2,3 or 5
 * */
#include <iostream>
#include <algorithm>

using namespace std;

void UglyNumber() {
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int b1, b2, b3;
    int maxVal = max(std::begin(a), std::end(a));
    cout << maxVal;
}