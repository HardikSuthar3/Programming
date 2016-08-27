#include "GRAPH.h"


int main() {
    // CoinChange();


    MSI map;
    map.insert(mp("A", 1));
    map.insert(mp("B", 2));
    map.insert(mp("C", 3));
    map.insert(mp("D", 4));
    map.insert(mp("E", 5));

    MIS mapRev;
    FOREACH(it, map) {
        mapRev.insert(mp(it->second, it->first));
    }

    Graph G;

    G.addEdge(map.at("A"), map.at("B"), -1);
    G.addEdge(map.at("B"), map.at("E"), 2);
    G.addEdge(map.at("E"), map.at("D"), -3);
    G.addEdge(map.at("D"), map.at("C"), 5);
    G.addEdge(map.at("A"), map.at("C"), 4);
    G.addEdge(map.at("B"), map.at("C"), 3);
    G.addEdge(map.at("B"), map.at("D"), 2);
    G.addEdge(map.at("D"), map.at("B"), 1);

//     cout << (G.is_M_Color(3, 0) ? "Yes" : "No");
/*
    G.BellmanFord(G.V.at(1));

    FORIT(it, G.V) {
        Node *n = it->second;
        cout << mapRev.at(n->value) << ": " << n->distance << endl;
    }*/

    int a = 10;
    hash<Node *> objHash;
    cout << objHash(G.V.at(map["A"]));

    return 0;
}
