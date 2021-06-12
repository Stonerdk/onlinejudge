#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    vector<int> vec;
    int u = 0;
    for (char& c : number) 
        vec.push_back((int)c - '0');
    for (int j = 0; j < k; j++) {
        for(int i = u; i < vec.size(); i++) {
            if (i == vec.size() - 1 || vec[i] < vec[i + 1]) {
                vec.erase(vec.begin() + i);
                u = i - 1 > 0 ? i - 1 : 0;
                break;
            }
        }
    }
    for (int& s : vec)
        answer += to_string(s);
    return answer;
}