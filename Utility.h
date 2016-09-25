#include<bits/stdc++.h>
using namespace std;



// Change Default Input as file

/*    ifstream cin("/HSData/Data/IITM/workspace/CLion/ProblemsImplementation/output.txt");
    std::streambuf *buf = std::cin.rdbuf();
    std::cin.rdbuf(cin.rdbuf());*/

int prime(long n) {
    if (n < 2)
        return 0;
    bool *prm = new bool[n + 1];
    fill(prm, prm + n + 1, false);
    int count = 0;
    for (int num = 2; num <= n; num++) {
        bool flag = false;
        for (int i = 2; i <= sqrt(num); i++) {
            if (prm[i] == true) {
                if (num % i == 0) {
                    prm[num] = false;
                    flag = true;
                    break;
                }
            }
        }

        if (flag == false) {
            count++;
            prm[num] = true;
        }
    }
    return count;
}


/// Split the String
/// \param s : Input String
/// \param delim: Delimeter
/// \return : Vector of String separated by delimenter
vector<string> split(const string &s, char delim) {
    vector<string> elems;
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim))
        elems.push_back(item);
    return elems;
}

int Kadane_Algo(int *a, int *start, int *finish, int n) {
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