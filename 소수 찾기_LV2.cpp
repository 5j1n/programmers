#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <cstring>

using namespace std;

bool arr[10000000];
bool visited[10];
unordered_set<int>set;
string str;
vector<int>number;
int answer = 0;

void tracking(int size, int target_size){
    if (size==target_size){
        if (!arr[stoi(str)] && !set.count(stoi(str))) {
            answer++;
            set.insert(stoi(str));
        }
        return;
    }
    
    for (int i = 0; i<number.size(); i++){
        if (!visited[i]){
            visited[i] = true;
            str.push_back(number[i]+'0');
            tracking(size+1,target_size);
            visited[i] = false;
            str.pop_back();
        }
    }
}

int solution(string numbers) {
    arr[0] = true;
    arr[1] =  true;
    for (int i = 2; i<=9999999; i++){
        if (!arr[i]){
            int tmp = i*2;
            while(tmp<=9999999){
                arr[tmp] = true;
                tmp+=i;
            }
        }
    }
    for (int i = 0; i<numbers.size(); i++){
        number.push_back(numbers[i]-'0');
    }

    for (int i = 1; i<=numbers.size(); i++){
        memset(visited,false,sizeof(visited));
        tracking(0,i);
    }
    return answer;
}
