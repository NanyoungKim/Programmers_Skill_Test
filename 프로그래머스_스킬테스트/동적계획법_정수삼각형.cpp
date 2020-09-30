#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int findMax(int a, int b) {
	return a > b ? a : b;
}

int solution(vector<vector<int>> triangle) {
	int answer = 0;
	int size = triangle.size();

	vector<vector<int>> sumVec;
	vector<int> rowVec;

	int sum = triangle[0][0];
	sumVec.push_back(triangle[0]);
	rowVec.push_back(sum);


	rowVec.clear();
		for (int i = 1; i < triangle.size(); i++) {
			for (int j = 0; j < triangle[i].size(); j++) {

				if (j == 0) {
					rowVec.push_back(sumVec[i - 1][0] + triangle[i][0]);
				}
				else if (j == triangle[i].size() - 1) {
					rowVec.push_back(sumVec[i - 1][j - 1] + triangle[i][j]);
				}
				else {

					rowVec.push_back(findMax(sumVec[i - 1][j - 1], sumVec[i - 1][j]) + triangle[i][j]);
				}


				

			}


			for (int k = 0; k < rowVec.size(); k++) {
				cout << rowVec[k] << " ";
			}
			cout << endl;

			sumVec.push_back(rowVec);
			rowVec.clear();


		}

	answer = *max_element(sumVec[size - 1].begin(), sumVec[size - 1].end());



	return answer;
}

int main() {





	vector<vector<int>> tri = { {7}, {3,8}, {8,1,0}, {2,7,4,4}, {4,5,2,6,5} };
	cout << solution(tri);

	return 0;
}