#include <bits/stdc++.h>
using namespace std;


// 0-9
int _01KnapSack() {
    int n, W; // Number of items and weights
    cin >> n >> W;
    int *value = new int[n];
    int *weight = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> value[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> weight[i];
    }

    int **t;
    t = new int *[n + 1];
    for (int j = 0; j <= n; ++j) {
        t[j] = new int[W + 1];
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            if (i == 0 || j == 0) {
                t[i][j] = 0;
            } else {
                t[i][j] = max(t[i - 1][j], t[i - 1][j - weight[i]] + value[i]);
            }
        }
    }
    cout << t[n][W];
    return 0;
}

// B
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

// C

void CoinChange() {
    int n, m;

    cin >> n >> m;
    int *s = new int[m];

    for (int i = 0; i < m; i++) {
        cin >> s[i];
    }

    long long **t, x, y;
    t = new long long *[n + 1];
    t[0] = new long long[m];
    for (int i = 0; i < m; i++) {
        t[0][i] = 1;
    }


    for (int i = 1; i <= n; ++i) {
        t[i] = new long long[m];
        for (int j = 0; j < m; ++j) {
            x = (i - s[j] >= 0) ? t[i - s[j]][j] : 0; // If Coin is Included
            y = (j >= 1) ? t[i][j - 1] : 0; // If Coin is not included
            t[i][j] = x + y;
        }
    }
    delete[] s;
    cout << t[n][m - 1] << endl;
}

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

void CuttingRoad() {
    int len;
    cin >> len;
    int *price = new int[len];
    for (int i = 0; i < len; i++) {
        cin >> price[i];
    }

    int *sol = new int[len + 1];
    sol[0] = 0;
    int maxVal = INT_MIN;

    for (int i = 1; i <= len; ++i) {
        maxVal = INT_MIN;
        for (int j = 0; j < i; ++j) {
            maxVal = max(maxVal, sol[i - j - 1] + price[j]);
        }
        sol[i] = maxVal;
    }
    cout << sol[len];
}

// E

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


// F

void FibonacciNumber(int n) {
    if (n <= 0) {
        cout << 0;
    } else {
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

// K

int Kadane_Algo(int *a, int n, int *first, int *second) {
    int curMax, localIndex, maxSofar;
    curMax = maxSofar = a[0];
    localIndex = 0;

    *first = *second = 0;
    for (int i = 1; i < n; ++i) {
        if (curMax + a[i] < a[i]) {
            curMax = a[i];
            localIndex = i;
        } else {
            curMax = curMax + a[i];
        }
        if (maxSofar < curMax) {
            maxSofar = curMax;
            *first = localIndex;
            *second = i;
        }
    }

    return maxSofar;
}

int Kadane_2D() {
    // Read the Data
    int row, col;
    cin >> row >> col;
    int **a = new int *[row];
    for (int i = 0; i < row; i++) {
        a[i] = new int[col];
        for (int j = 0; j < col; j++) {
            cin >> a[i][j];
        }
    }

    int finalBottom, finalLeft;
    int finalTop, finalRight;
    int maxSum = INT_MIN;

    for (int left = 0; left < col; ++left) {
        int *tmp = new int[row];
        for (int i = 0; i < row; ++i) {
            tmp[i] = 0;
        }
        for (int right = left; right < col; ++right) {
            for (int i = 0; i < row; i++) {
                tmp[i] += a[i][right];
            }

            int localTop, localBottom;
            int sum = Kadane_Algo(tmp, row, &localTop, &localBottom);
            if (sum > maxSum) {
                maxSum = sum;
                finalTop = localTop;
                finalBottom = localBottom;
                finalLeft = left;
                finalRight = right;
            }
        }
    }

    cout << "(" << finalTop << "," << finalLeft << ") ->" << "(" << finalBottom << "," << finalRight
         << ") ->" << endl;
    cout << maxSum;
}

// L

void LargestSumContiniousSubarray() {
    int n;
    cin >> n;
    int *data = new int[n];
    for (int i = 0; i < n; ++i) {
        cin >> data[i];
    }

    // Alocating Memory
    int **largestSum = new int *[n];
    for (int j = 0; j < n; ++j) {
        largestSum[j] = new int[n];
    }
    int maxSofar = INT_MIN;

    /*if (data[0] > 0) {
        largestSum[0] = data[0];
    } else {
        largestSum[0] = 0;
    }*/

    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            if (j == i) {
                largestSum[i][j] = data[i];
            } else {
                largestSum[i][j] = largestSum[i][j - 1] + data[j];
            }
            maxSofar = max(largestSum[i][j], maxSofar);
        }
    }

    cout << maxSofar;
}

void LongestBitonicSubsequence() {
    int n;
    cin >> n;

    int *a = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int *lis, *lds;
    lis = new int[n];
    lds = new int[n];

    for (int i = 0; i < n; i++) {
        lis[i] = lds[i] = 1;
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i] && lis[i] < lis[j] + 1) {
                lis[i] = lis[j] + 1;
            }
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        for (int j = i; j < n; ++j) {
            if (a[j] < a[i] && lds[j] + 1 > lds[i]) {
                lds[i] = lds[j] + 1;
            }
        }
    }

    int maxValue = INT_MIN;

    for (int i = 0; i < n; i++) {
        if (lis[i] + lds[i] > maxValue) {
            maxValue = lis[i] + lds[i] - 1;
        }
    }

    cout << maxValue;
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
            } else if (first[i] == second[j]) {
                LCS[i][j] = 1 + LCS[i - 1][j - 1];
            } else {
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
        } else if (LCS[m - 1][n] > LCS[m][n - 1]) {
            m--;
        } else {
            n--;
        }
    }

    cout << lcs;
}

int LongestIncreasingSubsequence() {
// Input Read
    int n;
    cin >> n;
    vector<int> a;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.push_back(x);
    }

    // Input End

    // Sol Begins
    int cur_len = 1;
    int maxlen = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] > a[i - 1])
            cur_len++;
        else
            cur_len = 1;
        maxlen = max(maxlen, cur_len);
    }
    cout << maxlen;
    // Sol Ends
}

void LongestPalindromicSubstring() {
    string str;
    cin >> str;
    const int n = str.length();

    int **L = new int *[n];
    for (int i = 0; i < n; ++i) {
        L[i] = new int[n];
        L[i][i] = 1;
    }

    for (int len = 2; len <= n; ++len) {
        for (int i = 0; i < n - len + 1; ++i) {
            int j = i + len - 1;
            if (str[i] == str[j] && len == 2) {
                L[i][j] = 2;
            } else if (str[i] == str[j]) {
                L[i][j] = L[i + 1][j - 1] + 2;
            } else {
                L[i][j] = max(L[i + 1][j], L[i][j - 1]);
            }
        }
    }

    cout << "  ";
    for (int i = 0; i < n; ++i) {
        cout << str[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < n; ++i) {
        cout << str[i] << " ";
        for (int j = 0; j < n; ++j) {
            cout << L[i][j] << " ";
        }
        cout << endl;
    }
}


// M


void MatrixChainMultiplication() {
    int n;
    long q;
    cin >> n;

    long **mat = new long *[n];
    int *p = new int[n];

    for (int i = 0; i < n; i++) {
        mat[i] = new long[n];
        cin >> p[i];
        mat[i][i] = 0;
    }


    for (int L = 2; L < n; L++) {
        for (int i = 1; i <= n - L + 1; i++) {
            int j = i + L - 1;
            mat[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < mat[i][j])
                    mat[i][j] = q;
            }
        }
    }

    cout << mat[1][n - 1];

}

void Maximum_Length_Chain_of_Pairs() {
    int n;
    cin >> n;

    vector<pair<int, int>>
            element;
    for (int i = 0; i < n; ++i) {
        pair<int, int> p;
        cin >> p.first;
        cin >> p.second;
        element.push_back(p);
    }

    sort(element.begin(), element.end(), [](pair<int, int> &a, pair<int, int> &b) -> bool {
        return a.first < b.first;
    });


    int *LIS = new int[n];

    for (int i = 0; i < n; ++i) {
        LIS[i] = 1;
    }

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (element[j].second <= element[i].first && LIS[i] < LIS[j] + 1) {
                LIS[i] = LIS[j] + 1;
            }
        }
    }

    int maxVal = LIS[0];
    for (int i = 1; i < n; i++) {
        if (maxVal < LIS[i]) {
            maxVal = LIS[i];
        }
    }

    cout << maxVal;
}

int MaxMatWithAllOne() {
    int n, m;
    cin >> n >> m;
    int **a = new int *[n];
    for (int i = 0; i < n; ++i) {
        a[i] = new int[n];
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
    int **b = new int *[n];
    int maxElement = INT_MIN;
    for (int i = 0; i < n; ++i) {
        b[i] = new int[n];
        for (int j = 0; j < m; ++j) {
            if (i == 0 || j == 0) {
                b[i][j] = a[i][j];
            }
            else {
                if (a[i][j] == 1) {
                    b[i][j] = 1 + min(b[i - 1][j - 1], min(b[i - 1][j], b[i][j - 1]));
                }
                else {
                    b[i][j] = 0;
                }
            }

            if (maxElement < b[i][j])
                maxElement = b[i][j];
        }
    }
    cout << maxElement;
}

void MinCostPath() {
    int n, m;
    cin >> n >> m;
    int **cst = new int *[n];
    for (int i = 0; i < n; i++) {
        cst[i] = new int[m];
        for (int j = 0; j < m; ++j) {
            cin >> cst[i][j];
        }
    }

    int **minCst = new int *[n];

    for (int i = 0; i < n; ++i) {
        minCst[i] = new int[m];
    }
    // Initializing the cost of first row and column
    minCst[0][0] = cst[0][0];
    for (int i = 1; i < n; i++) {
        minCst[i][0] = minCst[i - 1][0] + cst[i][0];

    }

    for (int i = 1; i < m; i++) {
        minCst[0][i] = minCst[0][i - 1] + cst[0][i];
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            minCst[i][j] = min(minCst[i - 1][j - 1], min(minCst[i - 1][j], minCst[i][j - 1])) + cst[i][j];
        }
    }

    cout << endl << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << minCst[i][j] << " ";
        }
        cout << endl;
    }
}

double cost(vector<pair<int, int>> ele, int i, int j, int k) {
    double a = sqrt(pow(ele[i].first - ele[k].first, 2) + pow(ele[i].second - ele[k].second, 2));
    double b = sqrt(pow(ele[j].first - ele[k].first, 2) + pow(ele[j].second - ele[k].second, 2));
    double c = sqrt(pow(ele[j].first - ele[i].first, 2) + pow(ele[j].second - ele[i].second, 2));

    return (a + b + c);
}
void MinimumCostPolygonTringulation() {
    vector<pair<int, int>> ele;
    int x, y;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        ele.push_back(make_pair(x, y));
    }

    double **C = new double *[n];
    for (int i = 0; i < n; ++i) {
        C[i] = new double[n];
    }

    for (int len = 1; len <= 2; len++) {
        for (int i = 0; i < n - len + 1; i++) {
            int j = i + len - 1;
            C[i][j] = 0;
        }
    }

    for (int len = 3; len <= n; len++) {
        for (int i = 0; i < n - len + 1; i++) {
            int j = i + len - 1;
            C[i][j] = DBL_MAX;
            for (int k = i + 1; k <= j - 1; k++) {
                double val = C[i][k] + C[k][j] + cost(ele, i, j, k);
                if (val < C[i][j])
                    C[i][j] = val;
            }
        }
    }

    cout << C[0][n - 1];
}

void MinimumInitialPointsToREachDEstination() {
    int m, n;
    cin >> m >> n;

    m = m + 2;
    n = n + 2;
    int **C = new int *[m];
    int **a = new int *[m];
    for (int i = 0; i < m; ++i) {
        C[i] = new int[n];
        a[i] = new int[n];
    }
    for (int i = 1; i < m - 1; ++i) {
        for (int j = 1; j < n - 1; ++j) {
            cin >> a[i][j];
        }
    }

    // Initialise Outer boundries

    fill(C[0], C[0] + m, INT_MIN);
    fill(C[n - 1], C[n - 1] + m, INT_MIN);

    for (int i = 1; i < n - 1; ++i) {
        C[i][0] = INT_MIN;
        C[i][m - 1] = INT_MIN;
    }

    C[n - 2][m - 1] = 0;
    C[n - 1][m - 2] = 0;


    for (int i = m - 2; i > 0; --i) {
        for (int j = n - 2; j > 0; --j) {
            int tmp = a[i][j] + max(C[i + 1][j], C[i][j + 1]);
            C[i][j] = (tmp >= 0) ? 0 : tmp;
        }
    }

    cout << -1 * C[1][1] + 1;
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


// O

int OptimalBST() {
    int n;
    cin >> n;
    int *freq = new int[n];
    int **sol = new int *[n];
    for (int i = 0; i < n; ++i) {
        sol[i] = new int[n];
        cin >> freq[i];
    }

    for (int i = 0; i < n; i++) {
        sol[i][i] = freq[i];
    }

    for (int len = 2; len <= n; len++) {
        for (int i = 0; i < n - len + 1; i++) {
            int j = i + len - 1;
            int minVal = INT_MAX;
            for (int k = i; k <= j; k++) {
                int tmp = (k > i) ? sol[i][k - 1] : 0 + (k < j) ? sol[k + 1][j] : 0;
                if (tmp < minVal)
                    minVal = tmp;
            }

            sol[i][j] = minVal;
            for (int k = i; k <= j; k++) {
                sol[i][j] += freq[k];
            }
        }
    }

    cout << sol[0][n - 1];
}