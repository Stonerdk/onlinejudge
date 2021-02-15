#include <iostream>
#include <vector>
#include <algorithm>
std::vector<int> time;

long long int getTimeSum(long long int t) {
	long long int res = 0;
	for (auto u : time) {
		res += t / u;
	}
	return res;
}

long long int getInterval(long long int start, long long int end, long people) {
	long long int div = (start + end) / 2;
	long long int tsa = getTimeSum(div);
	//std::cout << "Start : " << start << " " << " End : " << end << " TS : " << tsa << " DIV : " << div << std::endl;
	long long int tsb;
	if (div - 1 >= 0)
		tsb = getTimeSum(div - 1);
	else
		tsb = 0;
	if (tsa < people) {
		return getInterval(div, end, people);
	}
	else if (tsb >= people) {
		return getInterval(start, div - 1, people);
	}
	else {
		return div;
	}
}

int main() {

	long long int N;
	int M, index;
	std::vector<std::pair<int, int>> available;
	std::cin >> N >> M;
	
	for (int i = 0; i < M; i++) {
		int tmp;
		std::cin >> tmp;
		time.push_back(tmp);
	}
	if (N <= M) {
		for (unsigned int i = 0; i < time.size(); i++) {
			available.push_back(std::make_pair(i, time[i]));
		}
		index = N - 1;
	}
	else {
		N -= M;
		long long int t = getInterval(0, 600000000000, N);
		for (unsigned int i = 0; i < time.size(); i++) {
			if (t % (long long int)time[i] == 0)
				available.push_back(std::make_pair(i, time[i]));
		}
		long long int interv = getTimeSum(t) - N;
		index = available.size() - 1 - (int)interv;
	}
	std::stable_sort(available.begin(), available.end(), 
		[](std::pair<int, int> a, std::pair<int, int> b) { return a.second < b.second; });
	std::cout << available[index].first + 1;

}