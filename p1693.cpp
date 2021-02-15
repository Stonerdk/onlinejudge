#include <iostream>
#include <vector>
#include <iterator>
class Node {
public:
	int index;
	std::vector<Node*> edges;
	Node(int index);
};

Node::Node(int index) {
	this->index = index;
}
Node** nodes;
bool* visited;
int** dt;

void deleteAgainstNodes(int node) {
	visited[node] = true;
	for (std::vector<Node*>::iterator iter = nodes[node]->edges.begin(); iter != nodes[node]->edges.end();) {
		if (visited[(*iter)->index] == true) {
			iter = nodes[node]->edges.erase(iter);
		}
		else {
			deleteAgainstNodes((*iter)->index);
			++iter;
		}
	}
}

int dp(int node, int color) {
	if (dt[node][color] != -1)
		return dt[node][color];
	int res = -1;
	for (int i = 1; i <= 18; i++) {
		if (i == color) continue;
		int sum = i;
		for (auto n : nodes[node]->edges) {
			sum += dp(n->index, i);
		}
		if (res == -1 || res > sum)
			res = sum;
	}
	dt[node][color] = res;
	return res;
}

int main() {
	int N;
	std::cin >> N;

	nodes = new Node*[N];
	visited = new bool[N];
	dt = new int* [N + 2];
	for (int i = 0; i < N; i++) {
		visited[i] = false;
		dt[i] = new int[19];
		for (int j = 0; j < 19; j++)
			dt[i][j] = -1;
		nodes[i] = new Node(i);
	}

	for (int i = 0; i < N - 1; i++) {
		int s, d;
		std::cin >> s >> d;
		nodes[s - 1]->edges.push_back(nodes[d - 1]);
		nodes[d - 1]->edges.push_back(nodes[s - 1]);
	}
	deleteAgainstNodes(0);
	int d = dp(0, 0);
	std::cout << d;
	for (int i = 0; i < N; i++) {
		delete[] dt[i];
		delete nodes[i];
	}
	delete[] nodes;
	delete[] dt;
	delete[] visited;
}