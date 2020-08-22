#include <string>
#include <vector>
#include <iostream>


using namespace std;



string solution(string s, int n) {
	string answer = "";

	for (int i = 0; i < s.size(); i++) {

		
		
		if (islower(s[i])) {		

			if (s[i] + n > 122) {
				s[i] +=  n - 26;
			}
			else {
				s[i] = s[i] + n;
			}


		}

		else if (isupper(s[i])) {	

			if (s[i] + n > 90) {
				s[i] +=  n - 26;
			}
			else {
				s[i] = s[i] + n;
			}

		}
		
		else if (s[i] == ' ') {
			s[i] = ' ';
		}
		


		
		answer += s[i];


	}


	return answer;
}



int main() {

	cout << solution("wz", 5) << endl;



	return 0;
}