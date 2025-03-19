#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int answer = 0;
int sz = 0, user_sz = 0;
unordered_set<string>line_up, history;
vector<bool>id(9);
vector<string>user;
unordered_set<string>set[9];
void tracking(int size, int idx){
    if (size==sz){
        string tmp = "";
        id.assign(user_sz,false);
        for (auto it = line_up.begin(); it!=line_up.end(); it++){
            for (int i = 0; i<id.size(); i++){
                if (user[i]==*it){
                    id[i] = 1;
                }
            }
        }
        for (int i = 0; i<id.size(); i++){
            tmp+=(id[i]+'0');
        }
        if (line_up.size()==sz && !history.count(tmp)) {
            answer++;
            history.insert(tmp);
        }
        return;
    }
    
    for (auto it = set[idx].begin(); it!=set[idx].end(); it++){
        if (!line_up.count(*it)){
            line_up.insert(*it);
            tracking(size+1,idx+1);
            line_up.erase(*it);
        }
    }
    return;
}
int solution(vector<string> user_id, vector<string> banned_id) {
    sz = banned_id.size();
    user_sz = user_id.size();
    user = user_id;
    for (int i = 0; i < user_id.size(); i++) {
        for (int j = 0; j < banned_id.size(); j++) {
            set[j].insert(user_id[i]);
        }
    }
    for (int i = 0; i < banned_id.size(); i++) {
        string str = banned_id[i];
        unordered_set<string>tmp = set[i];
        for (int j = 0; j < str.size(); j++) {
            if (str[j] != '*') {
                for (auto it = set[i].begin(); it != set[i].end(); it++) {
                    string tmp_str = *it;
                    if (tmp_str[j] != str[j] && tmp.count(tmp_str)) {
                        tmp.erase(tmp_str);
                    }
                }
            }
        }
        for (auto it = set[i].begin(); it != set[i].end(); it++) {
                    string tmp_str = *it;
                    if (tmp_str.size()!=str.size() && tmp.count(tmp_str)) {
                        tmp.erase(tmp_str);
                    }
        }
        set[i] = tmp;
        for (auto it = tmp.begin(); it!=tmp.end(); it++){
        }
    }
    tracking(0,0);
    return answer;
}
