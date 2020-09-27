#include <string>
#include <vector>
#include <iostream>

using namespace std;

int com[50][50] = { 0, };
int arr[50][50] = { 0, };
int childCnt[50] = { 0, };

vector<int> findChild(int n, vector<vector<int>> edg) {

	vector<int> vec;
	int resArr[19] = { 0, };
	int r = 0;




	int temp = edg[0][0];
	for (int i = 0; i < edg.size(); i++) {
		int j = 0;
		if (edg[i][0] == temp) {           //자식들 넣음

			if (j == 0) { r++; }        //r = 9
			arr[i][j] = edg[i][1];
			j++;

		}
	}

	// 바로 아래 연결된 자식의 수만 세기
	for (int i = 0; i < r; i++) {

		for (int j = 0; j < 50; j++) {

			int child = 0;
			if (arr[i][j] != 0) {
				child++;
			}
			else {
				childCnt[i] = child;
				break;
			}
		}

	}




	//해당 노드에 연결된 모든 자식 수 저장 : resArr
	for (int i = r - 1; i >= 0; i--) {         //i는 8부터 0까지

		for (int j = 0; j < childCnt[i]; j++) {

			resArr[i] += resArr[arr[i][j]];
			cout << resArr[i] << endl;
		}
	}


	for (int i = 0; i < r; i++) {

		vector<int> mVec;
		vector<int> mVec2;

		for (int j = 0; j < childCnt[i]; j++) {


		}
	}


}


int solution(int n, vector<vector<int>> edges) {
	int answer = 0;

	findChild(n, edges);





	return answer;
}