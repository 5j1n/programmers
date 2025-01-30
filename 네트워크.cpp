#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool> visited(n, false); // 방문 여부를 체크하기 위한 1차원 배열
    
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            answer++;
            queue<int> q;
            q.push(i);
            visited[i] = true;
            
            while (!q.empty()) {
                int current = q.front();
                q.pop();
                
                for (int j = 0; j < n; j++) {
                    if (computers[current][j] == 1 && !visited[j]) {
                        visited[j] = true;
                        q.push(j);
                    }
                }
            }
        }
    }
    return answer;
}

int main() {
    vector<vector<int>> computers = { {1, 1, 0}, {1, 1, 0}, {0, 0, 1} };
    cout << solution(3, computers); // Expected output: 2
}
