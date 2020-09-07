#include <string>
#include <vector>
#include <iostream>

using namespace std;

int gcd(int a, int b) {
	int tmp = 0;
	if (a <= b) {
		while (a != 0) {
			tmp = a;
			a = b % a;
			b = tmp;
		}
		return b;
	}
	else {
		while (b != 0) {
			tmp = b;
			b = a % b;
			a = tmp;
		}
		return a;
	}


}
int lcm(int a, int b) {
	return (a*b) / gcd(a, b);
}




int solution(vector<int> arr) {
	int answer = 0;
	int lcmNum = arr[0];
	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < arr.size(); j++) {

			if (i == j) continue;
		
			lcmNum = lcm(lcmNum, arr[j]);
			


		}
		answer = lcmNum;
		break;

	}

	return answer;
}

int main() {

	vector<int> vec = { 2,6,8,14 };
	cout << solution(vec);

	return 0;

}