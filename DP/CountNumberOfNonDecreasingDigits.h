#include <iostream>
#include <cmath>

using namespace std;

#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define FOR(i, a, b) for(int i=(a);i<=(b);i++)
#define FORD(i, a, b) for(int i=(a);i>=(b);i--)
inline bool EQ(double a, double b) { return fabs(a - b) < 1e-9; }


void countTotalNumbers() {
    int n;
    cin >> n;
    int **C = new int *[n + 1];
    FOR(i, 0, n) {
        C[i] = new int[10];
    }

    FOR(i, 0, 9) {
        C[0][i] = 0;
        C[1][i] = 1;
    }
    FOR(i, 2, n) {
        FOR(j, 0, 9) {
            C[i][j] = 0;
            FOR(k, 0, 9) {
                if (k <= j) {
                    C[i][j] += C[i - 1][k];
                } else {
                    break;
                }
            }
        }
    }

    int val = 0;
    FOR(i, 0, 9) {
        val += C[n][i];
    }

    cout << val;
}