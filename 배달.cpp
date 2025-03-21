#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int visited[51];
vector<pair<int,int>>v[51];
int arr[51][51];

void bfs(){
    visited[1] = 0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,1});
    
    while(!pq.empty()){
        int dist = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        if(visited[cur]<dist) continue;
        for (int i = 0; i<v[cur].size(); i++){
            int nxt = v[cur][i].first;
            int d = v[cur][i].second;
            if (visited[nxt]>dist+d){
                visited[nxt] = dist+d;
                pq.push({dist+d,nxt});
            } 
        }
    }
}
int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    for (int i = 1; i<=N; i++){
        visited[i] = INT_MAX;
        for (int j = 1; j<=N; j++)
            arr[i][j] = INT_MAX;
    }
    for (int i = 0; i<road.size(); i++){
        int a = road[i][0];
        int b = road[i][1];
        int dist = road[i][2];
        if (arr[a][b]>dist){
            v[a].push_back({b,dist});
            v[b].push_back({a,dist});
            arr[a][b] = arr[b][a] = dist;
        }
    }
    bfs();
    for (int i = 1; i<=N; i++){
        cout<<visited[i]<<" ";
        if (visited[i]<=K) answer++;
    }
    return answer;
}
