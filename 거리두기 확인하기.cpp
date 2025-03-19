#include <string>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
vector<pair<int,int>>people;
int visited[6][6];
char arr[5][5];

bool bfs(int x, int y){
    visited[x][y] = 0;
    queue<pair<int,pair<int,int>>>q;
    q.push({0,{x,y}});
    
    while(!q.empty()){
        int dist = q.front().first;
        int curX = q.front().second.first;
        int curY = q.front().second.second;
        q.pop();
        
        for (int i = 0; i<4; i++){
            int nx = curX + dx[i];
            int ny = curY + dy[i];
            if (nx<0||ny<0||nx>4||ny>4) continue;
            if (visited[nx][ny]!=-1) continue;
            if (arr[nx][ny]=='X') continue;
            visited[nx][ny] = visited[x][y]+1;
            if (arr[nx][ny]=='P' && dist+1<=2) return false;
            q.push({dist+1,{nx,ny}});
        }
    }
    return true;
}
vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for (int t = 0; t<places.size(); t++){
        people.clear();
        
        for (int i = 0; i<5; i++){
            for (int j = 0; j<5; j++){
                arr[i][j] = places[t][i][j];
                if (arr[i][j]=='P') people.push_back({i,j});
            }
        }
        bool flag = true;
        for (int i = 0; i<people.size(); i++){
            memset(visited,-1,sizeof(visited));
            if(!bfs(people[i].first, people[i].second)){
                answer.push_back(0);
                flag = false;
                break;
            }
        }
        if (flag) answer.push_back(1);
        
    }
    return answer;
}
