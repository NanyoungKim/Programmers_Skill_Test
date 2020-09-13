#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;




int solution(int X, vector<int> &A) {
	// write your code in C++14 (g++ 6.2.0)
	int cnt = 0;
	
	bool chk[100001];
	for (int i = 0; i < 100001; i++) {
		chk[i] = false;
	}


	bool cross = false;
	for (int i = 0; i < A.size(); i++) {

		
		if (chk[A[i]] == false) {
			chk[A[i]] = true;
			cnt++;

			cout << "cnt: " << cnt << " sec : " << i << endl;
		}
		if (cnt == X) {
			cross = true;
			return i;
		}
	}

	if (!cross) {
		return -1;
	}


}


int main() {
	int x = 5;
	vector<int> v = { 1,3,1,4,2,3,5,4 };
	cout << solution(x, v);

	return 0;
}


	