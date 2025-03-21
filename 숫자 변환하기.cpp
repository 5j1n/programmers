#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int arr[1000001];
int X,Y,N;

int bfs(){
    queue<pair<int,int>>q;
    q.push({0,X});
    arr[X] = 0;
    if (arr[Y]!=-1) return arr[Y];
    while(!q.empty()){
        int cur = q.front().second;
        int dist = q.front().first;
        q.pop();

        if (cur+N<=Y){
            if (arr[cur+N]==-1){
                if (cur+N==Y && arr[Y]==-1) return dist+1;
                q.push({dist+1,cur+N});
                arr[cur+N] = dist+1;
            }
        }
        if (cur*2<=Y){
            if (arr[cur*2]==-1){
                if (cur*2==Y && arr[Y]==-1) return dist+1;
                q.push({dist+1,cur*2});
                arr[cur*2] = dist+1;
            }
        }
        if (cur*3<=Y){
            if (arr[cur*3]==-1){
                if (cur*3==Y&& arr[Y]==-1) return dist+1;
                q.push({dist+1,cur*3});
                arr[cur*3] = dist+1;
            }
        }
    }
    return -1;
}
int solution(int x, int y, int n) {
    int answer = 0;
    for (int i = 0; i<=y; i++)
        arr[i] = -1;
    X=x; Y=y; N=n;
    
    answer = bfs();
    return answer;
}
