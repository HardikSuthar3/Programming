#include "BinaryTree/BTree.h"


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

int main() {
    /* int t;
     cin >> t;

     t--;
     int n, m;
     cin >> n >> m;
     MakeGraph(n, m);
     PrintGraph();*/
    BT T(1);
    T.Add(1, 2, 3);
    T.Add(2, 4, 5);

    cout << T.Diameter(T.V[1]);
    return 0;
}



