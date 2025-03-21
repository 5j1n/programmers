#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <climits>
using namespace std;

vector<int>s;
int st,en;
unordered_map<int,vector<int>>target;
int mini = INT_MAX;
set<int>insert_time;

int solution(vector<vector<int>> targets) {
    int answer = 0;
    int removed = 0, idx = 0;
    for (int i  =0; i<targets.size(); i++){
        target[targets[i][0]].push_back(targets[i][1]);
        insert_time.insert(targets[i][0]);
    }
    for(auto it = insert_time.begin(); it!=insert_time.end(); it++){
        if (mini<=*it){
            mini = INT_MAX;
            s.clear();
            answer++;
        }
        for (int i = 0; i<target[*it].size(); i++){
            s.push_back(target[*it][i]);
            mini = min(mini,target[*it][i]);
        }
    }
    if (s.size()) answer++;
    return answer;
}
