#include "../GRAPH.h"


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

///Reverses the edges
void Transpose(Graph &G) {
    FORIT(it, G.V) {
        it->second->adjNode.clear();
        it->second->adje.clear();
    }

    EACH(item, G.E) {
        swap(item->first, item->second);
        item->first->adjNode.pb(item->second);
        item->first->adje.pb(item);
    }
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
//        cout << u->val << endl;

        FORIT(item, u->adjNode) {
            (*item)->par = u;
            if ((*item)->used == false) {
                (*item)->used = true;
                (*item)->d = u->d + 1;
                bfsQueue.push((*item));
            }

        }
    }

    return output;
}

vector<Node *> DFS(Graph &G, Node *root) {
    static vector<Node *> output;
    if (root != nullptr) {
        root->used = true;
        output.pb(root);
        FORIT(item, root->adjNode) {
            if ((*item)->used == false) {
                G.Union(root, (*item));
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

        if (u->val == val)
            return u;

        FORIT(item, u->adjNode) {
            (*item)->par = u;
            if ((*item)->used == false) {
                (*item)->used = true;
                (*item)->d = u->d + 1;
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
            node = node->par;
        }
        reverse(path.begin(), path.end());
    }
    return path;
}


int _TopologicalSortUtil(Graph &G, Node *root, stack<Node *> &topologicalStack) {

    static int visitCount = 0;
    root->used = true;
    visitCount++;
    FORIT(item, root->adjNode) {
        if (!(*item)->used) {
            _TopologicalSortUtil(G, *item, topologicalStack);
        }
    }

    topologicalStack.push(root);
}
vector<Node *> TopologicalSort(Graph &G) {

    vector<Node *> output;
    static stack<Node *> topologicalStack;
    FORIT(it, G.V) {
        if (!it->second->used) {
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
        item->second->par = item->second;
    }

    FOREACH(it, G.E) {
        Node *x, *y;
        x = G.Find((*it)->first);
        y = G.Find((*it)->second);
        if (x->val == y->val) {
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
            if (item->col == c) {
                flag = false;
                break;
            }
        }
        if (!flag) {
            continue;
        } else {
            node->col = c;
            if (is_M_Color(G, m, v + 1))
                return true;
            node->col = 0;
        }
    }
    return false;
}


/// This Function Finds shortest path distance from source vertice to all other vertice
/// \param G : Graph
/// \param root : Source Vertive
/// Generates the distance in Node::distance variable.
void SingleSourceShortestPathWithTopologicalSort(Graph &G, Node *root) {
    vector<Node *> topOrder = TopologicalSort(G);

    EACH(item, topOrder) {
        item->d = INT_MAX;
        item->used = false;
    }
    root->d = 0;
    EACH(item, topOrder) {
        Node *u = item;
        if (item->d != INT_MAX) {
            EACH(edge, item->adje) {
                Node *v = edge->to;
                if (u->d + edge->weight < v->d) {
                    v->d = u->d + edge->weight;
                    v->par = u;

                }
            }
        }
    }

}



/// Minimum Spanning Tree

vector<Node *> PrimsMST(Graph &G, Node *root) {
    vector<Node *> vec;

    FORIT(it, G.V) {
        Node *tmp = it->second;
        tmp->par = nullptr;
        tmp->used = false;
        tmp->d = INT_MAX;
        vec.pb(tmp);
    }

    root->par = root;
    root->used = false;
    root->d = 0;


    // Comparator Declaration
    function<bool(Node *&, Node *&)> funObj(
            [](Node *&x, Node *&y) -> bool { return !(x->d < y->d); });

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
        EACH(item, node->adje) {
            Node *v = item->to;
            if (item->weight < v->d) {
                v->d = item->weight;
                v->par = node;
            }
            flag = true;
        }
    }


    return output;

}

vector<Edge *> KrushkalMST(Graph &G) {
    // Sort the edges based on w
    function<bool(Edge *&, Edge *&)> funObj(
            [](Edge *&x, Edge *&y) -> bool { return (x->w < y->w); });

    sort(G.E.begin(), G.E.end(), funObj);
    int verticeCount = 0;

    vector<Edge *> vec;
    EACH(edge, G.E) {
        Node *u, *v;

        u = G.Find(edge->first);
        v = G.Find(edge->second);

        if (u->val != v->val) {
            vec.pb(edge);
            if (!edge->first->used) {
                edge->first->used = true;
                verticeCount++;
            }
            if (!edge->second->used) {
                edge->second->used = true;
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
        it->second->d = INT_MAX;
        it->second->par = nullptr;
        Q.pb(it->second);
    }
    source->d = 0;
    source->par = source;

    function<bool(Node *&, Node *&)> funObj(
            [](Node *&x, Node *&y) -> bool { return !(x->d < y->d); });
    make_heap(Q.begin(), Q.end(), funObj);

    vector<Node *> output;

    vector<float> distVect;

    while (!Q.empty()) {
        pop_heap(Q.begin(), Q.end());
        Node *u = Q.back();
        Q.pop_back();
        output.pb(u);
        distVect.pb(u->d);

        EACH(item, u->adje) {
            Node *v = item->to;
            if (v->d > u->d + item->weight) {
                v->d = u->d + item->weight;
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
        node->par = nullptr;
        node->d = INT_MAX;
    }

    source->par = source;
    source->d = 0;

    FOREACH(it, G.V) {
        Node *u = it->second;
        EACH(item, u->adje) {
            Node *v = item->to;
            if (*v == *source)
                continue;
            if (v->d > u->d + item->weight) {
                v->d = u->d + item->weight;
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



/// Stringly Connected Components

set<Node *> ConnectedComponents(Graph &G) {
    set<Node *> connComp;
    static stack<Node *> topologicalStack;


    FORIT(it, G.V) {
        if (!it->second->used) {
            _TopologicalSortUtil(G, it->second, topologicalStack);
        }
    }

    Transpose(G);

    FORIT(it, G.V) {
        it->second->used = false;
        it->second->upar = it->second;
    }


    while (!topologicalStack.empty()) {
        Node *u = topologicalStack.top();
        if (!u->used) {
            connComp.insert(u->upar);
            u->used = true;
            EACH(item, u->adjNode) {
                if (!item->used) {
                    G.Union(u, item);
                    DFS(G, item);
                }

            }
        }

        topologicalStack.pop();
    }

    return connComp;
}

