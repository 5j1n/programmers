#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

char arr[101][101];
bool visited[101][101];
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
int n,m;


int bfs(int i ,int j){
    int ret = arr[i][j]-'0';;
    visited[i][j] = true;
    queue<pair<int,int>>q;
    q.push({i,j});
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for (int i = 0; i<4; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if (nx<0||ny<0||nx>=n||ny>=m) continue;
            if (arr[nx][ny]=='X'||visited[nx][ny])continue;
            ret += arr[nx][ny]-'0';
            q.push({nx,ny});
            visited[nx][ny] = true;
        }
    }
    return ret;
}
vector<int> solution(vector<string> maps) {
    vector<int> answer;
    n = maps.size();
    m = maps[0].size();
    for (int i = 0; i<maps.size(); i++){
        for (int j = 0; j<maps[i].size(); j++){
            arr[i][j] = maps[i][j];
        }
    }
    
    for (int i = 0; i<maps.size(); i++){
        for (int j = 0; j<maps[i].size(); j++){
            if (arr[i][j]!='X'&&!visited[i][j]){
                answer.push_back(bfs(i,j));
            }
        }
    }
    sort(answer.begin(),answer.end());
    if (!answer.size()) answer.push_back(-1);
    return answer;
}
