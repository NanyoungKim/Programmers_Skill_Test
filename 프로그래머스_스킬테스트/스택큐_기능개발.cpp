#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;
bool chk[100] = { 0, };

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	queue<int> que;
	queue<int> dayQue;
	float remain = 0.0;
	int day = 0;


	for (int i = 0; i < progresses.size(); i++) {

		remain = (100 - progresses[i]) % speeds[i];
		day = (100 - progresses[i]) / speeds[i];

		cout << day << " ";
		if (remain == 0.0) {
			dayQue.push(day);
		}
		else {
			dayQue.push(day + 1);
		}

	}


	int d = 0;
	while (!dayQue.empty()) {

		int cnt = 0;
		bool chk = false;
		d++;

		while (d >= dayQue.front()) {
			cnt++;
			dayQue.pop();
			chk = true;
			if (dayQue.empty()) {
				break;
			}
		}


		if(chk) answer.push_back(cnt);


	}




	return answer;
}


int main() {

	vector<int> progress = { 93,30,55 };
	vector<int> speeds = { 1,30,5 };



	vector<int> res = solution(progress, speeds);

	for (int i = 0; i < res.size(); i++) {
		cout << i << " : " <<  res[i] << endl;
	}

	return 0;
}


