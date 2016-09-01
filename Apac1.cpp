#include "TEMPLATE.h"
#include <fstream>


long long C(int n, int r) {
    if (r > n / 2) r = n - r; // because C(n, r) == C(n, n - r)
    long long ans = 1;
    int i;

    for (i = 1; i <= r; i++) {
        ans *= n - r + i;
        ans /= i;
    }

    return ans;
}


void Apac1() {
    int64_t T;
    fstream out;
    out.open("/Users/Hardik/Documents/op_long.txt", ios::out);
    cin >> T;
    long l, r;
    long n;
    long double result = 0;
    int64_t cnt = 1;
    while (T > 0) {
        T--;
        cin >> l >> r;
        n = min(l, r);
        result = n;

        long i = 2;
        while (i <= n) {
            result += C(n, i);
            i += 2;
        }
        out << "Case #" << cnt++ << ": " << result << endl;
    }


    out.close();

}