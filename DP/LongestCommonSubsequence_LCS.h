#include <bits/stdc++.h>
using namespace std;

void printLCS(int **LCS, string first, string second) {
    int m = first.size();
    int n = second.size();
    char lcs[LCS[m][n] + 1];

    int index = LCS[m][n];
    lcs[index] = '\0';
    while (n > 0 && m > 0) {
        if (first[m - 1] == second[n - 1]) {
            lcs[--index] = first[m - 1];
            m--;
            n--;
        }
        else if (LCS[m - 1][n] > LCS[m][n - 1]) {
            m--;
        }
        else {
            n--;
        }
    }

    cout << lcs;
}


void LCS() {
    string first, second;
    getline(cin, first);
    getline(cin, second);

    int m = first.size();
    int n = second.size();

    int **LCS = new int *[m + 1];

    for (int i = 0; i <= m; i++) {
        LCS[i] = new int[n];
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                LCS[i][j] = 0;
            }
            else if (first[i] == second[j]) {
                LCS[i][j] = 1 + LCS[i - 1][j - 1];
            }
            else {
                LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
            }
        }
    }
    cout << LCS[m][n] << endl;
    printLCS(LCS, first, second);
}
