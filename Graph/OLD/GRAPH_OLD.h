/*
#include "../../TEMPLATE.h"


template<class T>
class Node {
 public:
    T value;
    float distance;
    int color;
    bool isVisited;

    vector<Node<T> *> adjNode;

    Node<T> *parent;


    Node(T value) : value(value) {
        this->value = value;
        this->isVisited = false;
        this->parent = nullptr;
        this->distance = 0;
        this->color = -1;
    }
};

template<class T>
class Edge {
 public:
    float weight;
    Node<T> *from, *to;

    bool isVisited;

    Edge(Node<T> *from, Node<T> *to, float weight) {
        this->from = from;
        this->to = to;
        this->weight = weight;
        this->isVisited = false;
    }
};

template<class T>
class Graph {
 public:

    //Variable Declaration

    vector<Edge<T> *> E;
    map<T, Node<T> *> V;


    // Function Declaration

    Node<T> *Find(Node<T> *x) {
        if (x->parent->value != x->value) {
            x->parent = Find(x->parent);
        }
        return x->parent;
    }

    void Union(Node<T> *x, Node<T> *y) {
        Node<T> *xpar, *ypar;
        xpar = Find(x);
        ypar = Find(y);
        if (xpar->distance > ypar->distance) {
            ypar->parent = xpar;
        } else if (ypar->distance > xpar->distance) {
            xpar->parent = ypar;
        } else {
            ypar->parent = xpar;
            xpar->distance++;
        }
    }



    Node<T> *addNode(T val) {
        Node<T> *n = new Node<T>(val);
        if (V.find(val) != V.end()) {
            V[val] = n;
        } else {
            V.insert(mp(val, n));
        }
        return n;
    }

    void addEdge(T src, T dst, float weight) {

        Node<T> *source, *dest;
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

        Edge<T> *edge = new Edge<T>(source, dest, weight);
        E.pb(edge);
        source->adjNode.pb(dest);
    }

    void addUndirectedEdge(T src, T dst, float weight) {

        Node<T> *source, *dest;
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

        Edge<T> *edge = new Edge<T>(source, dest, weight);
        E.pb(edge);
        source->adjNode.pb(dest);
        dest->adjNode.pb(source);
    }

};

*/
