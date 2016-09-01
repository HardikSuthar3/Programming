/*
#include "GRAPH_OLD.h"

template<class T>
class GraphTraversal: public Graph<T> {
 public:

    // Variable Declaration
    stack <T> topologicalStack;


    // Function Declaration

    void DFS(Node<T> *root) {
        if (root == nullptr)
            return;
        root->isVisited = true;
        cout << root->value << endl;
        EACH(item, root->adjNode) {
            if (item->isVisited == false) {
                DFS(item);
            }
        }
    }

    void BFS(Node<T> *root) {
        queue<Node<T> *, list<Node<T> * >> bfsQueue;
        bfsQueue.push(root);
        root->isVisited = true;
        while (!bfsQueue.empty()) {
            Node<T> *u = bfsQueue.front();
            bfsQueue.pop();

            cout << u->value << endl;

            EACH(item, u->adjNode) {
                item->parent = u;
                if (item->isVisited == false) {
                    item->isVisited = true;
                    item->distance = u->distance + 1;
                    bfsQueue.push(item);
                }

            }
        }
    }

    Node<T> *_ShortestPathBFS(Node<T> *root, T val) {
        queue <list<Node<T> * >> bfsQueue;
        bfsQueue.push(root);
        root->isVisited = true;
        while (!bfsQueue.empty()) {
            Node<T> *u = bfsQueue.front();
            bfsQueue.pop();

            if (u->value == val)
                return u;

            EACH(item, u->adjNode) {
                item->parent = u;
                if (item->isVisited == false) {
                    item->isVisited = true;
                    item->distance = u->distance + 1;
                    bfsQueue.push(item);
                }

            }
        }
        return nullptr;
    }

    void ShortestPathBFS(Node<T> *root, T val) {
        Node<T> *node = _ShortestPathBFS(root, val);
        if (node != nullptr) {
            vector <T> path;
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
    }

    void _TopologicalSort(Node<T> *root) {

        root->isVisited = true;

        EACH(item, root->adjNode) {
            if (!item->isVisited) {
                _TopologicalSort(item);
            }
        }

        topologicalStack.push(root->value);
    }

    void TopologicalSort(Node<T> *root) {

        _TopologicalSortUtil(root);
        bool first = true;
        cout << "[";
        while (!topologicalStack.empty()) {

            if (!first)
                cout << ", ";
            cout << topologicalStack.top();
            topologicalStack.pop();
            first = false;
        }
        cout << "]";
    }

    bool isCyclePresent() {
        EACH(item, V) {
            item.second->parent = item.second;
        }

        EACH(item, E) {
            Node<T> *x, *y;
            x = Find(item->from);
            y = Find(item->to);
            if (x->value == y->value) {
                return true;
            }
            Union(x, y);
        }

        return false;
    }

    bool is_M_Color(int m, int v) {

        if (v == V.size())
            return true;
        auto it = V.begin();
        advance(it, v);
        Node<T> *node = it->second;

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
                if (is_M_Color(m, v + 1))
                    return true;
                node->color = 0;
            }
        }
        return false;
    }
};
*/
