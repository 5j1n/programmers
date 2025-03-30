#include <string>
#include <vector>
#include <queue>

using namespace std;

priority_queue<int,vector<int>,greater<int>>pq;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    for (int i = 0; i<scoville.size(); i++)
        pq.push(scoville[i]);
    
    while(pq.size()>1&&pq.top()<K){
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        pq.push(a+2*b);
        answer++;
    }
    if (pq.empty()||pq.top()<K) answer = -1;
    return answer;
}
