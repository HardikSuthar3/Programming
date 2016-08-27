#include <iostream>

#define FOR(i, a, b) for(int i=(a),_b=(b); i<=_b; i++)
#define FORD(i, a, b) for(int i=(a),_b=(b); i>=_b; i--)
#define REP(i, a) for(int i=0,_a=(a); i<_a; i++)
#define EACH(it, a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)

#define DEBUG(x) { cout << #x << " = "; cout << (x) << endl; }
#define PR(a, n) { cout << #a << " = "; FOR(_,1,n) cout << a[_] << ' '; cout << endl; }
#define PR0(a, n) { cout << #a << " = "; REP(_,n) cout << a[_] << ' '; cout << endl; }

#define sqr(x) ((x) * (x))
using namespace std;


void CountOfSumWhoseSumIsN() {
    int n, S;
    cin >> n >> S;

    int **C = new int *[n];
    for (int i = 0; i < n; ++i) {
        C[i] = new int[S + 1];
        fill(C[i], C[i] + n, 0);
    }

    for (int i = 1; i <= 9; ++i) {
        C[0][i] = 1;
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= S; j++) {
            C[i][j] = 0;
            if (j != 0) {
                
                for (int k = 0; k <= 9; k++) {
                    C[i][j] += (j - k) >= 0 ? C[i - 1][j - k] : 0;
                }
            }
        }
    }

    cout << C[n - 1][S];
}