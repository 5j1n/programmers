#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<int>q;
    for (int i = 0; i < works.size(); i++) {
        q.push(works[i]);
    }
    while (n--) {
        int tmp = q.top();
        tmp--;
        q.pop();
        if (tmp) q.push(tmp);
        if (q.empty())break;
    }
    while(!q.empty())
    {
        answer += pow(q.top(), 2);
        q.pop();
    }
    return answer;
}
