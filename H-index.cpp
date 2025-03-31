#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(),citations.end());
    
    int st = 0;
    int en = citations.size();
    
    while(st<=en){
        int mid = (st+en)/2; 
        int idx = lower_bound(citations.begin(),citations.end(),mid) - citations.begin();
        if (citations.size()-idx>=mid){ 
            answer = max(answer,mid);
            st = mid+1;
        }

        else en = mid-1;
    }
    return answer;
}
