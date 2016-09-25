#include <iostream>
#include <vector>
#include <limits>
#include <cfloat>
#include <math.h>


using namespace std;

double cost(vector<pair<int, int>> ele, int i, int j, int k);

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
double cost(vector<pair<int, int>> ele, int i, int j, int k) {
    double a = sqrt(pow(ele[i].first - ele[k].first, 2) + pow(ele[i].second - ele[k].second, 2));
    double b = sqrt(pow(ele[j].first - ele[k].first, 2) + pow(ele[j].second - ele[k].second, 2));
    double c = sqrt(pow(ele[j].first - ele[i].first, 2) + pow(ele[j].second - ele[i].second, 2));

    return (a + b + c);
}

