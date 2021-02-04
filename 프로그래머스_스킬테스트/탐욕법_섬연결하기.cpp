#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


bool cmp(const vector<int> &a, const vector<int> &b) {
	return a[2] < b[2];
}

int findParent(int p[], int idx) {

	if (idx == p[idx]) { return p[idx]; }
	else {
		return p[idx] = findParent(p, p[idx]);
	}

}





int solution(int n, vector<vector<int>> costs) {
	int answer = 0;
	int size = costs.size();

	int *visited = new int[n];
	int *parent = new int[n];
	for (int i = 0; i < n; i++) visited[i] = 0;
	for (int i = 0; i < n; i++) parent[i] = i;

	sort(costs.begin(), costs.end(), cmp);


	int cnt = 0;
	for (int i = 0; i < size; i++) {

		if (cnt == n) break;

		int n1 = costs[i][0];
		int n2 = costs[i][1];

		for (int i = 0; i < n; i++) cout << parent[i] << " ";
		cout << endl;

		int tmp = 0;
		if (n1 > n2) {
			tmp = n1;
			n1 = n2;
			n2 = tmp;
		}


		cout << n1 << " " << n2 << endl;
		cout << "parent : " << findParent(parent, n1) << " " << findParent(parent, n2) << endl;
		if (findParent(parent, n1) != findParent(parent, n2)) {//같은 그룹 아니어야 조인

			answer += costs[i][2];
			
			if (visited[n1] == 0) cnt += 1; visited[n1] = 1;
			if (visited[n2] == 0) cnt += 1; visited[n2] = 1;

			parent[n2] = n1;

		}


	}




	return answer;
}

int main() {

	int n = 4;

	//vector<vector<int>> costs = { {0, 1, 1},{0, 2, 2},{1, 2, 5},{1, 3, 1},{2, 3, 8} };
	vector<vector<int>> costs = { {0, 1, 5},{1, 2, 3},{2, 3, 3},{3, 1, 2},{3, 0, 4} };
	cout << solution(n, costs);
	return 0;
}

