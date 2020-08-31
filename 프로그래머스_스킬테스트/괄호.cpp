#include<string>
#include <iostream>
#include <stack>
using namespace std;

bool solution(string s)
{
	bool answer = true;
	int cnt = 100000;
	stack<char> stk;

	int strLen = s.length();

	char* str = &s[0];

	for (int i = 0; i < strLen; i++) {


		if (str[i] == '(') {
			stk.push('(');

		}
		else {

			if (stk.size() == 0) {
				return false;
			}
			else {
				if (stk.top() == '(') {
					stk.pop();
				}
				else {
					stk.push(')');
				}
			}

		}
	}



	if (stk.size() == 0) {
		answer = true;
	}

	else {
		answer = false;
	}




	return answer;
}


int main() {

	string s = "(())()";

	cout << solution(s);

	return 0;
}