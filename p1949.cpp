#include <iostream>
#include <list>
using namespace std;

class Node {

public:
    int pop;
    int dp;
    bool visited;
    bool calculated;
    list<Node*> children;
    void append(Node* child);
    Node();
    Node(int pop);    
};
Node::Node() {

}
Node::Node(int pop) {
    this->dp = 0;
    this->pop = pop;
    this->visited = false;
    this->calculated = false;
}

void Node::append(Node* child) {
    this->children.push_back(child);
}

void postorder(Node* n) {
    n->visited = true;
    for (auto child : n->children) {
        if (!child->visited)
            postorder(child);
    }
    int on = 0, off = 0;

    for (auto child : n->children) {
        if (child->calculated) {
            off += child->dp;
            for (auto grandchild : child->children) {
                on += grandchild->dp;
            }
        }
    } on += n->pop;
    n->dp = on > off ? on : off;
    n->calculated = true;
  
}

int main() {
    int N, p, s, d;
    cin >> N;
    Node** narr = new Node * [N];
    for (int i = 0; i < N; i++) {
        cin >> p;
        narr[i] = new Node(p);
    }
    for (int i = 0; i < N - 1; i++) {
        cin >> s >> d;
        narr[s-1]->append(narr[d-1]);
        narr[d-1]->append(narr[s-1]);
    }

    postorder(narr[0]);
    //for (int i = 0; i < N; i++)
    cout << narr[0]->dp << endl;

}
