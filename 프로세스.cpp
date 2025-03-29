#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

queue<pair<int,int>>q;
priority_queue<int>pq;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    for (int i = 0; i<priorities.size(); i++){
        q.push({priorities[i],i});
        pq.push(priorities[i]);
    }
    
    while(!q.empty()){
        answer++;
        int tmp = q.front().first;
        int idx = q.front().second;
        q.pop();
        if (idx==location && pq.top()==tmp){
            break;
        }
        else if (pq.top()==tmp){
            pq.pop();
        }
        else {
            q.push({tmp,idx});
            answer--;
        }
    }
    
    return answer;
}
