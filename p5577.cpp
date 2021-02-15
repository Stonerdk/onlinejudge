#include <iostream>
class ColorPacket;
class ColorPacket {
public:
	int color;
	int count;
	ColorPacket* next = nullptr;
	ColorPacket* prev = nullptr;
	bool panged = false;
	ColorPacket(int color, int count);
};

ColorPacket::ColorPacket(int color, int count) {
	this->color = color;
	this->count = count;
}

int main() {
	ColorPacket* start = new ColorPacket(0, 0);
	ColorPacket* end = new ColorPacket(0, 0);
	ColorPacket* last = start;
	start->next = end;
	end->prev = start;

	int N, col;
	std::cin >> N;
	for (int i = 0; i < N; i++) {
		std::cin >> col;
		if (last->color != col) {
			ColorPacket* tmp = new ColorPacket(col, 1);
			tmp->next = end;
			tmp->prev = last;
			last->next = tmp;
			end->prev = tmp;
			last = tmp;
		}
		else {
			last->count++;
		}
	}
	int res = 0;
	for (ColorPacket* iter = start->next; iter->next != end; iter = iter->next) {
		int tmp;
		int pcnt = 0;
		ColorPacket* right,* left;
		if (iter->prev->color == iter->next->color && iter->count == 1) {
			if (iter->prev->count + iter->next->count >= 3) {
				pcnt += 1;
				right = iter->next;
				left = iter->prev;
				while (1) {
					if (right->color == 0 || left->color == 0) break;
					if (right->color == left->color && right->count + left->count >= 4) {
						pcnt += right->count + left->count;
						right = right->next;
						left = left->prev;
					}
					else break;
				}
			}
		}
		else {
			if (iter->prev->count == 3) {
				if (iter->count >= 2) {
					iter->count--;
					pcnt += 1 + iter->prev->count;
					right = iter;
					left = iter->prev->prev;
					while (1) {
						if (right->color == 0 || left->color == 0) break;
						if (right->color == left->color && right->count + left->count >= 4) {
							pcnt += right->count + left->count;
							right = right->next;
							left = left->prev;
						}
						else break;
					}
					iter->count++;
				}
				else if (iter->count == 1) {
					pcnt += 1 + iter->prev->count;
					right = iter->next;
					left = iter->prev->prev;
					while (1) {
						if (right->color == 0 || left->color == 0) break;
						if (right->color == left->color && right->count + left->count >= 4) {
							pcnt += right->count + left->count;
							right = right->next;
							left = left->prev;
						}
						else break;
					}
				}
			}
			else if (iter->next->count == 3) {
				if (iter->count >= 2) {
					if (iter->count >= 2) {
						iter->count--;
						pcnt += 1 + iter->next->count;
						right = iter->next->next;
						left = iter;
						while (1) {
							if (right->color == 0 || left->color == 0) break;
							if (right->color == left->color && right->count + left->count >= 4) {
								pcnt += right->count + left->count;
								right = right->next;
								left = left->prev;
							}
							else break;
						}
						iter->count++;
					}
				}
				else if (iter->count == 1) {
					pcnt += 1 + iter->next->count;
					right = iter->next->next;
					left = iter->prev;
					while (1) {
						if (right->color == 0 || left->color == 0) break;
						if (right->color == left->color && right->count + left->count >= 4) {
							pcnt += right->count + left->count;
							right = right->next;
							left = left->prev;
						}
						else break;
					}
				}
			}
		}
		if (pcnt > res) res = pcnt;
	}
	std::cout << N - res << std::endl;
}