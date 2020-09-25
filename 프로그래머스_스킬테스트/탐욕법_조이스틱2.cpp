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
	


	if (name.find('A') != string::npos) {		//A�� ������

		int start = name.find_first_of('A');
		int last = name.find_last_of('A');

		for (int i = 0; i < start; i++) {

			int num = JoyStick(name[i]);	//�ش��ڸ� ���ĺ� ����� 
			
			answer += num;
			answer++;	//���������� �̵��� �� 

		}
		answer += start;
		for (int i = name.length()-1; i>last; i--) {
			
			answer += JoyStick(name[i]);
			answer++;	//�������� �� �� 


		}

		answer -= 1;	//�������� ���� ���� ���ֱ�

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
