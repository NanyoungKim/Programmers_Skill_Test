#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> ball, vector<int> order) {
	vector<int> answer;

	vector<int> priorVec;
	bool chk = true;

	int size = order.size();

	for (int i = 0; i < order.size(); i++) {

		//prior 먼저 있나 검사
		if (priorVec.size() != 0) {

			do {
				for (int j = 0; j < priorVec.size(); j++) {

					if (priorVec[j] == ball.front()) {
						answer.push_back(ball.front());
						priorVec.erase(priorVec.begin() + j);
						ball.erase(ball.begin());

						j--;
						chk = false;
					}
					else if (priorVec[j] == ball.back()) {
						answer.push_back(ball.back());
						priorVec.erase(priorVec.begin() + j);
						ball.pop_back();
						chk = false;


						j--;
					}
					else {
						chk = true;
					
					}
				}

			} while ((chk == false) && priorVec.size() != 0);


		}

	





		//명령따르기
		if (order[i] == ball.front()) {
			answer.push_back(order[i]);
			//order.erase(order.begin() + i);
			ball.erase(ball.begin());
			
			//i = i - 1;
		}
			
		else if (order[i] == ball.back()) {
			answer.push_back(order[i]);
			//order.erase(order.begin() + i);
			ball.pop_back();
			

			//i = i - 1;
		}

		else {
			priorVec.push_back(order[i]);
		}







			
	}











	return answer;
}



int main() {

	vector<int> ball = { 1,2,3,4,5,6 };
	vector<int> order = { 6,2,5,1,4,3 };
	vector<int> res = solution(ball, order);

	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	}

	return 0;
}