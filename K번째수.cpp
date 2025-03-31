#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for (int i = 0; i<commands.size(); i++){
        int st = commands[i][0];
        int en = commands[i][1];
        int idx = commands[i][2];
        vector<int>tmp;
        for (int i = st-1; i<en; i++){
            tmp.push_back(array[i]);
        }
        sort(tmp.begin(),tmp.end());
        answer.push_back(tmp[idx-1]);
    }
    return answer;
}
