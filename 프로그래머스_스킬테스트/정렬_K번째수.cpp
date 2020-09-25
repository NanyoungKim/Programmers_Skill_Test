#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;


vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;
	int start, last;
	

	priority_queue<int, vector<int>, greater<int>> pq;
	

	for (int i = 0; i < commands.size(); i++) {

		int cnt = 0;
	


		start = commands[i][0] - 1;
		last = commands[i][1] - 1;

		for (int j = start; j <= last; j++) {
			pq.push(array[j]);
		}


		while (!pq.empty()) {
		

			if (cnt+1 == commands[i][2]) {

				//cout << "top: " << pq.top() << endl;
				answer.push_back(pq.top());
				break;
			}
			else {
				pq.pop();
			}
			cnt += 1;

		}


		while (!pq.empty()) {	//ÃÊ±âÈ­
			pq.pop();
		}

		


	}

	return answer;
}


int main() {

	vector<int> array = { 1,5,2,6,3,7,4 };
	vector<vector<int>> _commands = { {2,5,3}, {4,4,1}, {1,7,3} };
	
	vector<int> res = solution(array, _commands);



	for (int i = 0; i < res.size(); i++) {
		cout << i << " : " << res[i] << endl;
	}

	return 0;
}

