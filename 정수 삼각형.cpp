#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int dp[501][501];
    for (int i = 1; i < triangle.size(); i++) {
        for (int j = 0; j < triangle[i].size(); j++) {
            dp[i][j] = 0;
        }
    }
    dp[0][0] = triangle[0][0];
    for (int i = 1; i < triangle.size(); i++) {
        for (int j = 0; j < triangle[i].size(); j++) {
            if (j == 0) {
                dp[i][j] = max(dp[i][j], triangle[i][j] + dp[i - 1][j]);
            }
            else if (j == triangle[i].size() - 1) {
                dp[i][j] = max(dp[i][j], triangle[i][j] + dp[i - 1][j-1]);
            }
            else dp[i][j] = max(dp[i][j], max(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j]);
        }
    }
    for (int i = 0; i < triangle[triangle.size() - 1].size(); i++)
        answer = max(answer, dp[triangle.size() - 1][i]);
    return answer;
}
