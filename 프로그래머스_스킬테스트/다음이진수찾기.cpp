#include <string>
#include <vector>
#include <iostream>

using namespace std;




int func(int k) {

	vector<int> str;
	int cnt = 0;
	while (k > 1) {

		if ((k % 2) == 0) {
			str.push_back(0);
			k = k / 2;
		}
		else {
			str.push_back(1);
			k = k / 2;
		}



	}
	
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == 1) {
			cnt++;
		}
	}

	return cnt;






}

int solution(int n) {
	int answer = 0;
	int chk = false;
	int originCnt = func(n);
	int nextCnt = 0;
	
	


	while (1) {

		nextCnt = func(++n);

		if (nextCnt == originCnt) {
			break;
		}




	}

	

	answer = n;







	return answer;
}


int main() {

	int n;
	cin >> n;
	cout << solution(n);


	return 0;
}