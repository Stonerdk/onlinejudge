#include <iostream>
#include <vector>
#include <queue>

class Node {
public:
	int index;
	long long dp = 10000000001;
	long long dp2 = 10000000001;
	long long dp3 = 10000000001;
	std::vector<std::pair<Node*, long long>> edges;
	Node(int index);
	Node();
	void addEdges(Node* node, long long distance);
	long long getDP();
};
Node::Node() {

}
Node::Node(int index) {
	this->index = index;
}
void Node::addEdges(Node* node, long long distance) {
	this->edges.push_back(std::make_pair(node, distance));
}
long long Node::getDP() {
	return dp2 > dp3 ? dp3 : dp2;
}

int main() {
	int N, M;
	std::cin >> N >> M;
	Node** nodes = new Node * [N];
	for (int i = 0; i < N; i++)
	{
		nodes[i] = new Node(i);
	}
	for (int i = 0; i < M; i++)
	{
		int s, d, dist;
		std::cin >> s >> d >> dist;
		nodes[s - 1]->addEdges(nodes[d - 1], dist);
		nodes[d - 1]->addEdges(nodes[s - 1], dist);
	}
	std::queue<Node*> q2;
	q2.push(nodes[0]);
	nodes[0]->dp2 = 0;
	nodes[0]->dp = 0;

	while (!q2.empty()) {
		Node* n = q2.front();
		q2.pop();
		for (auto next : n->edges) {
			bool flag = false;
			if (next.first->dp > n->dp + next.second) {
				next.first->dp = n->dp + next.second;
				flag = true;
			}
			if (next.first->dp3 > n->dp2 + next.second) {
				next.first->dp3 = n->dp2 + next.second;
				flag = true;
			}
			if (next.first->dp2 > n->dp3 + next.second * 4) {
				next.first->dp2 = n->dp3 + next.second * 4;
				flag = true;
			}
			if (flag) {
				q2.push(next.first);
			}

		}
	}
	
	int res = 0;
	for (int i = 0; i < N; i++) {
		//std::cout << nodes[i]->index << ": " << nodes[i]->dp * 2 << ", " << nodes[i]->getDP() << std::endl;
		if (nodes[i]->dp * 2 < nodes[i]->getDP()) {
			res++;
		}
	}
	std::cout << res;
}