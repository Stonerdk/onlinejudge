#include <iostream>
#include <string>
#include <queue>
using namespace std;
int N, row, col;
char** board;
bool** visited;
int xdir[4] = {0, 1, 0, -1};
int ydir[4] = {1, 0, -1, 0};
int treasure = 0;
string currentkey = "";

void bfs(int i, int j) {
    queue<pair<int, int>> q;
    q.push(pair<int, int>(i, j));
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        visited[x][y] = true;
        q.pop();
        for(int i = 0; i < 4; i++) {
            int nx = x + xdir[i];
            int ny = y + ydir[i];
            if (isValid(nx, ny) && !visited[nx][ny]) {
                char c = board[nx][ny];
                if (c >= 'A' && c <= 'Z') {
                    char lower = c + 'a' - 'A';
                    if (currentkey.find(lower) != string::npos) {
                        board[nx][ny] = '.';
                        for (int j = 0; j < row + 2; j++)
                            for(int k = 0; k < col + 2; k++)
                                visited[j][k] = false;
                        q.push(pair<int, int>(nx, ny));
                    }
                } else if (c >= 'a' && c <= 'z') {
                    currentkey.push_back(c);
                    board[nx][ny] = '.';
                    q.push(pair<int, int>(nx, ny));
                } else if (c == '$') {
                    treasure += 1;
                    board[nx][ny] = '.';
                    q.push(pair<int, int>(nx, ny));
                } else if (c == '.') {
                    q.push(pair<int, int>(nx, ny));
                }
            }
        }
    }
}

bool isValid(int i, int j) {
    return i >= 0 && i < row + 2 && j >= 0 && j < col + 2;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> row >> col;
        board = new char*[row + 2];
        visited = new bool*[row + 2];
        for (int j = 0; j < row + 2; j++) {
            visited[j] = new bool[col + 2];
            board[j] = new char[col + 2];
            board[j][0] = '.';
            if (j == 0 || j == row + 1) {
                for (int k = 1; k <= col; k++) {
                    board[j][k] = '.';
                    visited[j][k] = false;
                }
            } else {
                for (int k = 1; k <= col; k++) {
                    cin >> board[j][k];
                    visited[j][k] = false;
                }
            }
            board[j][col + 1] = '.';
        }
        cin >> currentkey;

        bfs(0, 0);

        for (int j = 0; j < row + 2; j++)
            delete [] board[j];
        delete [] board;
        currentkey = "";
        cout << treasure << endl;
        treasure = 0;
    }
}