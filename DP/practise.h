#include <iostream>
#include <string>
#include <vector>

using namespace std;


void LIS() {
    int n;
    cin >> n;

    int *a = new int[n];

    int *LIS = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        LIS[i] = 1;
    }

    for (int i = 1; i < n; i++) {

        for (int j = 0; j < i; j++) {
            if (a[j] < a[i] && LIS[i] < LIS[j] + 1) {
                LIS[i] = LIS[j] + 1;
            }
        }
    }
    cout << LIS[n - 1];
}


void printLCS(int **LCS, string first, string second);
int kadane(int *arr, int *start, int *finish, int n);
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

void MatrixChainMultiplication() {
    int n;
    cin >> n;
    int *a = new int[n];
    long **m = new long *[n];
    for (int i = 0; i < n; ++i) {

    }
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        m[i] = new long[n];
        m[i][i] = 0;
    }

    for (int len = 2; len < n; len++) {
        for (int i = 1; i < n - len + 1; i++) {
            int j = i + len - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                long q = m[i][k] + m[k + 1][j] + a[i - 1] * a[k] * a[j];
                if (q < m[i][j])
                    m[i][j] = q;
            }
        }
    }
    cout << m[1][n - 1];
}

void KnapSack() {
    int n;
    int W;
    cin >> n >> W;
    int *p = new int[n];
    int *w = new int[n];
    for (int i = 0; i < n; ++i) {
        cin >> p[i] >> w[i];
    }

    int **K = new int *[n + 1];
    for (int i = 0; i <= n; i++) {
        K[i] = new int[W + 1];
        K[i][0] = 0;
    }
    for (int i = 0; i <= W; i++)
        K[0][i] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= W; j++) {
            if (w[i] < j) {
                K[i][j] = max(K[i - 1][j], p[i - 1] + K[i - 1][j - w[i]]);
            }
            else {
                K[i][j] = K[i - 1][j];
            }

        }
    }
    cout << K[n][W];
}

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

void LongestBitonicSequence() {
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int *LIS = new int[n];
    int *LDS = new int[n];

    LIS[0] = LDS[0] = 1;
    for (int i = 0; i < n; ++i) {
        LIS[i] = LDS[i] = 1;
    }

    int ldsMax = INT_MIN;
    int lisMax = INT_MIN;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i] && 1 + LIS[j] > LIS[i]) {
                LIS[i] = 1 + LIS[j];
            }

        }
    }

    for (int i = n - 2; i >= 0; --i) {
        for (int j = n - 1; j > i; --j) {
            if (a[j] < a[i] && LDS[j] + 1 > LDS[i]) {
                LDS[i] = LDS[j] + 1;
            }

        }
    }
    int max = INT_MIN;
    for (int i = 0; i < n; ++i) {
        if (LIS[i] + LDS[i] - 1 > max) {
            max = LIS[i] + LDS[i] - 1;
        }
    }
    cout << max;
}

void LongestPalindromeSubString() {
    string str;
    getline(cin, str);

    bool **isPal = new bool *[str.length()];
    for (int i = 0; i < str.length(); i++) {
        isPal[i] = new bool[str.length()];
        isPal[i][i] = true;
    }
    int minLen = 1;
    int x = 1, y = 1;
    int iindex = 0, jindex = 0, length = 0;
    for (int len = 2; len <= str.length(); len++) {
        for (int i = 0; i < str.length() - len + 1; i++) {
            int j = i + len - 1;

            if (str[i] == str[j]) {
                if (j == i + 1) {
                    isPal[i][j] = true;
                }
                else {
                    isPal[i][j] = isPal[i + 1][j - 1];
                }
            }
            else {
                isPal[i][j] = false;
            }

            if (j - i + 1 > minLen && isPal[i][j]) {
                x = i;
                y = j;
                minLen = y - x + 1;
            }
        }

    }


    cout << isPal[0][str.length() - 1] << endl;

    cout << minLen << endl << endl;

    cout << str.substr(x, minLen);
}

void MinimumJump() {
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int *J = new int[n];
    J[0] = 0;

    for (int i = 1; i < n; i++) {
        J[i] = INT_MAX;
        for (int j = 0; j < i; j++) {

            if (j + a[j] >= i && 1 + J[j] < J[i]) {
                J[i] = 1 + J[j];
            }
        }
    }

    cout << J[n - 1];
}

void MaximumSquareSubmatrixWithOne() {
    int n, m;
    cin >> n >> m;
    int **a = new int *[n];
    int **s = new int *[n];
    for (int i = 0; i < n; ++i) {
        a[i] = new int[m];
        s[i] = new int[m];
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];

            if (i == 0 || j == 0) {
                s[i][j] = a[i][j];
            }
        }

    }
    int maxLen = INT_MIN;
    int x = 0, y = 0;
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; j++) {
            if (a[i][j] == 0) {
                s[i][j] = 0;
            }
            else {
                s[i][j] = 1 + min(min(s[i - 1][j], s[i][j - 1]), s[i - 1][j - 1]);
            }
            if (s[i][j] > maxLen) {
                maxLen = s[i][j];
                x = i;
                y = j;
            }
        }
    }


    cout << "(" << x - maxLen + 1 << "," << y - maxLen + 1 << ")->(" << x << "," << y << ")" << endl << "Length: "
         << maxLen << endl;
}

void MaximumRectangleSumin2DMatrix() {
    int r, c;
    cin >> r >> c;
    int **a = new int *[r];
    for (int i = 0; i < r; i++) {
        a[i] = new int[c];
        for (int j = 0; j < c; ++j) {
            cin >> a[i][j];
        }
    }

    int maxSum = INT_MIN;
    int finalLeft, finalRight, finalTop, finalBottom;
    int sum;
    int *t = new int[r], start, finish;

    for (int left = 0; left < c; ++left) {
        for (int i = 0; i < r; ++i) {
            t[i] = 0;
        }
        for (int right = left; right < c; ++right) {

            for (int i = 0; i < r; ++i) {
                t[i] += a[i][right];
            }
            sum = kadane(t, &start, &finish, r);
            // update maxSum and other output values
            if (sum > maxSum) {
                maxSum = sum;
                finalLeft = left;
                finalRight = right;
                finalTop = start;
                finalBottom = finish;
            }
        }
    }


    cout << "(" << finalTop << "," << finalLeft << ") ->" << "(" << finalBottom << "," << finalRight
         << ") ->" << endl;
    cout << maxSum;
}
int kadane(int *arr, int *start, int *finish, int n) {
    // initialize sum, maxSum and
    int sum = 0, maxSum = INT_MIN, i;

    // Just some initial value to check for all negative values case
    *finish = -1;

    // local variable
    int local_start = 0;

    for (i = 0; i < n; ++i) {
        sum += arr[i];
        if (sum < 0) {
            sum = 0;
            local_start = i + 1;
        }
        else if (sum > maxSum) {
            maxSum = sum;
            *start = local_start;
            *finish = i;
        }
    }

    // There is at-least one non-negative number
    if (*finish != -1)
        return maxSum;

    // Special Case: When all numbers in arr[] are negative
    maxSum = arr[0];
    *start = *finish = 0;

    // Find the maximum element in array
    for (i = 1; i < n; i++) {
        if (arr[i] > maxSum) {
            maxSum = arr[i];
            *start = *finish = i;
        }
    }
    return maxSum;
}

int KD(int *a, int *start, int *finish, int n) {
    *finish = -1;
    int curMax = a[0];
    int maxSoFar = a[0];
    for (int i = 1; i < n; ++i) {
        if (curMax + a[i] > a[i]) {
            curMax = curMax + a[i];
        }
        else {
            curMax = a[i];
        }
    }
}

void BinaryStringWithoutConsicutiveOnes() {
    int n;
    cin >> n;
    int *a = new int[n];
    int *b = new int[n];
    a[0] = 1;
    b[0] = 1;
    for (int i = 1; i < n; ++i) {
        a[i] = a[i - 1] + b[i - 1];
        b[i] = a[i - 1];
    }

    cout << a[n - 1] + b[n - 1];
}

