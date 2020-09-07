#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool chk(string name) {
	char * str = &name[0];
	bool res = true;

	for (int i = 0; i < name.length(); i++) {
		if (name[0] != 'A') {
			res = false;
		}
	}
	return res;
}

int solution(string name) {
	int answer = 0;
	int right = 0;
	int left = 0;
	int minNum = 0;
	int strLen = name.length();

	char * str = &name[0];
	
	
	if (chk(name)) return 0;

	right = str[0] - 'A';
	left = 'Z' + 1 - str[0];

	answer = min(right, left);

	if (str[1] == 'A') {
		
		for (int i = strLen - 1; i > 1; i--) {

		
			
			right = str[i] - 'A';
			left = 'Z' + 1 - str[i];

			answer += min(right, left);
			
		}
		answer += strLen - 2;

	}
	else {
		for (int i = 1; i < strLen; i++) {

			right = str[i] - 'A';
			left = 'Z' + 1 - str[i];

			answer += min(right, left);
			
		}
		answer += strLen - 1;
	}


	return answer;
}

int main() {

	string name = "AAAA";
	cout << solution(name);

	return 0;

}