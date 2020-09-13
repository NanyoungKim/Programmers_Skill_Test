#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> colSum;
vector<int> rowSum;
int N, M;

bool chkRange(int i, int j) {

	if (1 <= i && i <= N - 1 && 1 <= j && j <= M - 1) {
		return true;
	}

	else {
		return false;
	}
}


bool chkSum(int i, int j){
	
	if (!chkRange(i,j)){


		int chkbelow = 0;
		int chkabove = 0;
		for (int i = 1; i < N; i++) {
			chkbelow += rowSum[i];
		}
		for (int i = 0; i < N - 1; i++) {
			chkabove += rowSum[i];
		}
			if (i == 0 && j == 0) {
				if (colSum[1] == 0 && chkbelow == 0) {
					return true;
				}
				else {
					return false;
				}
			} 
			else if (i == 0 && j == M-1) {
				if (colSum[M - 2] == 0 && chkbelow == 0) {
					return true;
				}
				else {
					return false;
				}
			}
			else if (i == N-1 && j == 0) {
				if (colSum[1] == 0 && chkabove == 0) {
					return true;
				}
				else {
					return false;
				}
			}
			else if (i == N - 1 && j == M - 1) {
				if (colSum[M - 2] == 0 && chkabove == 0) {
					return true;
				}
				else {
					return false;
				}
			}


	}
	else {
		if (colSum[j - 1] != colSum[j + 1]) {		//컬럼 양쪽 비교해서 다르면 
			return false;
		}
		else {		//컬럼 양쪽 일단 같고 

			int above = 0;
			int below = 0;

			for (int p = 0; p < i; p++) {
				above += rowSum[p];
			}
			for (int q = i + 1; q < rowSum.size(); q++) {
				below += rowSum[q];
			}

			return above == below ? true : false;	//열의 위 아래 합도 같으면 트루
		}
	}






	
}



int solution(vector< vector<int> > &A) {
	// write your code in C++14 (g++ 6.2.0)

	 
	int cnt = 0;

	
	for (int i = 0; i < A[0].size(); i++) {	//열 3
		int col = 0;
		for (int j = 0; j < A.size(); j++) {//행 5
			col += A[j][i];
			colSum.push_back(col);
		}
	}

	for (int i = 0; i < A.size(); i++) { //행 5
		int row = 0;
		for (int j = 0; j < A[0].size(); j++) { //열 3
			row += A[i][j];
			rowSum.push_back(row);
		}
	}


	for (int i = 0; i < A.size(); i++) {
		for (int j = 0; j < A[0].size(); j++) {

			if (chkSum(i,j)) {
				cout << i << " " << j << endl;
				cnt++;
			}
		}
	}

	return cnt;


}


int main() {

	vector < vector<int>> vec = { {2,7,5},{3,1,1}, {2,1,-7}, {0,2,1}, {1,6,8} };

	N = vec.size();			//5
	M = vec[0].size();		//3

	cout << solution(vec);

	return 0;
}