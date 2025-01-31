#include <iostream>
#include <string>
#include <set>
#include <vector>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    multiset<int>set;

    for (int i = 0; i < operations.size(); i++) {
        if (operations[i][0] == 'I') {
            operations[i].erase(0, 2);
            set.insert(stoi(operations[i]));
        }

        else {
            if (!set.empty()) {
                if (operations[i][2] == '1') {
                    auto it = set.end();
                    it--;
                    set.erase(it);
                }
                else
                    set.erase(set.begin());
            }
        }
    }

    if (set.empty()) {
        answer.push_back(0);
        answer.push_back(0);
    }
    else {
        auto it = set.end();
        it--;
        answer.push_back(*it);
        answer.push_back(*set.begin());
    }
    return answer;
}
