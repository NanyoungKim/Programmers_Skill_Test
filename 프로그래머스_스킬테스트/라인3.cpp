#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int cnt = 10000000;
vector<int> cntVec;
int ressum = 2000000000;

int rescnt = 1000000;

void recurFunc(int n, int cnt) {
	
	
	
	if (n < 10) {

		if (rescnt > cnt) {
			ressum = n;
			rescnt = cnt;
		}
		

		return;
	}


	for (int i = 0; i < to_string(n).length()-1; i++) {

		string s = to_string(n);
		
		int first = stoi(s.substr(0, i + 1));
		int second = stoi(s.substr(i + 1, s.length() - 1));
		n = first + second;
		//cout << n << " ";

		recurFunc(n, cnt + 1);
	}



}



vector<int> solution(int n) {
	vector<int> answer;

	 recurFunc(n, 0);


	//sort(cntVec.begin(), cntVec.end());

	answer.push_back(rescnt);
	answer.push_back(ressum);








	return answer;
}



int main() {

	
	int n = 73425;
	vector<int> res = solution(n);



	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	}

	return 0;
}