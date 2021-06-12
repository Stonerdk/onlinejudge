#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int index;
    vector<pair<Node*, int>> dests;
    priority_queue<int, vector<int>, greater<int>> dij;
    Node(int index);
    void addEdge(Node* n, int dist);
};

Node::Node(int index) {
    this->index = index;
}

void Node::addEdge(Node* n, int dist) {
    this->dests.push_back(make_pair(n, dist));
}

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    Node** nodes = new Node * [N];
    for (int i = 0; i < N; i++)
        nodes[i] = new Node(i);
    for (int i = 0; i < M; i++) {
        int s, d, e;
        cin >> s >> d >> e;
        nodes[s - 1]->addEdge(nodes[d - 1], e);
    }

    queue<Node*> q;
    q.push(nodes[0]);
    while (!q.empty()) {
        Node* p = q.front();
        q.pop();
        for (auto i : p->dests) {
            Node* dest = i.first;
            int dist = i.second;
            if (dist + p->dij.top() < dest->dij.top()) {
                if (dest->dij.size() >= K)
                    dest->dij.pop();
                dest->dij.push(dist + p->dij.top());
                q.push(dest);
            }
        }
    }

    for (int i = 0; i < N; i++) {
        if (nodes[i]->dij.size() < K) cout << -1;
        else cout << nodes[i]->dij.top();
        cout << endl;
    }
}