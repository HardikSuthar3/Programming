#include <bits/stdc++.h>
using namespace std;

void EditDistance() {
    string first, second;
    getline(cin, first);
    getline(cin, second);
    int m = first.length();
    int n = second.length();

    int **ED = new int *[m + 1];
    for (int i = 0; i <= m; i++) {
        ED[i] = new int[n + 1];
        for (int j = 0; j <= n; ++j) {
            if (i == 0)
                ED[i][j] = j;
            else if (j == 0)
                ED[i][j] = i;
            else if (first.at(i - 1) == second.at(j - 1))
                ED[i][j] = ED[i - 1][j - 1];
            else
                ED[i][j] = 1 + min(ED[i][j - 1], min(ED[i - 1][j], ED[i - 1][j - 1]));
        }
    }

    cout << ED[m][n];
}