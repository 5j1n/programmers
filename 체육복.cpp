#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	int ans = 0;
	int stu[31];
	stu[0] = 0;
	for (int i = 0; i <= n; i++)
		stu[i] = 1;

	for (int i = 0; i < lost.size(); i++)
		stu[lost[i]]--;

	for (int j = 0; j < reserve.size(); j++)
		stu[reserve[j]]++;

	for (int i = 1; i <= n; i++) {
		if (!stu[i]) {
			if (stu[i - 1] > 1) {
				stu[i]++;
				stu[i - 1]--;
			}
			else if (i + 1 <= n && stu[i + 1] > 1) {
				stu[i]++;
				stu[i + 1]--;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (stu[i] > 0) ans++;
	}
	return ans;
}
