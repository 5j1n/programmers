#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

stack<int>s;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    for (int i = numbers.size()-1; i>-1; i--){
        while(!s.empty()&&s.top()<=numbers[i]){
            s.pop();
        }
        if (s.empty())answer.push_back(-1);
        else answer.push_back(s.top());
        s.push(numbers[i]);
    }
    reverse(answer.begin(),answer.end());
    return answer;
}
