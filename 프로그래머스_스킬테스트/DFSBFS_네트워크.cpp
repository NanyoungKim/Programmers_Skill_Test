#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int N = 0;
int ans = 0;
bool chkGroup = false;

int res = 0;
int Min;
vector<int> resVec;

void dfs(vector<vector<int>> computers, int cnt, int row, int col, int ans) {


	
	if (cnt==(N-1)) {
	
		resVec.push_back(ans);
		return;
	}

	if (count(computers[row].begin(), computers[row].end(), 1) == 1) {	//자기자신만 1이면 바로 다음줄로
		ans++;
		chkGroup = false;
		dfs(computers, cnt+1, row + 1, 0, ans);
	}




	if (col > N - 1) {
		
		
			chkGroup = false;
			dfs(computers, cnt, row + 1, 0, ans);
		
		

		
	}


	if (row != col) {
		if (computers[row][col] == 1 ) {


			if (chkGroup == false) ans++;

			chkGroup = true;
			dfs(computers, cnt + 1, col, row + 1,ans);
		}
		else {
			dfs(computers, cnt, row, col + 1, ans);
		}
	}
	else {		//자기자신은 그냥 한칸 오른쪽으로 이동
		dfs(computers, cnt, row, col + 1, ans);
	}


}




int solution(int n, vector<vector<int>> computers) {
	int answer = 0;

	N = n;
	Min = n;
	dfs(computers, 1, 0, 0,0);

	sort(resVec.begin(), resVec.end());

	answer = resVec[0];
	cout << "answer : " << answer << endl;

	return answer;
}


int main() {

	int n = 6;
	vector<vector<int>> computers = { {1,1,1,0,0,0}, {1,1,1,0,0,0}, {1,1,1,0,0,0}, {0,0,0,1,0,0}, {0,0,0,0,1,1}, {0,0,0,0,1,1} };
	cout << solution(n, computers);

	return 0;
}
