#include <string>
#include <vector>
#include <iostream>
using namespace std;

int dist[101][101];
int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            dist[i][j] = -1;

    for (int i = 0; i < puddles.size(); i++) {
        dist[puddles[i][1]][puddles[i][0]] = 0;
    }
    dist[1][1] = 1;
    for (int i = 1; i <= n; i++) {
        if (dist[i][1] == 0)
            break;
        dist[i][1] = 1;
    }

    for (int i = 1; i <= m; i++)
    {
        if (dist[1][i] == 0)
            break;
        dist[1][i] = 1;
    }
   
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (dist[i][j] == -1) {
                dist[i][j] = 0;
                if (i - 1 >= 1) dist[i][j] += dist[i - 1][j] % 1000000007;
                if (j - 1 >= 1) dist[i][j] += dist[i][j - 1] % 1000000007;
                dist[i][j] = dist[i][j] % 1000000007;
            }
    answer = dist[n][m];
    return answer;
}

int main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);
    int m = 4;
    int n = 3;
    vector<vector<int>>puddles = { {2,2} };
    cout << solution(m, n, puddles) << "\n";
}
