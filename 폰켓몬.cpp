#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<int,int>map;

int solution(vector<int> nums)
{
    int answer = 0;
    for (int i = 0; i<nums.size(); i++){
        map[nums[i]]++;
    }
    if (map.size()>=nums.size()/2){
        answer = nums.size()/2;
    }
    else answer = map.size();
    return answer;
}
