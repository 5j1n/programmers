#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

unordered_set<int>v[101];
bool visited[101];

int bfs(int x){
    queue<int>q;
    visited[x] = true;
    q.push(x);
    int ret = 1;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for (auto it = v[cur].begin(); it!=v[cur].end(); it++){
            if (visited[*it]) continue;
            visited[*it] = true;
            q.push(*it);
            ret++;
        }
    }
    return ret;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 0xfffffff;
    for (int i = 0; i<wires.size(); i++){
        v[wires[i][0]].insert(wires[i][1]);
        v[wires[i][1]].insert(wires[i][0]);
    }
    for (int i = 0; i<wires.size(); i++){
        memset(visited,false,sizeof(visited));
        v[wires[i][0]].erase(wires[i][1]);
        v[wires[i][1]].erase(wires[i][0]);
        answer =  min(answer,abs(n - 2 * bfs(wires[i][0])));
        v[wires[i][0]].insert(wires[i][1]);
        v[wires[i][1]].insert(wires[i][0]);
    }
    return answer;
}
