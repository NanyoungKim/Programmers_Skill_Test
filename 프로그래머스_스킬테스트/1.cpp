//#include <bits/stdc++.h>
#include<queue>
#include<utility>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);


/*
 * Complete the 'minCost' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER rows
 *  2. INTEGER cols
 *  3. INTEGER initR
 *  4. INTEGER initC
 *  5. INTEGER finalR
 *  6. INTEGER finalC
 *  7. INTEGER_ARRAY costRows
 *  8. INTEGER_ARRAY costCols
 */

 //int map[100000][100000]={0};
 //int visited[100000][100000] = {0};

int **fromStart;

int R, C;
//위, 오, 아, 왼
int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, 1, 0, -1 };

queue<pair<int, int>> que;

int Bfs(int finalR, int finalC, vector<int> costRows, vector<int> costCols) {

	int res = 0;

	while (!que.empty()) {

		int r = que.front().first;
		int c = que.front().second;
		que.pop();

		if (r == finalR && c == finalC) {
			res = fromStart[r][c];
			break;
		}


		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];

			if (nr >= R || nr < 0 || nc >= C || nc < 0) continue;


			int cost = 0;
			if (i == 0) { cost = fromStart[r][c] + costRows[nr]; }
			else if (i == 1) { cost = fromStart[r][c] + costCols[c]; }
			else if (i == 2) { cost = fromStart[r][c] + costRows[r]; }
			else { cost = fromStart[r][c] + costCols[nc]; }

			if (fromStart[nr][nc] == 0) {
				if (fromStart[nr][nc] > cost) {
					fromStart[nr][nc] = cost;   //더 작은걸로 갱신

					que.push(make_pair(nr, nc));
				}
			}



		}

	}




	return res;
}

int minCost(int rows, int cols, int initR, int initC, int finalR, int finalC, vector<int> costRows, vector<int> costCols) {

	R = rows; C = cols;

	//visited[initR][initC] = 1;
	//fromStart[initR][initC] = 0;

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			fromStart[i][j] = 0;
		}
	}

	que.push(make_pair(initR, initC));
	int ans = Bfs(finalR, finalC, costRows, costCols);

	return ans;

}
int main() {




	return 0;
}