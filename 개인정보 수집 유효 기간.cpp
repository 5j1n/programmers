#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <string>
#include <cstring>

using namespace std;

struct date{
    int year = 0;
    int month = 0;
    int day = 0;
};

date now;
unordered_map<char,int>deadline;

void str2date(string today, date &d){
    int tmp = 0;
    for (int i = 0; i<today.size(); i++){
        if (today[i]=='.'){
            if (!d.year){
                d.year = tmp;
            }
            else if (!d.month){
                d.month = tmp;
            }
            tmp = 0;
        }
        else {
            tmp = 10*tmp;
            tmp +=today[i]-'0';
        }
        
        if (i==today.size()-1){
            d.day = tmp;
        }
    }
}
vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    int tmp = 0;
    str2date(today, now);
    for (int i = 0; i<terms.size(); i++){
        char tmp_char = terms[i][0];
        string month_str = "";
        for (int j = 2; j<terms[i].size(); j++){
            month_str.push_back(terms[i][j]);
        }
        int deadline_day = 28 * stoi(month_str);
        deadline[tmp_char] = deadline_day;
    }
    vector<int> answer;
    int today_int = now.year*12*28 + now.month*28 + now.day;
    for (int i = 0; i<privacies.size(); i++){
        date tmp;
        string str = privacies[i].substr(0,10);
        str2date(str,tmp);
        int tmp_int  = tmp.year*12*28 + tmp.month*28 + tmp.day;
        if (today_int - tmp_int >= deadline[privacies[i][privacies[i].size()-1]]){
            answer.push_back(i+1);
        }
    }
    return answer;
}
