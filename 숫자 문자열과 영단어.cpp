#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<string,int>map;
int solution(string s) {
    map["zero"] = 0;
    map["one"]=1;
    map["two"]=2;
    map["three"]=3;
    map["four"]=4;
    map["five"]=5;
    map["six"]=6;
    map["seven"]=7;
    map["eight"]=8;
    map["nine"]=9;
    int answer = 0;
    
    string tmp="";
    for (int i = 0; i<s.size(); i++){
        if (s[i]>='0'&&s[i]<='9'){
            answer = answer*10;
            answer+=s[i]-'0';
        }
        
        else{
            tmp+=s[i];
            if (map.count(tmp)){
                answer = answer*10;
                answer+=map[tmp];
                tmp="";
            }
        }
    }
    return answer;
}
