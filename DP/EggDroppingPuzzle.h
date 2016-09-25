#include <bits/stdc++.h>
using namespace std;

void EggDroppingPuzzle() {
    int n, k;
    cin >> n >> k;
    int **E = new int *[n + 1];/*   */
    for (int i = 0; i <= n; ++i) {
        E[i] = new int[k + 1];
        E[i][0] = 0;
        E[i][1] = 1;
    }
    E[0][1] = 0;
    for (int i = 1; i <= k; i++) {
//        E[0][i] = 0;
        E[1][i] = i;
    }
    for (int i = 2; i <= n; i++) { // Number of Eggs
        for (int j = 2; j <= k; j++) { // Number of Floors
            E[i][j] = INT_MAX;
            int tmp;
            for (int x = 1; x <= j; x++) {
                tmp = 1 + max(E[i - 1][x - 1], E[i][j - x]);
                E[i][j] = min(tmp, E[i][j]);
                /*if (tmp < E[i][j])
                    E[i][j] = tmp;*/
            }

        }
    }

    cout << E[n][k];
}