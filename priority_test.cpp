#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
struct Point {
    int x;
    int y;
};
struct MaxHeap {
    bool operator()(const Point& a, const Point& b) {
        return a.x > b.x;
    }
};
string point2str(Point a){
    return to_string(a.x) + ", " + to_string(a.y);
} 
int main() {
    priority_queue<Point, vector<Point>, MaxHeap> mxheap;
    mxheap.push(Point{2, 3});
    mxheap.push(Point{3, 4});
    cout << point2str(mxheap.top()) << endl;
    mxheap.pop();
    cout << point2str(mxheap.top()) << endl;
}