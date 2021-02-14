#include <iostream>
#include <vector>
#include <cstring>
const int MAX = 10001;
bool visited[MAX];
int dp[MAX];
int maxlen = 0;
int N, M, src, dest;
int maxroad = 0;
std::vector<std::pair<int, int>>* vertices;

int dfs1(int index) {
	int res = 0;
	if (dp[index] != -1)
		return dp[index];
	for (auto p : vertices[index]) {
		int tmp = dfs1(p.first) + p.second;
		res = res < tmp ? tmp : res;
	}
	dp[index] = res;
	return res;
}

void dfs2(int index) {
	visited[index] = true;
	for (auto p : vertices[index]) {
		if (dp[index] - dp[p.first] == p.second) {
			maxroad++;
			if (!visited[p.first])
				dfs2(p.first);
		}
	}
}

int main() {
	std::cin >> N >> M;
	vertices = new std::vector<std::pair<int, int>>[N];
	for (int i = 0; i < M; i++) {
		int x, y, dist;
		std::cin >> x >> y >> dist;
		vertices[x - 1].push_back(std::make_pair(y - 1, dist));
	}
	std::cin >> src >> dest;
	src--;
	dest--;
	memset(visited, false, sizeof(visited));
	memset(dp, -1, sizeof(dp));
	std::cout << dfs1(0) << std::endl;
	dfs2(0);
	std::cout << maxroad;
}