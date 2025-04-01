#include <string>
#include <vector>

using namespace std;

vector<int>num1 = {1,2,3,4,5};
vector<int>num2 = {2,1,2,3,2,4,2,5};
vector<int>num3 = {3,3,1,1,2,2,4,4,5,5};
int sc1, sc2, sc3, maxi;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    for (int i = 0; i<answers.size(); i++){
        if (answers[i] == num1[i%num1.size()]) sc1++;
        if (answers[i] == num2[i%num2.size()]) sc2++;
        if (answers[i] == num3[i%num3.size()]) sc3++;
    }
    maxi = max(sc1, max(sc2,sc3));
    if (maxi==sc1) answer.push_back(1);
    if (maxi==sc2) answer.push_back(2);
    if (maxi==sc3) answer.push_back(3);
    return answer;
}
