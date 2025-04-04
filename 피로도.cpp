#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool visited[9];
vector<vector<int>>d;
vector<int>v;
int energy;
int answer = -1;

void tracking(int size, int m, int k){
     if (size==m){
        energy = k; 
        int ret = 0;
        for (int i = 0; i<size; i++){
            if (energy>=d[v[i]][0]){
                energy -= d[v[i]][1];
                ret++;
            }
            else break;
        }
        answer = max(answer,ret);
        return;
     }   
    for (int i = 0; i<d.size(); i++){
        if (!visited[i]){
            visited[i] = true;
            v.push_back(i);
            tracking(size+1,m, k);
            visited[i] = false;
            v.pop_back();
        }
    }
    return;
}
int solution(int k, vector<vector<int>> dungeons) {
    
    d = dungeons;
    tracking(0,dungeons.size(), k);
    return answer;
}
