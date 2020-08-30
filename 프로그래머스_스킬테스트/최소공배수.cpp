#include <string>
#include <vector>
#include <iostream>

using namespace std;


int gcd (int a, int b) {
	int tmp = 0;
	int ans = 0;
	if (a >= b) {
		while (b != 0) {
			tmp = a % b;
			a = b;
			b = tmp;
		}
		return a;
	}
	else {
		while (a != 0) {
			tmp = b % a;
			b = a;
			a = tmp;
		}
		return b;
	}

}


int lcd(int a, int b) {
	
	return (a*b) / gcd(a, b);
}

int solution(vector<int> arr) {
	int answer = 0;
	int lcdNum = arr[0];
	

	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < arr.size(); j++) {

			if (i == j) continue;


			

			lcdNum = lcd(lcdNum, arr[j]);

		}
	}


	answer = lcdNum;
	return answer;
}




int main() {

	vector<int> arrr = { 2,6,8,14 };
	cout << solution(arrr);

	return 0;
}