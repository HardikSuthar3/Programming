//
// Created by Hardik on 03/07/16.
//

#include <iostream>

using namespace std;


void fibo(int n) {
    if (n <= 0) {
        cout << 0;
    }
    else {
        int i = 2;
        int cur, prev;
        prev = 0;
        cur = 1;
        int next;
        cout << prev << " " << cur << " ";
        while (i <= n) {
            next = cur + prev;
            prev = cur;
            cur = next;
            cout << cur << " ";
            i++;
        }
    }
}
