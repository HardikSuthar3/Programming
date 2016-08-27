#include "../Graph/OLD/GRAPH_OLD.h"

void SwapeNodes() {
    /*int n;
    list<int> a;
    FORD(i, 10, 1) {
        a.pb(i);
    }*/

    MII m;
    FOR(i, 1, 10) {
        m.insert(mp(i, i));
    }

    cout << m.size() << endl;
    /*Graph<int> G;
    G.V.pb(new Node<int>(10));
    G.V.pb(new Node<int>(20));
*/

}