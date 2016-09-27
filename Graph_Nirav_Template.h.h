#include <bits/stdc++.h>

using namespace std;


// Graph Structure
int V, E, root;
vector<int> G[1001];
vector<pair<int, int>> edges;
vector<pair<int, float>> W;
int *par;
bool *used;
// End Structure

void UFinit(int n) {
    for (int i = 0; i <= n; i++) {
        par[i] = i;
    }
}

void MakeGraph(int n, int m) {
    V = n;
    E = m;

    par = new int[n];
    used = new bool[n];
    fill(par, par + n + 1, -1);
    fill(used, used + n + 1, false);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].push_back(i);

//         comment below to make directed graph
//        G[v].push_back(i);

        edges.push_back(make_pair(u, v));
        W.push_back(make_pair(i, w));
    }
}

void PrintGraph() {
    cout << "Nodes" << endl;
    for (int i = 0; i < V; i++) {
        cout << i << " : ";
        for (int j = 0; j < G[i].size(); j++) {
            int eid = G[i][j];
            auto x = edges[eid];
            int adj = x.first ^x.second ^i;
            cout << adj << " ";
        }
        cout << endl;
    }
    cout << endl << endl;
    cout << "Edges" << endl;
    for (int i = 0; i < edges.size(); i++) {
        cout << edges[i].first << " " << edges[i].second << ": " << W[i].second << endl;
    }

}

void ClearGraph() {
    delete[]par;
    delete[] used;
    for (int i = 0; i < V; i++) {
        G[i].clear();

    }
    edges.clear();
    W.clear();
    V = E = root = -1;
}

void TransposeGraph() {
    for (int i = 0; i < V; i++) {
        G[i].clear();
    }
    for (int i = 0; i < E; i++) {
        swap(edges[i].first, edges[i].second);
        G[edges[i].first].push_back(i);

        // Uncommnet if Undirected Graph
        G[edges[i].second].push_back(i);
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


// Operations
vector<int> dfs(int v) {
    static vector<int> path;
    if (used[v]) {
        return path;
    }
    used[v] = true;
    path.push_back(v);
    for (int i = 0; i < G[v].size(); i++) {
        int edgeNo = G[v][i];
        int x = edges[edgeNo].first;
        int y = edges[edgeNo].second ^v;
        //        int adjV = edges[edgeNo].first ^edges[edgeNo].second ^i;

        int adjV = x ^y;
        if (!used[adjV]) {
            dfs(adjV);
        }
    }
    return path;
}

vector<int> bfs(int r) {

    queue<int> q;
    q.push(r);

    vector<int> res;
    used[r] = true;

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        res.push_back(v);
        for (int i = 0; i < G[v].size(); i++) {
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

vector<int> shortestPathBFS(int r, int to) {
    queue<int> q;
    q.push(r);

    fill(par, par + 1000, -1);
    used[r] = true;

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int i = 0; i < G[v].size(); i++) {
            int eno = G[v][i];
            int adj = edges[eno].first ^edges[eno].second ^v;

            par[adj] = v;

            if (adj == to) {
                queue<int> empty;
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
    vector<int> res;
    while (to != -1) {
        res.push_back(to);
        to = par[to];
    }
    reverse(res.begin(), res.end());
    return res;
}


void topologicalDfs(int v, vector<int> &topst) {
    if (used[v]) {
        return;
    }
    used[v] = true;

    for (int i = 0; i < G[v].size(); i++) {
        int edgeNo = G[v][i];
        int x = edges[edgeNo].first;
        int y = edges[edgeNo].second ^v;
        //        int adjV = edges[edgeNo].first ^edges[edgeNo].second ^i;
        int adjV = x ^y;

        if (!used[adjV]) {
            topologicalDfs(adjV, topst);
        }
    }
    topst.push_back(v);

    return;
}
vector<int> topologicalSort(int r) {
    vector<int> topOrder;
    for (int i = 0; i < V; i++) {
        if (used[i] == false) {
            topologicalDfs(i, topOrder);
        }
    }
    reverse(topOrder.begin(), topOrder.end());
    return topOrder;
}


bool isCycle() {
    UFinit(V);
    for (int i = 0; i < edges.size(); i++) {
        if (Find(edges[i].first) == Find(edges[i].second)) return true;
        Union(edges[i].first, edges[i].second);
    }
    return false;
}

bool isMColor(int m, int v) {
    static vector<int> col(V);
    if (v > V) return true;
    for (int c = 1; c <= m; ++c) {
        bool flg = true;
        for (int i = 0; i < G[v].size(); i++) {
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


// Minimum Spanning Tree

vector<int> primMst(int r) {
    vector<int> dist(V);
    fill(dist.begin(), dist.end(), INT_MAX);
    dist[r] = 0;

    function<bool(int &, int &)> compare([&](int &u, int &v) -> bool { return (dist[u] > dist[v]); });

    priority_queue<int, vector<int>, decltype(compare)> ind(compare);

    ind.push(r);

    long total_distance = 0;

    used[root] = true;
    while (!ind.empty()) {
        int u = ind.top();
        ind.pop();

        total_distance += dist[u];
        for (int i = 0; i < G[u].size(); ++i) {
            int eno = G[u][i];
            pair<int, int> p = edges[eno];
            int adj = p.first ^p.second ^u;
            float w = W[eno].second;
            if (dist[adj] > dist[u] + w) {
                dist[adj] = w;
                if (used[adj] == false) {
                    ind.push(adj);
                    used[adj] = true;
                }
            }
        }
    }
    return dist;
}

void krushkalsMst() {
    function<bool(pair<int, float> &, pair<int, float> &)>
            compare([](pair<int, float> &x, pair<int, float> &y) -> bool { return (x.second < y.second); });


    UFinit(V);

    sort(W.begin(), W.end(), compare);
    int vc = 0;
    int i = 0; // Number of Edges in solution

    vector<pair<int, int>> op;
    vector<float> we;
    while (i < V) {
        int eid = W[i].first;
        if (Find(edges[eid].first) != Find(edges[eid].second)) {
            Union(edges[eid].first, edges[eid].second);
            op.push_back(edges[eid]);
            we.push_back(W[i].second);
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

    for (int i = 0; i < op.size(); i++) {
        cout << op[i].first << " " << op[i].second << ": " << we[i] << endl;
    }
}


// Shortest Path Algorithms

vector<float> dijkastra(int src) {
    vector<int> q;

    vector<float> dist(V);
    fill(dist.begin(), dist.end(), FLT_MAX);
    dist[src] = 0;
    q.push_back(src);

    // Declare Comparator
    function<bool(int &, int &)> comparator(
            [&](int &a, int &b) -> bool {
                return dist[a] < dist[b];
            }
    );
    while (!q.empty()) {
        auto it = min_element(q.begin(), q.end(), comparator);
        int u = *it;
        q.erase(it);
        used[u] = true;
        for (int i = 0; i < G[u].size(); i++) {
            int eid = G[u][i];
            int adj = edges[eid].first ^edges[eid].second ^u;
            if (dist[adj] > dist[u] + W[eid].second) {
                dist[adj] = dist[u] + W[eid].second;
                q.push_back(adj);
                par[adj] = u;
            }
        }
    }

}

vector<float> bellmanFord(int src) {
    vector<float> dist(V);
    fill(dist.begin(), dist.end(), INT_MAX);
    dist[src] = 0;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < G[i].size(); j++) {
            int eno = G[i][j];
            pair<int, int> p = edges[eno];
            int adj = p.first ^p.second ^i;
            float w = W[eno].second;
            if (dist[adj] > dist[i] + w) {
                dist[adj] = dist[i] + w;
            }
        }
    }
    return dist;
}


//All Pair shortest Path
float **floydWarshall() {
    float **dist = new float *[V];
    for (int i = 0; i < V; i++) {
        dist[i] = new float[V];
        fill(dist[i], dist[i] + V, FLT_MAX);
        dist[i][i] = 0;
    }
    for (int i = 0; i < edges.size(); i++) {
        pair<int, int> p = edges[i];
        int u = p.first;
        int v = p.second;
        dist[u][v] = dist[v][u] = W[i].second;
    }


    for (int u = 0; u < V; u++) {
        for (int v = 0; v < V; v++) {
            for (int k = 0; k < V; k++) {
                if (dist[u][v] > dist[u][k] + dist[k][v]) {
                    dist[u][v] = dist[u][k] + dist[k][v];
                }
            }
        }
    }
    return dist;
}


vector<int> connectedComponents() {
    vector<int> top = topologicalSort(0);
    TransposeGraph();
    fill(used, used + V, false);
    vector<int> comp;
    for (int i = 0; i < V; i++) {
        int u = top[i];
        if (used[u] == false) {
            dfs(u);
            comp.push_back(u);
        }
    }
    return comp;
}


void eularPath() {
    bool flag = true;
    // Check each vertice is of even degree
    vector<int> vertice;
    for (int i = 0; i < V; i++) {
        /*    if (G[i].size() % 2 == 1)
                flag = false;
            else {
                if (G[i].size() > 0) {
                    vertice.push_back(i);
                }
            }*/

        if (G[i].size() > 0) {
            vertice.push_back(i);
        }
    }

    int u = vertice.front();
    dfs(u);
    int c = 0;
    for (int i = 0; i < vertice.size(); i++) {
        u = vertice[i];
        if (used[u] == false) {
            c++;
        }
    }
    if (c > 0)
        cout << "Eular Path Does Not Exist";
    else {
        cout << "Eular Path Does Exist";
    }
}



// Maximum Flow Graph

int **graph2Mat() {
    int **mat = new int *[V];
    for (int i = 0; i < V; i++) {
        mat[i] = new int[V];
        fill(mat[i], mat[i] + V, 0);
    }

    for (int i = 0; i < edges.size(); ++i) {
        pair<int, int> p = edges.at(i);
        mat[p.first][p.second] = W[i].second;
    }
    return mat;
}

bool bfsMaxFlow(int **res, int s, int t) {
    par = new int[V];
    fill(par, par + V, -1);
    used = new bool[V];
    fill(used, used + V, false);
    used[s] = true;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < V; i++) {
            if (i == u)
                continue;
            if (used[i] == false && res[u][i] > 0) {
                par[i] = u;
                used[i] = true;
                q.push(i);
            }
        }
    }
    return (used[t] == true);
}

int maxFlow() {
    int **mat = graph2Mat();
    int **res = new int *[V];
    for (int i = 0; i < V; i++) {
        res[i] = new int[V];
        for (int j = 0; j < V; j++) {
            res[i][j] = mat[i][j];
        }
    }

    int max_flow = 0;
    int s = 0, t = 5;

    while (bfsMaxFlow(res, s, t)) {
        int mincost = INT_MAX;
        for (int v = t; v != s; v = par[v]) {
            int u = par[v];
            mincost = min(mincost, res[u][v]);
        }
        max_flow += mincost;
        for (int v = t; v != s; v = par[v]) {
            int u = par[v];
            res[u][v] -= mincost;
            res[v][u] += mincost;
        }
    }

    return max_flow;
}