#include <string>
#include <vector>
#include <iostream>


using namespace std;




int solution(int m, int n, vector<vector<int>> puddles) {
	int answer = 0;
	//memset(map, 0, sizeof(map));



	//int dp[101][101];
	//int map[101][101] = { 0, };

	int **dp, **map;
	dp = new int*[n];
	map = new int*[n];

	for (int i = 0; i <= n; i++) {
		dp[i] = new int[m];
		map[i] = new int[m];
		memset(dp[i], 0, sizeof(int)*m);
		memset(map[i], 0, sizeof(int)*m);
	}


	//물 웅덩이 -100으로 표시
	for (auto v : puddles) map[v[1]][v[0]] = -100;




	//초기셋팅
	dp[1][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {

			if (map[i][j] == -100) {
				dp[i][j] = 0;
			}
			else {
				dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 1000000007;
			}
			//cout << dp[i][j] << " ";
		}
		//	cout << endl;
	}







	return  dp[n][m];
}

int main() {

	//memset(dp, 0, sizeof(dp));
	
	
	int m = 4, n = 3;
	vector<vector<int>> v = { {2,2} };

	//cout << v.size() << endl;
	//cout << v[0].size() << endl;
	//cout << v[0][0] << " " << v[0][1] << endl;




	cout << solution(m, n, v);
}