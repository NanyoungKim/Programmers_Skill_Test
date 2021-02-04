#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<char> cVec;
vector<string> listVec;
vector<char> alphaVec;

int visited[26] = { 0 };

void dfs(int toPick) {

	if (toPick == 0) {
		string str = "";
		for (int k = 0; k < cVec.size(); k++) {
			str.push_back(cVec[k]);
		}
		listVec.push_back(str);
		return;
	}


	for (int i = 0; i < alphaVec.size(); i++) {

		if (visited[i] == 0) {
			visited[i] = 1;
			cVec.push_back(alphaVec[i]);
			dfs(toPick - 1);
			cVec.pop_back();
			visited[i] = 0;

		}
	}

}

vector<string> solution(vector<string> orders, vector<int> course) {
	vector<string> answer;

	for (int i = 0; i < orders.size(); i++) {
		for (int j = 0; j < orders[i].length(); j++) {

			if (find(alphaVec.begin(), alphaVec.end(), orders[i][j]) == alphaVec.end()) {//¾øÀ¸¸é
				alphaVec.push_back(orders[i][j]);

			}
		}
	}
	sort(alphaVec.begin(), alphaVec.end());

	for (int i = 0; i < course.size(); i++) {

		for (int j = 0; j < 26; j++) { visited[j] = 0; }

		dfs(course[i]);
		cVec.clear();
	}


	for (int i = 0; i < listVec.size(); i++) {

	}



	
	return answer;
}



int main() {

	vector<string> ord = { "ABCFG","AC","CDE","ACDE","BCFG","ACDEH" };
	vector<int> course = { 2,3,4 };

	vector<string> ans =  solution(ord, course);

	return 0;
}