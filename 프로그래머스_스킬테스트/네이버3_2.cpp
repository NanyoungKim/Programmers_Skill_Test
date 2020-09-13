#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int solution(vector<int> &A) {
	// write your code in C++14 (g++ 6.2.0)

	vector<int> sumVec;

	sort(A.begin(), A.end());
	int sum = A[0];
	for (int i = 1; i < A.size(); i++) {

		sum += A[i];
		//cout << sum << endl;
		sumVec.push_back(sum);

	}

	int res = 0;
	for (int i = 0; i < sumVec.size(); i++) {
		//cout << sumVec[i];
		res += sumVec[i];
	}
	return res;
}


int main() {

	vector<int> v = { };

	cout << solution(v);

	return 0;
}