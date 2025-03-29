#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

queue<int>q;
queue<pair<int,int>>bridge;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    for (int i = 0; i<truck_weights.size(); i++){
        q.push(truck_weights[i]);
    }
    
    int cur_weight = 0;
    while(!q.empty()){
        answer++;
        if (!bridge.empty() && answer - bridge.front().second == bridge_length){
            cur_weight -= bridge.front().first;
            bridge.pop();
        }
        if (cur_weight+q.front()<=weight){
            cur_weight+=q.front();
            bridge.push({q.front(),answer});
            q.pop();
        }
    }
    return answer + bridge_length;
}
