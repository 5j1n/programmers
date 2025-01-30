#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int n;

bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(), phone_book.end());
    for (int i = 0; i < phone_book.size()-1; i++) {
            string tmp = phone_book[i];
            string target = phone_book[i+1].substr(0, tmp.length());
         //   cout << tmp << " " << target << "\n";
 
            if (tmp == target) {
                answer = false;
                break;
            }
    }
    return answer;
}

int main() {
    cin >> n;
    vector<string> phone_book(n);
    for (int i = 0; i < n; i++)
        cin >> phone_book[i];
    cout << solution(phone_book);
}
