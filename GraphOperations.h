#include "GRAPH.h"


Graph Mat2Graph(float **g, int n) {

    Graph G;
    FOR(i, 0, n - 1) {
        FOR(j, 0, n - 1) {
            if (g[i][j] != 0) {
                G.addEdge(i, j, g[i][j]);
            }
        }
    }
    return G;
}


// Traversal
vector<Node *> BFS(Graph &G, Node *root) {

    vector<Node *> output;
    queue<Node *, deque<Node * >> bfsQueue;
    bfsQueue.push(root);

    while (!bfsQueue.empty()) {
        Node *u = bfsQueue.front();
        bfsQueue.pop();
        output.pb(u);
//        cout << u->value << endl;

        FORIT(item, u->adjNode) {
            (*item)->parent = u;
            if ((*item)->isVisited == false) {
                (*item)->isVisited = true;
                (*item)->distance = u->distance + 1;
                bfsQueue.push((*item));
            }

        }
    }

    return output;
}

vector<Node *> DFS(Graph &G, Node *root) {
    static vector<Node *> output;
    if (root != nullptr) {
        root->isVisited = true;
        output.pb(root);
        FORIT(item, root->adjNode) {
            if ((*item)->isVisited == false) {
                DFS(G, *item);
            }
        }
    }
    return output;
}


Node *_ShortestPathBFS(Graph &G, Node *root, int val) {
    queue<Node *, list<Node * >>
            bfsQueue;
    bfsQueue.push(root);

    while (!bfsQueue.empty()) {
        Node *u = bfsQueue.front();
        bfsQueue.pop();

        if (u->value == val)
            return u;

        FORIT(item, u->adjNode) {
            (*item)->parent = u;
            if ((*item)->isVisited == false) {
                (*item)->isVisited = true;
                (*item)->distance = u->distance + 1;
                bfsQueue.push((*item));
            }

        }
    }
    return nullptr;
}
vector<Node *> ShortestPathBFS(Graph &G, Node *root, int val) {
    Node *node = _ShortestPathBFS(G, root, val);
    vector<Node *> path;
    if (node != nullptr) {
        while (node != nullptr) {
            path.pb(node);
            node = node->parent;
        }
        reverse(path.begin(), path.end());
    }
    return path;
}


int _TopologicalSortUtil(Graph &G, Node *root, stack<Node *> &topologicalStack) {

    static int visitCount = 0;
    root->isVisited = true;
    visitCount++;
    FORIT(item, root->adjNode) {
        if (!(*item)->isVisited) {
            _TopologicalSortUtil(G, *item, topologicalStack);
        }
    }

    topologicalStack.push(root);
}
vector<Node *> TopologicalSort(Graph &G) {

    vector<Node *> output;
    static stack<Node *> topologicalStack;
    FORIT(it, G.V) {
        if (!it->second->isVisited) {
            _TopologicalSortUtil(G, it->second, topologicalStack);
        }
    }

    while (!topologicalStack.empty()) {

        output.pb(topologicalStack.top());
        topologicalStack.pop();

    }
    return output;
}

bool isCyclePresent(Graph &G) {
    FOREACH(item, G.V) {
        item->second->parent = item->second;
    }

    FOREACH(it, G.E) {
        Node *x, *y;
        x = G.Find((*it)->from);
        y = G.Find((*it)->to);
        if (x->value == y->value) {
            return true;
        }
        G.Union(x, y);
    }

    return false;
}

bool is_M_Color(Graph &G, int m, int v) {

    if (v == G.V.size())
        return true;
    auto it = G.V.begin();
    advance(it, v);
    Node *node = it->second;

    FOR(c, 1, m) {
        bool flag = true;
        EACH(item, node->adjNode) {
            if (item->color == c) {
                flag = false;
                break;
            }
        }
        if (!flag) {
            continue;
        } else {
            node->color = c;
            if (is_M_Color(G, m, v + 1))
                return true;
            node->color = 0;
        }
    }
    return false;
}

void ShortestPathWithTopologicalSort(Graph &G, Node *root) {
    vector<Node *> topOrder = TopologicalSort(G);
    root->distance = 0;
    EACH(item, topOrder) {
        item->isVisited = false;
    }
    EACH(item, topOrder) {
    }
}



/// Minimum Spanning Tree

vector<Node *> PrimsMST(Graph &G, Node *root) {
    vector<Node *> vec;

    FORIT(it, G.V) {
        Node *tmp = it->second;
        tmp->parent = nullptr;
        tmp->isVisited = false;
        tmp->distance = INT_MAX;
        vec.pb(tmp);
    }

    root->parent = root;
    root->isVisited = false;
    root->distance = 0;


    // Comparator Declaration
    function<bool(Node *&, Node *&)> funObj(
            [](Node *&x, Node *&y) -> bool { return !(x->distance < y->distance); });

    vector<Node *> output;
    bool flag = true;

    while (!vec.empty()) {
        if (flag) {
            flag = false;
            make_heap(vec.begin(), vec.end(), funObj);
        }


//             make_heap(vec.begin(), vec.end(), funObj);

        pop_heap(vec.begin(), vec.end());
        Node *node = vec.back();
        vec.pop_back();

        output.pb(node);
        EACH(item, node->adjEdge) {
            Node *v = item->to;
            if (item->weight < v->distance) {
                v->distance = item->weight;
                v->parent = node;
            }
            flag = true;
        }
    }


    return output;

}

vector<Edge *> KrushkalMST(Graph &G) {
    // Sort the edges based on weight
    function<bool(Edge *&, Edge *&)> funObj(
            [](Edge *&x, Edge *&y) -> bool { return (x->weight < y->weight); });

    sort(G.E.begin(), G.E.end(), funObj);
    int verticeCount = 0;

    vector<Edge *> vec;
    EACH(edge, G.E) {
        Node *u, *v;

        u = G.Find(edge->from);
        v = G.Find(edge->to);

        if (u->value != v->value) {
            vec.pb(edge);
            if (!edge->from->isVisited) {
                edge->from->isVisited = true;
                verticeCount++;
            }
            if (!edge->to->isVisited) {
                edge->to->isVisited = true;
                verticeCount++;
            }
            if (verticeCount == G.V.size())
                break;
        }
    }

    return vec;

}




/// Shortest Path

vector<Node *> Dijkstra(Graph &G, Node *source) {

    // Initiliase Single Source Graph
    //NITIALIZE SINGLE SOURCE()

    vector<Node *> Q;
    FOREACH(it, G.V) {
        it->second->distance = INT_MAX;
        it->second->parent = nullptr;
        Q.pb(it->second);
    }
    source->distance = 0;
    source->parent = source;

    function<bool(Node *&, Node *&)> funObj(
            [](Node *&x, Node *&y) -> bool { return !(x->distance < y->distance); });
    make_heap(Q.begin(), Q.end(), funObj);

    vector<Node *> output;

    vector<float> distVect;

    while (!Q.empty()) {
        pop_heap(Q.begin(), Q.end());
        Node *u = Q.back();
        Q.pop_back();
        output.pb(u);
        distVect.pb(u->distance);

        EACH(item, u->adjEdge) {
            Node *v = item->to;
            if (v->distance > u->distance + item->weight) {
                v->distance = u->distance + item->weight;
            }
        }
        make_heap(Q.begin(), Q.end(), funObj);
    }

    return output;

}

void BellmanFord(Graph &G, Node *source) {
    // Initialize
    FOREACH(it, G.V) {
        Node *node = it->second;
        node->parent = nullptr;
        node->distance = INT_MAX;
    }

    source->parent = source;
    source->distance = 0;

    FOREACH(it, G.V) {
        Node *u = it->second;
        EACH(item, u->adjEdge) {
            Node *v = item->to;
            if (*v == *source)
                continue;
            if (v->distance > u->distance + item->weight) {
                v->distance = u->distance + item->weight;
            }
        }
    }
}

void FloydWarshall(float **d, int n) {
    /// This is the dynamic programming
    FOR(k, 0, n - 1) {
        FOR(i, 0, n - 1) {
            FOR(j, 0, n - 1) {
                if (d[i][k] + d[k][j] < d[i][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }

}

