#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int N = 0;
int *checked;

void dfs(vector<vector<int>> computers,int start,  int n) {

	checked[start] = 0;	//방문했음을 표시

	for (int i = 0; i < n; i++) {			//i는 col 을 의미

		if (checked[i] == 1 && computers[start][i] == 1) {	//방문 안한 컴퓨터인데 연결됐으면
			dfs(computers, i, n);							//그 컴퓨터랑 연결된 컴퓨터 바로 탐색 : col 이 row 로 감
		}
	}

}



int solution(int n, vector<vector<int>> computers) {
	int answer = 0;

	N = n;
	checked = new int[n];

	for (int i = 0; i < n; i++) {
		checked[i] = 1;					//방문 안 된곳은 1로 표시
	}

	for (int i = 0; i < n; i++) {

		if (checked[i] == 0) {	//이미 방문했으면
			continue;
		}
		else {
			answer++;
			dfs(computers, i, n);			//i는 row를 의미  
		}

	}

	return answer;
}


int main() {

	int n = 6;
	vector<vector<int>> computers = { {1,1,1,0,0,0}, {1,1,1,0,0,0}, {1,1,1,0,0,0}, {0,0,0,1,0,0}, {0,0,0,0,1,1}, {0,0,0,0,1,1} };
	cout << solution(n, computers);

	return 0;
}
