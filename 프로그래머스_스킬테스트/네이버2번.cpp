#include <iostream>
#include <string>


using namespace std;


string solution(string &S) {
	// write your code in C++14 (g++ 6.2.0)

	int start;
	bool chk = false;

	do {

		if (S.length() == 0) {
			return "";
		}

		if ((start = S.find("AA")) != string::npos) {		//¿÷¿Ω
			S.erase(start, 2);
			chk = true;

		}
		else if ((start = S.find("BB")) != string::npos) {
			S.erase(start, 2);
			chk = true;
		}
		else if ((start = S.find("CC")) != string::npos) {
			S.erase(start, 2);
			chk = true;
		}
		else {
			chk = false;
		}
	} while (chk==true);
	

	return S;

}


int main() {


	string s = "ABBCCBBB";
	cout << solution(s);

	return 0;
}