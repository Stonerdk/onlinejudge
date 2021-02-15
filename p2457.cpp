#include <iostream>
#include <vector>
#include <algorithm>
int monthday[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int date2num(int month, int day) {
	int res = 0;
	for (int i = 1; i < month; i++)
		res += monthday[i - 1];
	return res + day;
}

class Flower {
public:
	int startday;
	int endday;
	Flower(int sm, int sd, int dm, int dd);
};

Flower::Flower(int sm, int sd, int dm, int dd) {
	this->startday = date2num(sm, sd);
	this->endday = date2num(dm, dd);
}
std::vector<Flower*> flowerList;

int main() {
	int N;
	std::cin >> N;
	for (int i = 0; i < N; i++) {
		int sm, sd, dm, dd;
		std::cin >> sm >> sd >> dm >> dd;
		flowerList.push_back(new Flower(sm, sd, dm, dd));
	}
	std::stable_sort(flowerList.begin(), flowerList.end(), [](Flower* a, Flower* b) {
		return a->startday < b->startday;
	});
	
	int thres = 60;
	int nextthres = 60;
	const int lastthres = date2num(11, 30) + 1;
	int cnt = 0;
	int res = 0;
	for (unsigned int i = 0; i < flowerList.size(); i++) {
		if (flowerList[i]->startday > thres) {
			if (thres != nextthres) {
				thres = nextthres;
				cnt++;
			} else {
				break;
			}
		}
		if (flowerList[i]->startday <= thres) {
			if (flowerList[i]->endday > nextthres) {
				if (flowerList[i]->endday >= lastthres) {
					res = cnt + 1;
					break;
				}
				nextthres = flowerList[i]->endday;
			}
		}
	}
	std::cout << res << std::endl;
}