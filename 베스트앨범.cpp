#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool cmp(pair<int,int>a ,pair<int,int>b){
    if (a.first==b.first)
        return a.second>b.second;
    return a.first<b.first;
}
unordered_map<string,vector<pair<int,int>>>map;
unordered_map<string,int>sum;
vector<pair<int,string>>v;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    for (int i = 0; i<plays.size(); i++){
        map[genres[i]].push_back({plays[i],i});
        sum[genres[i]]+=plays[i];
    }
    for (auto it = sum.begin(); it!=sum.end(); it++){
        v.push_back({it->second,it->first});
    }
    sort(v.begin(),v.end());
    
    for (int i = v.size()-1; i>-1; i--){
        string str = v[i].second;
        sort(map[str].begin(), map[str].end(),cmp);
        
        answer.push_back(map[str][map[str].size()-1].second);
        if (map[str].size()>1) answer.push_back(map[str][map[str].size()-2].second);
    }
    
    return answer;
}
