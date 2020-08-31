#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int chkK(vector<int> vec, int k) {
	//모든 원소 수가 k이상이어야함
	//하나라도 작으면 재정비

	int cnt = 0;
	
	if (vec.size() == 1) {
		if (vec[0] < k) {		//불가능한경우
			return 2;
		}
		else {
			return -1;
		}
		
	}

	for (int i = 0; i < vec.size(); i++) {

		
		if (vec[i] < k) {
			return 0;				//재정비 해야함
		}
		else {
			cnt++;
		}
	
		
	}

	if (cnt == vec.size()) {
		return -1;					//완료 이제 검사 더 이상 그만
	}
		
	


}



int solution(vector<int> scoville, int K) {
	int answer = 0;

	int check = 0;
	int size;
	while (1) {
		size = scoville.size();

		sort(scoville.begin(), scoville.end());

		check = chkK(scoville, K);

		if (check == 2) {
			answer = -1;
			break;
		}
		
		if (check == -1) {
			break;
		}
		
		if (check == 0) {
			answer++;
			int firstMin = scoville[0];
			int secondMin = scoville[1];
			int newSco = firstMin + (2 * secondMin);

			scoville[1] = newSco;
			
			scoville.erase(scoville.begin());

		}

		

		



	}
	

	return answer;
}



int main() {

	vector<int> sco;
	sco.push_back(1);
	sco.push_back(2);
	sco.push_back(3);
	sco.push_back(9);
	sco.push_back(10);
	sco.push_back(12);

	int k = 7;
	cout << solution(sco, k);


	return 0;
}