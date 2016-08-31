/*
#include "TEMPLATE.h"

class Edge;


class Node {

 public:
    int value;
    int color;
    float distance;


    bool isVisited;

    vector<Node *> adjNode;
    vector<Edge *> adjEdge;


    Node *parent;
    Node *uf_parent;

    bool operator==(const Node &rhs) const {
        return this->value == rhs.value;
    }
    bool operator!=(const Node &rhs) const {
        return this->value != rhs.value;
    }
    Node(int value) {
        this->value = value;
        this->isVisited = false;
        this->parent = nullptr;
        this->distance = 0;
        this->uf_parent = this;
    }

};

class Edge {
 public:
    float weight;
    Node *from, *to;
    bool isVisited;

    Edge(Node *from, Node *to, float weight) {
        this->from = from;
        this->to = to;
        this->weight = weight;
        this->isVisited = false;
    }

};

class Graph {
 private:

    VI par;

 public:

    vector<Edge *> E;
    map<int, Node *> V;
    map<string, Edge *> edgeMap;


    stack<int> topologicalStack;


    Node *addNode(int val) {
        Node *n = new Node(val);
        if (V.find(val) != V.end()) {
            V[val] = n;
        } else {
            V.insert(mp(val, n));
        }
        return n;
    }


    void addEdge(int src, int dst) {
        addEdge(src, dst, 0);
    }
    void addEdge(int src, int dst, float weight) {

        Node *source, *dest;
        if (V.find(src) == V.end()) {
            source = addNode(src);
        } else {
            source = V.at(src);
        }

        if (V.find(dst) == V.end()) {
            dest = addNode(dst);
        } else {
            dest = V.at(dst);
        }

        Edge *edge = new Edge(source, dest, weight);
        E.pb(edge);
        source->adjNode.pb(dest);
        source->adjEdge.pb(edge);
        edgeMap.insert(mp(to_string(source->value) + "," + to_string(dest->value), edge));
    }

    void addUndirectedEdge(int src, int dst, float weight) {

        Node *source, *dest;
        if (V.find(src) == V.end()) {
            source = addNode(src);
        } else {
            source = V.at(src);
        }

        if (V.find(dst) == V.end()) {
            dest = addNode(dst);
        } else {
            dest = V.at(dst);
        }

        Edge *edge = new Edge(source, dest, weight);
        E.pb(edge);
        source->adjNode.pb(dest);
        dest->adjNode.pb(source);
        edgeMap.insert(mp(to_string(source->value) + "," + to_string(dest->value), edge));
    }

    Edge *getEdge(Node *&a, Node *&b) {
        return edgeMap.at(to_string(a->value) + to_string(b->value));
    }

    Edge *getEdge(int a, int b) {
        return edgeMap.at(to_string(a) + to_string(b));
    }


    Node *Find(Node *x) {
        if (x->uf_parent->value != x->value) {
            x->uf_parent = Find(x->uf_parent);
        }
        return x->uf_parent;
    }

    void Union(Node *x, Node *y) {
        Node *xpar, *ypar;
        xpar = Find(x);
        ypar = Find(y);
        if (xpar->distance > ypar->distance) {
            ypar->uf_parent = xpar;
        } else if (ypar->distance > xpar->distance) {
            xpar->uf_parent = ypar;
        } else {
            ypar->uf_parent = xpar;
            xpar->distance++;
        }
    }

    */
/*void DFS(Node *root) {
        if (root == nullptr)
            return;
        root->used = true;
        cout << root->value << endl;
        FORIT(item, root->adjNode) {
            if ((*item)->used == false) {
                DFS(*item);
            }
        }
    }*//*


    */
/*void BFS(Node *root) {
        queue<Node *, deque<Node * >> bfsQueue;
        bfsQueue.push(root);

        while (!bfsQueue.empty()) {
            Node *u = bfsQueue.front();
            bfsQueue.pop();

            cout << u->value << endl;

            FORIT(item, u->adjNode) {
                (*item)->parent = u;
                if ((*item)->used == false) {
                    (*item)->used = true;
                    (*item)->distance = u->distance + 1;
                    bfsQueue.push((*item));
                }

            }
        }
    }*//*


    */
/*void ShortestPathBFS(Node *root, int val) {
        Node *node = _ShortestPathBFS(root, val);
        if (node != nullptr) {
            vector<int> path;
            while (node != nullptr) {
                path.pb(node->value);
                node = node->parent;
            }
            reverse(path.begin(), path.end());
            cout << path;
        } else {
            cout << "NA";
        }
        cout << endl;
    }*//*



};
*/
