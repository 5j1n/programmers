#include <iostream>
#include <stack>

using namespace std;

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
bool solution(string s) {
	bool answer = true;
	stack<char>stack;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') {
			stack.push('(');
		}
		else {
			if (!stack.empty()) {
				stack.pop();
			}
			else return false;
		}
	}

	if (!stack.empty()) return false;
	return answer;
}
