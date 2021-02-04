
#include <iostream>
#include <string>
#include <vector>


using namespace std;

string solution(string new_id) {
	string answer = new_id;
	//1
	for (int i = 0; i < answer.length(); i++) {
		answer[i] = tolower(answer[i]);
	}
	cout << answer << "\n";

	//2
	for (int i = 0; i < answer.length(); i++) {
		printf("%c : %d\n", answer[i], answer[i]);
		if ((97 <= answer[i] && answer[i] <= 122) || (48 <= answer[i] && answer[i] <= 57) || answer[i] == '-' || answer[i] == '_' || answer[i] == '.') { continue; }
		else {
			answer.erase(i, 1); --i;
		}
		cout <<i << ": " <<  answer << "\n";
	}
	cout << answer << "\n";

	//3
	for (int i = 0; i < answer.length() - 1; i++) {
		if (answer[i] == '.' && answer[i + 1] == '.') {
			answer.erase(i, 1); --i;
		}
	}
	cout << answer << "\n";

	//4
	if (answer[0] == '.') answer.erase(0, 1);
	int l1 = answer.length();
	if (answer[l1 - 1] == '.') answer.erase(l1 - 1, 1);
	cout << answer << "\n";

	//5
	if (answer.length() == 0) { answer = "a"; }
	int l2 = answer.length();
	cout << answer << "\n";


	//6
	if (l2 >= 16) {
		answer.erase(15, l2 - 15);
		if (answer[answer.length() - 1] == '.') {
			answer.erase(answer.length() - 1, 1);
		}
	}cout << answer << "\n";

	//7

	int l3 = answer.length();
	if (l3 <= 2) {

		answer.append(3 - l3, answer[l3 - 1]);
	}
	cout << answer << "\n";



	return answer;
}

int main() {

	cout << solution("...!@BaT#*..y.abcdefghijklm");
	 //cout << solution("...@@@@@");
		
		

	return 0;
}