#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int N = 0;
int *checked;

void dfs(vector<vector<int>> computers,int start,  int n) {

	checked[start] = 0;	//�湮������ ǥ��

	for (int i = 0; i < n; i++) {			//i�� col �� �ǹ�

		if (checked[i] == 1 && computers[start][i] == 1) {	//�湮 ���� ��ǻ���ε� ���������
			dfs(computers, i, n);							//�� ��ǻ�Ͷ� ����� ��ǻ�� �ٷ� Ž�� : col �� row �� ��
		}
	}

}



int solution(int n, vector<vector<int>> computers) {
	int answer = 0;

	N = n;
	checked = new int[n];

	for (int i = 0; i < n; i++) {
		checked[i] = 1;					//�湮 �� �Ȱ��� 1�� ǥ��
	}

	for (int i = 0; i < n; i++) {

		if (checked[i] == 0) {	//�̹� �湮������
			continue;
		}
		else {
			answer++;
			dfs(computers, i, n);			//i�� row�� �ǹ�  
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
