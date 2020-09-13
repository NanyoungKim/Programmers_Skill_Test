#include <iostream>
#include <vector>

using namespace std;


vector<int> solution(vector<int> &A, int K) {
	// write your code in C++14 (g++ 6.2.0)


	if (A.size() == 0) {
		return A;
	}


	for (int i = 0; i < K; i++) {

		int tmp = A.back();

		for (int j = A.size()-1; j > 0 ; j--) {
			A[j] = A[j-1];
		}
		A[0] = tmp;


		for (int i = 0; i < A.size(); i++) {
		//	cout << A[i] << " ";
		}
		//cout << endl;
	}


	return A;

}




int main() {

	vector<int> arr = { };

	int K = 4;
	vector<int> res = solution(arr, K);


	for (int i = 0; i < res.size(); i++) {
	//	cout << res[i] << " ";
	}

	return 0;
}