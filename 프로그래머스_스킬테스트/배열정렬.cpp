#include <string>
#include <vector>
#include <algorithm>
#include<iostream>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;
	vector<int> newVec;

	for (int i = 0; i < commands.size(); i++) {
		
		int start = commands[i][0];
		int end = commands[i][1];
		int selectNum = commands[i][2];

		

		for (int j = start-1; j<=end-1; j++){
			newVec.push_back(array[j]);
		}
		sort(newVec.begin(), newVec.end());

		answer.push_back(newVec[selectNum - 1]);
		newVec.clear();


	}

	return answer;
}

int main() {

	vector<int> array = { 1,5,2,6,3,7,4 };
	vector<vector<int>> commands = { {2,5,3},{4,4,1}, {1,7,3} };
	
	vector<int> ans = solution(array, commands);

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}

	return 0;
}