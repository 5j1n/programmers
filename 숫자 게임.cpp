    #include <iostream>
    #include <string>
    #include <vector>
    #include <algorithm>
    using namespace std;

    int solution(vector<int> A, vector<int> B) {
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        int i = 0, j = 0;
        int answer = 0;
        while (i < A.size() && j < A.size()) {
            if (A[i] < B[j]) {
                answer++;
                //cout << A[i] << " " << B[j] << "\n";
                i++;
            }
            j++;
        }
        return answer;
    }

    int main() {
        vector<int>A = { 5,1,3,7};
        vector<int>B = { 2,2,6,8 };
        solution(A, B);
    }
