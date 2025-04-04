#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string>v;
string str;
char arr[5] = {'A','E','I','O','U'};

void tracking(int size, int m){
    if (size==m){
        v.push_back(str);
        return;
    }
    for (int i = 0; i<5; i++){
        str.push_back(arr[i]);
        tracking(size+1,m);
        str.pop_back();
    }
}
int solution(string word) {
    int answer = 0;
    for (int i = 1; i<=5; i++){
        tracking(0,i);
    }
    sort(v.begin(),v.end());
    for (int i =0 ; i<v.size(); i++){
        if (v[i]==word){
            answer = i+1;
            break;
        }
    }
    return answer;
}
