#include <iostream>
#include <map>
using namespace std;

class Point {
public:
    int x;
    int y;
    Point(int x, int y);
    Point operator+(Point& b);
};

Point::Point(int x, int y) {
    this->x = x;
    this->y = y;
}
Point Point::operator+(Point& b) { 
    return Point(x + b.x, y + b.y); 
}
bool grid[2002][2002];
int L, K, W, cnt = 0;

bool& Grid(Point p) {
    return grid[p.x + L][p.y + L];
}

bool isValid(Point p) {
    return p.x + L >= 0 && p.x + L < W && p.y + L >= 0 && p.y + L < W;
}


int main() {
    char dir = 'R';
    cin >> L >> K;
    map<char, Point> dirmap;
    Point recent = Point(0, 0);
    dirmap['R'] = Point(0, 1);
    dirmap['L'] = Point(0, -1);
    dirmap['U'] = Point(-1, 0);
    dirmap['D'] = Point(1, 0);
    W = 2 * L + 1;

    for (int i = 0; i < K; i++)
    {
        int t;
        cin >> t;
        for (int j = 0; j < t; j++) {
            cnt++;
            Point update = recent + dirmap[dir];
            if (!isValid(update) || Grid(update) == true) {
                cout << cnt;
                return 0;
            }
            Grid(update) = true;
            recent = update;
        }
        cin >> dir;
    }
}