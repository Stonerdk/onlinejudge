#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Triple {
    int idx;
    int start;
    int end;
    Triple(int idx, int start, int end) : idx(idx), start(start), end(end) {}
};

struct WaitHeapComp {
    bool operator()(Triple& a, Triple& b) {
        return a.start > b.start;
    }
};

struct UseHeapComp {
    bool operator()(Triple& a, Triple& b) {
        return a.end > b.end;
    }
};

int main() {
    int Z, N, M, x;
    cin >> Z;
    for (int i = 0; i < Z; i++) {
        cin >> N >> M;
        vector<int> zeros;
        vector<int> lastIndex(N, -1);
        priority_queue<Triple, vector<Triple>, WaitHeapComp> waitHeap;
        priority_queue<Triple, vector<Triple>, UseHeapComp> useHeap;
        vector<int> res;
        bool flag = false;
        for (int j = 0; j < M; j++) {
            cin >> x;
            if (x == 0)
                zeros.push_back(j);
            else {
                if (lastIndex[x - 1] != -1)
                    waitHeap.push(Triple(x, lastIndex[x - 1], j));
                lastIndex[x - 1] = j;
            }
        }
        zeros.push_back(M);
        for (auto j : zeros) {
            while (!waitHeap.empty() && waitHeap.top().start < j) {
                useHeap.push(waitHeap.top());
                waitHeap.pop();
            }
            if (!useHeap.empty()) {
                if (useHeap.top().end > j) {
                    if (j != M)
                        res.push_back(useHeap.top().idx);
                    useHeap.pop();
                }
                else {
                    flag = true;
                    break;
                }
            }
            else {
                if (j != M)
                    res.push_back(0);
            }
        }
        if (!flag) {
            cout << "YES" << endl;
            for (auto r : res) {
                cout << r << " ";
            }
            cout << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
}