#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<string> dict = { "A", "B", "C", "D", "E", "F", "G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z" };



string longestStr(string name){

	bool chk = false;
	for (int i = name.length(); i > 0 ; i--) {

		for (int j = 0; j < dict.size(); j++) {
			if (dict[j] == name) {
				chk = true;
				return name;
			}
				
		}
		if (!chk) {
			name = name.substr(0,i-1);
			continue;
			
		}


	}
	return name;

}




vector<int> solution(string msg) {
	vector<int> answer;

	char* str = &msg[0];

	int size = msg.length();
	int chkCnt = 0;
	string current = longestStr(msg);		//K
	//cout << "1 current is " << current << endl;

	int cnt = 0;


	int i = 0;
	string newCurrent;
	int curLen = 0;
	while ((size-2) > i) {

		
		
		if (find(dict.begin(), dict.end(), current) == dict.end()) {	//없으면 dict 백터에 추가

			//cout << "2 current is " << current << endl;
			dict.push_back(current);
			
			newCurrent = msg.substr(i);	
			current = longestStr(newCurrent);
			curLen = current.length();
			//cout << "curLen is " << curLen << endl;
			//cout << "3 current is " << current << endl;

			


		}
		else {			//이미 있으면 

			
			for (int j = 0; j < dict.size(); j++) {
				
				
				if (dict[j] == current) {
					answer.push_back(j+1);					//11(K), 1(A), 27(KA)
					//cout << j+1 << endl;
					//current.append(&str[i]);
					cnt = current.length();
					//cout << " cnt   " << cnt << endl;
					break;
				}
			}

			//current.append(str[++i]);
			
			
			char a = msg.at(++i + (cnt-1));
			//cout << "i = " << i << "a" <<a << endl;
			current.push_back(a);
			//cout << "4 current is " << current << endl;
			
		}

		
	}

	string s;
	s.push_back(msg.at(i + 1));
	for (int j = 0; j < dict.size(); j++) {


		if (dict[j] == s) {
			answer.push_back(j+1);					//11(K), 1(A), 27(KA)
			//cout << j << endl;
			//current.append(&str[i]);
			break;
		}
	}

	



	return answer;
}


int main() {

	string msg = "TOBEORNOTTOBEORTOBEORNOT";
	vector<int> res = solution(msg);

	



	/*for (int i = 0; i < res.size(); i++) {
		cout << "answer is " << res[i] << " ";
	}*/
	return 0;
}


//
//#include<iostream>
//using namespace std;
//
//int main() {
//
//	string str = "abcd";
//
//	char* ptr = &str[0];
//	string s = "b"
//
//	if (s = ptr.at(1)) {
//
//	}
//
//	return 0;
//}