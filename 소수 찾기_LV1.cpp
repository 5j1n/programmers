#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int>v(n+1,1);

    for (int i = 2; i <= n; i++) {
        if (v[i]) {
            answer++;
            int cnt = 2;
            while (i * cnt <= n) {
                v[i * cnt] = 0;
                cnt++;
            }
        }
    }
    return answer;
}

int main() {
    int n;
    cin >> n;
    cout<<solution(n);
}
