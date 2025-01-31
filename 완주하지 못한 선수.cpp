// #include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<string, int>map;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    for (int i = 0; i < participant.size(); i++)
        map[participant[i]]++;

    for (int i = 0; i < completion.size(); i++)
        map[completion[i]]--;

    for (auto i = map.begin(); i != map.end(); i++)
    {
        if (i->second > 0)
        {
            answer = i->first;
            break;
        }
    }
    return answer;
}

// int main() {
//     vector<string>participant = { "leo", "kiki", "eden" };
//     vector<string>completion = { "eden", "kiki" };

//     cout << solution(participant, completion);
// }
