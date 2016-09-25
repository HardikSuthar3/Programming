/*#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <typeinfo>
#include <climits>
#include <cfloat>
#include <fstream>




// Container Classes

#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <functional>*/
#include<bits/stdc++.h>

using namespace std;


//Split String by Single Character Delimiter
vector<string> split(const string &s, char delim) {
    vector<string> elems;
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim))
        elems.push_back(item);
    return elems;
}
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

// Loop
#define FOR(i, a, b) for(int i=(a),_b=(b); i<=_b; i++)
#define FORD(i, a, b) for(int i=(a),_b=(b); i>=_b; i--)
#define REP(i, a) for(int i=0,_a=(a); i<_a; i++)
#define EACH(item, container) for(auto &item : container)
#define FOREACH(it, a) for(auto it = a.begin(); it != a.end(); ++it)
#define FORIT(it, a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); it++)

/// Loop Ends



/// Miscelleneous

#define mp make_pair
#define pb push_back
#define popb pop_back
#define pf push_front
#define popf pop_front


#define fi first
#define se second

#define DEBUG(x) { cout << #x << " = "; cout << (x) << endl; }

#define MOD 1000000007

inline bool EQ(double a, double b) { return fabs(a - b) < 1e-9; }

inline bool EQ(float a, float b) { return fabs(a - b) < 1e-5; }

/// Miscelleneous End



/// TypeDef Start
typedef long long int LL;
typedef map<string, int> MSI;
typedef map<int, int> MII;
typedef map<LL, LL> MLL;
typedef map<char, int> MCI;
typedef map<int, string> MIS;


typedef pair<int, int> PII;
typedef pair<string, int> PSI;
typedef pair<string, string> PSS;

typedef vector<int> VI;
typedef vector<float> VF;
typedef vector<string> VS;
typedef vector<char> VC;
typedef vector<bool> VB;
typedef vector<PII> VPII;

typedef deque<int> DQI;
typedef deque<string> DQS;
typedef deque<char> DQC;
typedef deque<bool> DQB;
typedef deque<PII> DQPII;


typedef stack<int> SI;
typedef stack<string> SS;
typedef stack<char> SC;
typedef stack<bool> SB;
typedef stack<PII> SPII;

typedef queue<int> QI;
typedef queue<string> QS;
typedef queue<char> QC;
typedef queue<bool> QB;
typedef queue<PII> QPII;

typedef priority_queue<int> PQI;
typedef priority_queue<string> PQS;
typedef priority_queue<char> PQC;
typedef priority_queue<bool> PQB;
typedef priority_queue<PII> PQPII;

/// TypeDef End



// Printing Containers

// Print Pair
template<typename T1, typename T2>
inline std::ostream &operator<<(std::ostream &os, const std::pair<T1, T2> &p) {
    return os << "(" << p.first << ", " << p.second << ")";
}

// Print Vector
template<typename T>
inline std::ostream &operator<<(std::ostream &os, const std::vector<T> &v) {
    bool first = true;
    os << "[";
    for (unsigned int i = 0; i < v.size(); i++) {
        if (!first)
            os << ", ";
        os << v[i];
        first = false;
    }
    return os << "]";
}


// Print Deque
template<typename T>
inline std::ostream &operator<<(std::ostream &os, const std::deque<T> &v) {
    bool first = true;
    os << "[";
    FOREACH(ii, v) {
        if (!first)
            os << ", ";
        os << *ii;
        first = false;
    }
    return os << "]";
}


// Print queue
template<typename T>
inline std::ostream &operator<<(std::ostream &os, const std::queue<T> &v) {
    std::queue<T> tmp(v);
    bool first = true;
    os << "[";
    while (!tmp.empty()) {
        auto ii = tmp.front();
        tmp.pop();
        if (!first)
            os << ", ";
        os << ii;
        first = false;
    }
    return os << "]";
}

// Print Set
template<typename T>
inline std::ostream &operator<<(std::ostream &os, const std::set<T> &v) {
    bool first = true;
    os << "[";
    for (typename std::set<T>::iterator ii = v.begin(); ii != v.end(); ++ii) {
        if (!first)
            os << ", ";
        os << *ii;
        first = false;
    }
    return os << "]";
}


// Print List
template<typename T>
inline std::ostream &operator<<(std::ostream &os, const std::list<T> &v) {
    bool first = true;
    os << "[";
    for (typename std::list<T>::const_iterator ii = v.begin(); ii != v.end(); ++ii) {
        if (!first)
            os << ", ";
        os << *ii;
        first = false;
    }
    return os << "]";
}


// Print Map
template<typename T1, typename T2>
inline std::ostream &operator<<(std::ostream &os, const std::map<T1, T2> &v) {
    bool first = true;
    os << "[";
    for (typename std::map<T1, T2>::const_iterator ii = v.begin(); ii != v.end(); ++ii) {
        if (!first)
            os << ", ";
        os << *ii;
        first = false;
    }
    return os << "]";
}


//End Printing Containers