#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <cstring>

using namespace std;
int N, row, col;
const int MAX = 102;
char** board;
bool visited[MAX][MAX];
int treasure = 0;
void bfs(int i, int j);
bool isValid(int i, int j);
bool key[26];

class Door {
private:
    map<char, vector<pair<int, int>>> data;
public:
    void add(char c, int i, int j);
    void open(char c);
    void clear();
};

void Door::add(char c, int i, int j) {
    if (data.find(c) == data.end()) {
        vector<pair<int, int>> temp;
        temp.push_back(make_pair(i, j));
        data.insert(make_pair(c, temp));
    }
    else {
        data[c].push_back(make_pair(i, j));
    }
};

void Door::open(char c) {
    if (data.find(c) != data.end()) {
        for (auto p : data[c]) {
            board[p.first][p.second] = '.';
        }
    }
}

void Door::clear() {
    data.clear();
}

Door door;


void bfs(int i, int j) {
    queue<pair<int, int>> q;
    q.push(pair<int, int>(i, j));
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if (!isValid(x, y))
            continue;
        char& c = board[x][y];
        if (visited[x][y] || c == '*')
            continue;
        if (c >= 'A' && c <= 'Z')
            continue;
        if (c >= 'a' && c <= 'z') {
            if (key[c - 'a'] == false) {
                key[c - 'a'] = true;
                door.open(c + 'A' - 'a');
                c = '.';
                memset(visited, false, sizeof(visited));
                /*for (; !q.empty(); q.pop());
                q.push(make_pair(i, j));
                continue;*/
            } 
        }
        else if (c == '$') {
            treasure += 1;
            c = '.';
        }
        visited[x][y] = true;
        q.push(pair<int, int>(x + 1, y));
        q.push(pair<int, int>(x - 1, y));
        q.push(pair<int, int>(x, y + 1));
        q.push(pair<int, int>(x, y - 1));
    }
}

bool isValid(int i, int j) {
    return i >= 0 && i < row + 2 && j >= 0 && j < col + 2;
}

int main() {
    cin >> N;
    vector<int> answer;
    string currentkey;

    for (int i = 0; i < N; i++) {
        cin >> row >> col;
        board = new char* [row + 2];
        for (int j = 0; j < row + 2; j++) {
            board[j] = new char[col + 2];
            board[j][0] = '.';
            if (j == 0 || j == row + 1) {
                for (int k = 1; k <= col; k++) {
                    board[j][k] = '.';
                }
            }
            else {
                for (int k = 1; k <= col; k++) {
                    cin >> board[j][k];
                    if (board[j][k] >= 'A' && board[j][k] <= 'Z')
                        door.add(board[j][k], j, k);
                }
            }
            board[j][col + 1] = '.';
        }
        memset(key, false, sizeof(key));
        memset(visited, false, sizeof(visited));
        cin >> currentkey;
        for (char c : currentkey) {
            door.open(c + 'A' - 'a');
        }

        bfs(0, 0);

        for (int j = 0; j < row + 2; j++)
            delete[] board[j];
        delete[] board;
        currentkey = "";
        answer.push_back(treasure);
        treasure = 0;
        door.clear();
    }
    for (int a : answer) {
        cout << a << endl;
    }
}

