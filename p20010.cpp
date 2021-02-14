#include <iostream>
#include <vector>
#include <cstring>
#include <iterator>
class Node;
int getMaxlen(Node* node);
int getMaxDiameter(Node* node);
Node* nodes[1001];
bool visited[1001];
int* maxlen;
int* maxdiameter;

class Node {
public:
	int index;
	std::vector<std::pair<int, Node*>> edges;
	std::vector<std::pair<int, Node*>> finalEdges;
	bool edges_occ;
	Node(int index);
	void addEdge(int node, int cost);
};

Node::Node(int index) {
	this->index = index;
}

void Node::addEdge(int node, int cost) {
	this->edges.push_back(std::make_pair(cost, nodes[node]));
}



int getMaxlen(Node* node) {
	if (maxlen[node->index] != -1)
		return maxlen[node->index];
	int res = 0;
	for (auto edge : node->finalEdges) {
		int tmp = edge.first + getMaxlen(edge.second);
		if (tmp > res)
			res = tmp;
	}
	maxlen[node->index] = res;
	return res;
}

int getMaxDiameter(Node* node) {
	if (maxdiameter[node->index] != -1)
		return maxdiameter[node->index];
	int res = 0, sec = 0;
	for (auto edge : node->finalEdges) {
		int tmp = edge.first + getMaxlen(edge.second);
		if (res < tmp) {
			sec = res;
			res = tmp;
		}
		else if (sec < tmp) {
			sec = tmp;
		}
	} res += sec;
	for (auto edge : node->finalEdges) {
		int tmp = getMaxDiameter(edge.second);
		if (tmp > res) res = tmp;
	}
	maxdiameter[node->index] = res;
	return res;
}


int main() {
	int N, M;
	std::cin >> N >> M;
	
	memset(visited, false, sizeof(visited));
	maxlen = new int[N];
	maxdiameter = new int[N];
	for (int i = 0; i < N; i++) {
		nodes[i] = new Node(i);
		maxlen[i] = -1;
		maxdiameter[i] = -1;
	}
		
	for (int i = 0; i < M; i++) {
		int s, d, dist;
		std::cin >> s >> d >> dist;
		nodes[s]->addEdge(d, dist);
		nodes[d]->addEdge(s, dist);
	}

	std::vector<Node*> visitedNodes;
	int minspanningcost = 0;
	visitedNodes.push_back(nodes[0]);
	visited[0] = true;
	while(1) {
		int mincost = 1000000;
		Node* minnode = nullptr;
		Node* minstart = nullptr;
		for (auto node : visitedNodes) {
			for (std::vector<std::pair<int, Node*>>::iterator iter = node->edges.begin(); iter != node->edges.end();) {
				if (visited[(iter)->second->index] == true) {
					iter = node->edges.erase(iter);
				}
				else {
					if (visited[(iter)->second->index] == false && (iter)->first < mincost) {
						mincost = (iter)->first;
						minnode = iter->second;
						minstart = node;
					}
					++iter;
				}
			}
		}
		if (!minnode) break;
		visited[minnode->index] = true;
		visitedNodes.push_back(minnode);
		minspanningcost += mincost;
		minstart->finalEdges.push_back(std::make_pair(mincost ,minnode));
	}
	std::cout << minspanningcost << std::endl;
	int diam = getMaxDiameter(nodes[0]);
	std::cout << diam << std::endl;
	delete[] maxlen;
	delete[] maxdiameter;
}