#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    stack<int>s;
    vector<int>days;
    for (int i = 0; i<progresses.size(); i++){
        int tmp = (100-progresses[i])/speeds[i];
        if((100-progresses[i])%speeds[i]) tmp++;
        days.push_back(tmp);
    }
    int size = 0;
    for (int i = 0; i<days.size(); i++){
        if (!s.empty()&&s.top()<days[i]){
            answer.push_back(size);
            while(!s.empty()) s.pop();
            s.push(days[i]);
            size = 1;
        }
        else if (s.empty()) {
            s.push(days[i]);
            size = 1;
        }
        else if (!s.empty()&&s.top()>=days[i]){
            size++;
        }
    }
    if (size) answer.push_back(size);
    return answer;
}
