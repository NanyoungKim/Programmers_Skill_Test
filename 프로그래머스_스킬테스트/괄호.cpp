#include<string>
#include <iostream>
#include <stack>
using namespace std;

bool solution(string s)
{
	bool answer = true;
	int cnt = 100000;
	stack<int> stk;

	int strLen = s.length();

	char* str = &s[0];

	for (int i = 0; i < strLen; i++) {

		if (stk.size() != 0) {
			if (str[i] == '(') {
				stk.push(1);
			}
			else {
				stk.pop();
			}
		}
		else {
			return false;
		}

		


		
	}

	



	return answer;
}


int main() {

	string s = "(()()";

	cout << solution(s);

	return 0;
}