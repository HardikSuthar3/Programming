#include "TEMPLATE.h"


int V, E;
VI G[1000];
VPII edges;
vector<pair<int, float>> W;
int *par;
bool *used;


void UFinit(int n) {
    FOR(i, 0, n) {
        par[i] = i;
    }
}
int Find(int x) {
    if (par[x] == x)
        return x;
    return par[x] = Find(par[x]);
}

void Union(int x, int y) {
    int xp, yp;
    xp = Find(x);
    yp = Find(y);
    par[yp] = xp;
}

void cleargraph() {
    REP(i, 1000) {
        G[i].clear();
    }
    edges.clear();
    W.clear();
    UFinit(V);
    delete[] par;
    delete[] used;
}

void MakeGraph(int n, int m) {
    V = n;
    E = m;

    par = new int[n + 1];
    used = new bool[n + 1];
    fill(par, par + n + 1, -1);
    fill(used, used + n + 1, false);

    REP(i, m) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].pb(i);

        // comment below to make directed graph
        G[v].pb(i);

        edges.pb(mp(u, v));
        W.pb(mp(i, w));
    }
}

void printgraph() {
    cout << "Nodes" << endl;
    FOR(i, 0, V - 1) {
        cout << i << " : ";
        FOR(j, 0, G[i].size() - 1) {
            int eid = G[i][j];
            auto x = edges[eid];
            int adj = x.first ^x.second ^i;
            cout << adj << " ";
        }
        cout << endl;
    }

    cout << "Edges" << endl;
    REP(i, edges.size()) {
        cout << edges[i].first << " " << edges[i].second << ": " << W[i].second << endl;
    }


    cout << edges;
}

void TransposeGraph() {
    REP(i, V) {
        G[i].clear();
    }
    REP(i, E) {
        swap(edges[i].first, edges[i].second);
        G[edges[i].first].pb(i);
    }
}

VI DFS(int v) {
    static VI path;
    if (used[v]) {
        return path;
    }
    used[v] = true;
    path.pb(v);
    FOR(i, 0, G[v].size() - 1) {
        int edgeNo = G[v][i];
        int x = edges[edgeNo].first;
        int y = edges[edgeNo].second ^v;
        //        int adjV = edges[edgeNo].first ^edges[edgeNo].second ^i;

        int adjV = x ^y;
        if (!used[adjV]) {
            DFS(adjV);
        }
    }
    return path;
}

VI BFS(int r) {

    QI q;
    q.push(r);

    VI res;
    used[r] = true;

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        res.pb(v);
        FOR(i, 0, G[v].size() - 1) {
            int eno = G[v][i];
            int adj = edges[eno].first ^edges[eno].second ^v;
            if (used[adj] == false) {
                used[adj] = true;
                q.push(adj);
            }
        }
    }

    return res;
}

VI BFSPath(int r, int to) {
    QI q;
    q.push(r);

    fill(par, par + 1000, -1);
    used[r] = true;

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        FOR(i, 0, G[v].size() - 1) {
            int eno = G[v][i];
            int adj = edges[eno].first ^edges[eno].second ^v;

            par[adj] = v;

            if (adj == to) {
                QI empty;
                swap(q, empty);
//                while (!q.empty()) q.pop();
                break;
            }

            if (used[adj] == false) {
                used[adj] = true;
                q.push(adj);
            }
        }
    }
    VI res;
    while (to != -1) {
        res.pb(to);
        to = par[to];
    }
    reverse(res.begin(), res.end());
    return res;
}


SI _TOPUtil(int v) {
    static stack<int> topst;
    if (used[v]) {
        return topst;
    }
    used[v] = true;

    FOR(i, 0, G[v].size() - 1) {
        int edgeNo = G[v][i];
        int x = edges[edgeNo].first;
        int y = edges[edgeNo].second ^v;
        //        int adjV = edges[edgeNo].first ^edges[edgeNo].second ^i;
        int adjV = x ^y;

        if (!used[adjV]) {
            _TOPUtil(adjV);
        }
    }
    topst.push(v);

    return topst;
}

VI TOPSort(int r) {
    SI topst = _TOPUtil(r);
    FOR(i, 1, V - 1) {
        if (used[i] == false) {
            topst = _TOPUtil(i);
        }
    }

    VI op;
    while (!topst.empty()) {
        op.pb(topst.top());
        topst.pop();
    }
    return op;
}

bool isCycle() {
    UFinit(V);
    FOR(i, 0, edges.size() - 1) {
        if (Find(edges[i].first) == Find(edges[i].second)) return true;
        Union(edges[i].first, edges[i].second);
    }
    return false;
}

bool isMColor(int m, int v) {
    static VI col(V);
    if (v > V) return true;
    FOR(c, 1, m) {
        bool flg = true;
        FOR(i, 0, G[v].size() - 1) {
            int eno = G[v][i];
            int adj = edges[eno].first ^edges[eno].second ^v;
            if (col[adj] == c) {
                flg = false;
                break;
            }
        }
        if (!flg)
            continue;
        else {
            col[v] = c;
            if (isMColor(m, v + 1) == true) return true;
            col[v] = -1;
        }
    }
    return false;
}

void PRIMMst(int r) {
    VF d(V);
    fill(d.begin(), d.end(), DBL_MAX);
    d[r] = 0;
    VI ind;

    VI mst;
    REP(i, V)ind.pb(i);

    function<bool(int &, int &)> compare([&d](int &u, int &v) -> bool { return (d[u] < d[v]); });

    bool flag = true;
    while (!ind.empty()) {
        if (!flag) {
            make_heap(ind.begin(), ind.end(), compare);
            flag = false;
        }
        pop_heap(ind.begin(), ind.end(), compare);
        int u = ind.back();
        ind.pop_back();
        mst.pb(u);
        REP(i, G[u].size()) {
            int eid = G[u][i];
            int adj = edges[eid].first ^edges[eid].second ^u;
            float w = W[eid].second;
            if (d[adj] > w) {
                d[adj] = w;
            }
        }
    }

    cout << mst;
}

void KrushkalsMst() {
    function<bool(pair<int, float> &, pair<int, float> &)>
            compare([](pair<int, float> &x, pair<int, float> &y) -> bool { return (x.second < y.second); });


    UFinit(V);

    sort(W.begin(), W.end(), compare);
    int vc = 0;
    int i = 0;

    VPII op;
    VF we;
    while (vc < V) {
        int eid = W[i].first;
        if (Find(edges[eid].first) != Find(edges[eid].second)) {
            Union(edges[eid].first, edges[eid].second);
            op.pb(edges[eid]);
            we.pb(W[i].second);
            if (used[edges[eid].first] == false) {
                vc++;
                used[edges[eid].first] = true;
            }
            if (used[edges[eid].second] == false) {
                vc++;
                used[edges[eid].second] = true;
            }
        }
        i++;

    }

    FOR(i, 0, op.size() - 1) {
        cout << op[i].first << " " << op[i].second << ": " << we[i] << endl;
    }
}

VF Dijkstra(int r) {
    VF d(V);
    fill(d.begin(), d.end(), DBL_MAX);
    d[r] = 0;
    VI ind;

    VI path;
    REP(i, V)ind.pb(i);

    function<bool(int &, int &)> compare([&d](int &u, int &v) -> bool { return (d[u] < d[v]); });

    bool flag = true;
    while (!ind.empty()) {
        if (!flag) {
            make_heap(ind.begin(), ind.end(), compare);
            flag = false;
        }
        pop_heap(ind.begin(), ind.end(), compare);
        int u = ind.back();
        ind.pop_back();
        path.pb(u);
        REP(i, G[u].size()) {
            int eid = G[u][i];
            int adj = edges[eid].first ^edges[eid].second ^u;
            float w = W[eid].second;
            if (d[adj] > d[u] + w) {
                d[adj] = d[u] + w;
            }
        }
    }

    return d;
}

VI ConnectedComponents() {
    VI top = TOPSort(0);
    TransposeGraph();
    fill(used, used + V, false);
    VI comp;
    REP(i, V) {
        int u = top[i];
        if (used[u] == false) {
            DFS(u);
            comp.pb(u);
        }
    }
    return comp;
}


void EularPath() {
    bool flag = true;
    // Check each vertice is of even degree
    VI vertice;
    REP(i, V) {
        /*    if (G[i].size() % 2 == 1)
                flag = false;
            else {
                if (G[i].size() > 0) {
                    vertice.pb(i);
                }
            }*/

        if (G[i].size() > 0) {
            vertice.pb(i);
        }
    }

    int u = vertice.front();
    DFS(u);
    int c = 0;
    REP(i, vertice.size()) {
        u = vertice[i];
        if (used[u] == false) {
            c++;
        }
    }
    if (c > 0)
        cout << "Eular Path Does Not Exist";
    else{
        cout << "Eular Path Does Exist";
    }
}


