#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<pair<int,int>>v;
int maxi =0;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    for (int i = 0; i<sizes.size(); i++){
        v.push_back({sizes[i][0],sizes[i][1]});
        maxi = max(maxi,sizes[i][0]);
        maxi = max(maxi,sizes[i][1]);
    }
    
    for (int i = 0; i<v.size(); i++){
        if (v[i].first<v[i].second) v[i].second = 0;
        else v[i].first = 0;
    }
    int maxi2 = 0;
    for (int i = 0; i<v.size(); i++){
        int tmp = max(v[i].first, v[i].second);
        maxi2 = max(tmp,maxi2);
    }
    answer = maxi * maxi2;
    return answer;
}
