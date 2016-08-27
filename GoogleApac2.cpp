//
// Created by Hardik on 10/07/16.
//



#include <iostream>
#include <algorithm>
#include <fstream>
#include <math.h>

using namespace std;


void APAC2() {
    int T;
    int R, C;
    fstream out;
    out.open("/Users/Hardik/Documents/op.txt", ios::out);
    cin >> T;

    int cnt = 0, caseId = 0;

    while (T > 0) {
        T--;
        cin >> R >> C;
        cnt = 0;
        int **H = new int *[R + 2];
        int **W = new int *[R + 2];
        for (int i = 0; i < R + 2; ++i) {
            H[i] = new int[C + 2];
            W[i] = new int[C + 2];
        }
        for (int i = 0; i < R + 2; ++i) {
            H[i][0] = 0;
            H[i][C + 1] = 0;

            W[i][0] = 0;
            W[i][C + 1] = 0;
        }
        for (int j = 0; j < C + 2; ++j) {
            H[0][j] = 0;
            H[R + 1][j] = 0;

            W[0][j] = 0;
            W[R + 1][j] = 0;
        }


        for (int i = 1; i <= R; ++i) {
            for (int j = 1; j <= C; ++j) {
                cin >> H[i][j];
                W[i][j] = H[i][j];
            }
        }
        int cnt = 0;
        for (int i = 1; i <= R; ++i) {
            for (int j = 1; j <= C; ++j) {
                int x, y;
                x = min(W[i - 1][j], W[i + 1][j]);
                y = min(W[i][j - 1], W[i][j + 1]);
                int z = min(x, y);
                if (z > H[i][j]) {
                    W[i][j] = z;
                    cnt++;
                }
            }
        }

        for (int i = R; i >= 1; --i) {
            for (int j = C; j >= 1; --j) {
                int x, y;
                x = min(W[i - 1][j], W[i + 1][j]);
                y = min(W[i][j - 1], W[i][j + 1]);
                int z = min(x, y);
                if (z > H[i][j]) {
                    W[i][j] = z;
                    cnt++;
                }
            }
        }
        out << "Case #" << caseId++ << ": " << cnt << endl;
        cout << "Case #" << caseId++ << ": " << cnt << endl;
        for (int i = 0; i < R + 2; ++i) {
            delete[] H[i];
            delete[] W[i];
        }
    }

    out.close();
}

void APAC3() {
    int T;
    cin >> T;
    int testCount = 1;
    while (T > 0) {
        T--;
        int M;
        cin >> M;
        if (M == 1) {
            double a, b;
            cin >> a;
            cin >> b;
            cout << "Case #" << testCount++ << ": " << (b - a) / a;
        }
        else {
            double a, b, c;
            cin >> a;
            cin >> b;
            cin >> c;
            cout << "Case #" << testCount++ << ": " << ((-2 * a) + b + sqrt(b * b + 4 * a * c)) / (2 * a);
        }

    }
}