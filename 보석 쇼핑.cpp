#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

unordered_set <string> jewel;
unordered_map <string,int> map;
vector<int> solution(vector<string> gems) {
    vector<int> answer;
    for (int i = 0; i<gems.size(); i++){
        jewel.insert(gems[i]);
    }
    int l = jewel.size(), r = gems.size();
    while(l<=r){
        bool flag= false;
        int mid = (l+r)/2;
        cout<<mid<<"\n";
        int st = 0, en = mid-1;
        map.clear();
        for (int j = 0; j<=en; j++){
            map[gems[j]]++;
        }
        if (map.size()==jewel.size()){
            answer = {st+1,en+1};
            r = mid-1;
            flag = true;
        }
        if (!flag){
            for (int j = mid; j<gems.size(); j++){
                map[gems[j-mid]]--;
                if (map[gems[j-mid]]==0) map.erase(gems[j-mid]);
                map[gems[j]]++;
                st++;
                en++;
                if (map.size()==jewel.size()){
                    if (answer.size()==0){
                        answer = {st+1,en+1};
                        r= mid-1;
                        flag = true;
                        break;
                    }
                    else if (en-st==answer[1]-answer[0] && answer[0]>st){
                        answer = {st+1,en+1};
                        r= mid-1;
                        flag = true;
                        break;
                    }
                    else if (en-st<answer[1]-answer[0]){
                        answer = {st+1,en+1};
                        r = mid-1;
                        flag = true;
                        break;
                    }
                }
            }
        }
        if (!flag) l = mid+1;
    }
    
    return answer;

}
