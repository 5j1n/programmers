#include <vector>
#include <iostream>
#include <stack>
using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    stack<int>s;
    for (int i = arr.size()-1; i>-1; i--){
        int tmp = arr[i];
        while(!s.empty()&&s.top()==tmp)
            s.pop();
        s.push(tmp);
    }
    answer.resize(s.size());
    int idx = 0;
    while(!s.empty()){
        answer[idx] = s.top();
        s.pop();
        idx++;
    }
    return answer;
}
