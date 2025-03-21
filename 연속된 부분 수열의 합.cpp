#include <iostream>
#include <string>
#include <vector>
#include <climits>
using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    answer = {INT_MAX,INT_MAX};
    int s = 0, e = 0;
    int size = INT_MAX;
    int sum = sequence[s];
    while(s<=e&&e<sequence.size()){
        if (sum<k){
            e++;
            if (e<sequence.size()) sum+=sequence[e];
        }
        else if (sum==k){
            if (size>e-s+1){
                size = e-s+1;
                answer = {s,e};
            }
            else if (size==e-s+1&&s<answer[0]){
                answer = {s,e};
            }
            sum-=sequence[s];
            s++;
        }
        else {
            sum-=sequence[s];
            s++;
        }
    }
    return answer;
}
