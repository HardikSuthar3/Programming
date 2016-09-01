#include "GRAPH.h"
#define NP Node*
#define EP Edge*


map<int, NP> V;
vector<EP> E;

void MakeGraph(int n, int m) {
    REP(i, m) {
        int u, v;
        float w;
        cin >> u >> v >> w;
        Node *x, *y;
        if (V.find(u) != V.end()) x = V[u];
        else {
            x = new Node
                    (u);
            V.insert(mp(u, x));
        }
        if (V.find(v) != V.end()) y = V[v];
        else {
            y = new Node
                    (v);
            V.insert(mp(v, y));
        }
        Edge *e = new Edge(x, y, w);
        E.pb(e);
        x->adje.pb(e);
    }
}

void Mat2Graph(float **g, int n) {

    REP(i, n) {
        NP n = new Node(i);
        V.insert(mp(i, n));
    }

    FOR(i, 0, n - 1) {
        FOR(j, 0, n - 1) {
            if (g[i][j] != 0) {
                NP u = V[i];
                NP v = V[j];
                EP e = new Edge(u, v, g[i][j]);
                u->adje.pb(e);
            }
        }
    }

}

void ClearGraph() {
    V.clear();
    E.clear();
}

void PrintGraph() {
    cout << "Nodes" << endl;
    FOREACH(it, V) {
        NP u = it->second;
        cout << u->val << ": ";
        REP(i, u->adje.size()) {
            EP e = u->adje[i];
            NP v = e->second;
            cout << v->val << " ";
        }
        cout << endl;
    }
    cout << "Edges" << endl;

    EACH(item, E) {
        cout << item->first->val << " " << item->second->val << ":" << item->w << endl;
    }
}


///Reverses the edges
void Transpose() {
    FORIT(it, V) {
        it->second->adjNode.clear();
        it->second->adje.clear();
    }

    EACH(item, E) {
        swap(item->first, item->second);
//        item->first->adjNode.pb(item->second);
        item->first->adje.pb(item);
    }
}


void UfInit() {
    FOREACH(it, V) {
        it->second->upar = it->second;
    }
}
NP Find(NP x) {
    if (*x == *x->upar) {
        return x;
    }
    return x->upar = Find(x->upar);
}

void Union(NP x, NP y) {
    NP xp = Find(x);
    NP yp = Find(y);
    yp->upar = xp;
}

vector<NP> DFS(NP r) {
    static vector<NP> dfs;
    if (r->used)
        return dfs;
    r->used = true;
    dfs.pb(r);
    REP(i, r->adje.size()) {
        Node *v = r->adje[i]->second;
        if (!v->used) {
            DFS(v);
        }
    }
    return dfs;
}

vector<NP> BFS(NP r) {
    queue<NP> q;
    vector<NP> bfs;
    q.push(r);
    r->used = true;
    while (!q.empty()) {
        NP u = q.front();
        q.pop();
        bfs.pb(u);
        cout << u->val << " ";
        REP(i, u->adje.size()) {
            NP v = u->adje[i]->second;
            if (v->used == false) {
                q.push(v);
                v->used = true;
            }
        }
    }
    return bfs;
}

NP _ShortestPathBFS(NP root, int val) {
    queue<Node *, list<Node * >>
            bfsQueue;
    bfsQueue.push(root);

    while (!bfsQueue.empty()) {
        Node *u = bfsQueue.front();
        bfsQueue.pop();

        if (u->val == val)
            return u;

        FORIT(it, u->adje) {
            NP v = (*it)->second;
            if (v->used == false) {
                v->used = true;
                v->d = u->d + 1;
                bfsQueue.push(v);
            }

        }
    }
    return nullptr;
}
vector<NP> ShortestPathBFS(NP root, int val) {
    Node *node = _ShortestPathBFS(root, val);
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

int _TopologicalSortUtil(Node *root, stack<Node *> &topologicalStack) {

    static int visitCount = 0;
    root->used = true;
    visitCount++;
    FORIT(item, root->adje) {
        if (!(*item)->second->used) {
            _TopologicalSortUtil((*item)->second, topologicalStack);
        }
    }

    topologicalStack.push(root);
}
vector<Node *> TopologicalSort() {

    vector<Node *> output;
    static stack<Node *> topologicalStack;
    FORIT(it, V) {
        if (!it->second->used) {
            _TopologicalSortUtil(it->second, topologicalStack);
        }
    }

    while (!topologicalStack.empty()) {

        output.pb(topologicalStack.top());
        topologicalStack.pop();

    }
    return output;
}


bool is_M_Color(int m, int v) {

    if (v == V.size())
        return true;
    auto it = V.begin();
    advance(it, v);
    Node *node = it->second;

    FOR(c, 1, m) {
        bool flag = true;
        EACH(item, node->adje) {
            NP v = item->second;
            if (v->col == c) {
                flag = false;
                break;
            }
        }
        if (!flag) {
            continue;
        } else {
            node->col = c;
            if (is_M_Color(m, v + 1))
                return true;
            node->col = 0;
        }
    }
    return false;
}

bool isCyclePresent() {
    FOREACH(item, V) {
        item->second->par = item->second;
    }

    FOREACH(it, E) {

        NP x = Find((*it)->first);
        NP y = Find((*it)->second);
        if (x->val == y->val) {
            return true;
        }
        Union(x, y);
    }

    return false;
}


/// This Function Finds shortest path distance from source vertice to all other vertice
/// \param G : Graph
/// \param root : Source Vertive
/// Generates the distance in Node::distance variable.
void SingleSourceShortestPathWithTopologicalSort(NP root) {
    vector<NP> topOrder = TopologicalSort();

    EACH(item, topOrder) {
        item->d = INT_MAX;
        item->used = false;
    }
    root->d = 0;
    EACH(item, topOrder) {
        Node *u = item;
        if (item->d != INT_MAX) {
            EACH(edge, item->adje) {
                Node *v = edge->second;
                if (u->d + edge->w < v->d) {
                    v->d = u->d + edge->w;
                    v->par = u;

                }
            }
        }
    }

}

/// Minimum Spanning Tree

vector<NP> PrimsMST(Node *root) {
    vector<NP> vec;

    FORIT(it, V) {
        NP tmp = it->second;
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
            Node *v = item->second;
            if (item->w < v->d) {
                v->d = item->w;
                v->par = node;
            }
            flag = true;
        }
    }


    return output;

}

vector<EP> KrushkalMST() {
    // Sort the edges based on w
    function<bool(Edge *&, Edge *&)> funObj(
            [](Edge *&x, Edge *&y) -> bool { return (x->w < y->w); });

    sort(E.begin(), E.end(), funObj);
    int verticeCount = 0;

    vector<Edge *> vec;
    EACH(edge, E) {
        Node *u, *v;

        u = Find(edge->first);
        v = Find(edge->second);

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
            if (verticeCount == V.size())
                break;
        }
    }

    return vec;

}




/// Shortest Path

vector<Node *> Dijkstra(Node *source) {

    // Initiliase Single Source Graph
    //NITIALIZE SINGLE SOURCE()

    vector<Node *> Q;
    FOREACH(it, V) {
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
            Node *v = item->second;
            if (v->d > u->d + item->w) {
                v->d = u->d + item->w;
            }
        }
        make_heap(Q.begin(), Q.end(), funObj);
    }

    return output;

}

void BellmanFord(Node *source) {
    // Initialize
    FOREACH(it, V) {
        Node *node = it->second;
        node->par = nullptr;
        node->d = INT_MAX;
    }

    source->par = source;
    source->d = 0;

    FOREACH(it, V) {
        Node *u = it->second;
        EACH(item, u->adje) {
            Node *v = item->second;
            if (*v == *source)
                continue;
            if (v->d > u->d + item->w) {
                v->d = u->d + item->w;
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



/// Strongly Connected Components

set<Node *> ConnectedComponents() {
    set<Node *> connComp;
    static stack<Node *> topologicalStack;


    FORIT(it, V) {
        if (!it->second->used) {
            _TopologicalSortUtil(it->second, topologicalStack);
        }
    }

    Transpose();

    FORIT(it, V) {
        it->second->used = false;
        it->second->upar = it->second;
    }


    while (!topologicalStack.empty()) {
        Node *u = topologicalStack.top();
        if (!u->used) {
            connComp.insert(u->upar);
            u->used = true;
            EACH(item, u->adje) {
                if (!item->second->used) {
                    Union(u, item->second);
                    DFS(item->second);
                }

            }
        }

        topologicalStack.pop();
    }

    return connComp;
}







