#include<iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(long long n) {
	long long answer = 0;
	bool chk = false;

	for (int i = 0; i < sqrt(50) * 1000000; i++) {
		if (i*i == n) {
			chk = true;
			answer = (i + 1)*(i + 1);
		}
		else
			continue;
	}

	if (chk == false) {
		answer = -1;
	}

	return answer;
}


int main() {


	long long n;
	cin >> n;

	cout << solution(n) << endl;


	return 0;
}