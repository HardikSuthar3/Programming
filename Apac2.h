#include <fstream>
#include "TEMPLATE.h"

#define MOD 1000000007


void Apac2() {

    int T;
    fstream out;
    out.open("/Users/Hardik/Documents/op_long.txt", ios::out);
    cin >> T;

    int K;
    long A, B;
    uint64_t N;
    long double result = 0;
    int64_t cnt = 1;
    while (T > 0) {
        T--;
        cin >> A >> B >> N >> K;
        uint64_t res = 0;

        for (uint64_t i = 1; i <= N; ++i) {
            for (uint64_t j = 1; j <= N; ++j) {
                if (i != j) {
                    if ((uint64_t) (pow(i, A) + pow(j, B)) % K == 0) {
                        res++;
                    }
                }
            }
        }

        out << "Case #" << cnt++ << ": " << res % MOD << endl;

    }

    out.close();
}