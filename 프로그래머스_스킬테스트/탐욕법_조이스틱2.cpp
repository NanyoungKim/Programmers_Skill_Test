#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int visit[20] = { 1 };

int JoyStick(char alpha) {

	if ('Z' - alpha >= 13) return alpha - 'A';
	else return 'Z' - alpha +1;

}


int solution(string name) {
	
	int answer = -1;
	


	if (name.find('A') != string::npos) {		//A가 있으면

		int start = name.find_first_of('A');
		int last = name.find_last_of('A');

		for (int i = 0; i < start; i++) {

			int num = JoyStick(name[i]);	//해당자리 알파벳 만들고 
			
			answer += num;
			answer++;	//오른쪽으로 이동한 것 

		}
		answer += start;
		for (int i = name.length()-1; i>last; i--) {
			
			answer += JoyStick(name[i]);
			answer++;	//왼쪽으로 간 것 


		}

		answer -= 1;	//마지막에 왼쪽 간거 빼주기

	}
	else {

		for (int i = 0; i < name.length(); i++) {

			answer += JoyStick(name[i]);
			answer++;

		}

	}


	if (answer < 0) {
		answer = 0;
	}
	return answer;
}


int main() {

	string name = "BABA";

	

	cout << solution(name);

	return 0;

}
