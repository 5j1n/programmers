#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;
int arr[50];
int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    int idx = 0;
    bool flag = false;
    for (int i = 0; i < words.size(); i++) {
        if (words[i] == target) {
            idx = i;
            flag = true;
            break;
        }
    }
    if (!flag) return 0;
    queue<pair<string,int>>q;
    q.push(make_pair(begin,0));
    while (arr[idx] == 0 && !q.empty()) {
        string str = q.front().first;
        int distance = q.front().second;
        q.pop();
        for (int i = 0; i < words.size(); i++) {
            int cmp = 0;
            for (int j = 0; j < str.size(); j++) {
                if (words[i][j] != str[j]) {
                    cmp++;
                }
            }
            if (cmp == 1&&arr[i]==0) {
                arr[i] = distance + 1;
                q.push(make_pair(words[i], arr[i]));
            }
        }
    }
    answer = arr[idx];
    return answer;
}

int main() {
    string begin = "hit";
    string target = "cog";
    vector<string>words = { "hot", "dot", "dog", "lot", "log" };
    cout << solution(begin, target, words);
}
