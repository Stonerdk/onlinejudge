#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> fibv;
    fibv.push_back(1);
    fibv.push_back(1);
    int D, K, cnt = 0;
    cin >> D >> K;
    for(int i = 2; i < K; i++)
        fibv.push_back(fibv[i - 1] + fibv[i - 2]);
    int X = fibv[D - 3], Y = fibv[D - 2];
    while(K > 0) {
        K -= Y;
        cnt++;
        if (K % X == 0) {
            cout << (K / X) << "\n" << cnt;
            break;
        }
    }
}