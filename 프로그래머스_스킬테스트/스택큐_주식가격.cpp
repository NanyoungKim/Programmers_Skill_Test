#include <string>
#include <vector>
#include <iostream>
#include <stack>
using namespace std;

vector<int> solution(vector<int> prices) {
	vector<int> answer;
	stack<int> stk;

	for (int i = 0; i < prices.size(); i++) {


		bool chk = false;
		int cnt = 0;


		if (i == prices.size()-1) {		//���� ���� ������ 0
			answer.push_back(0);
			break;
		}

		for (int j = i+1; j < prices.size(); j++) {
			

			if (prices[i] > prices[j]) {
				stk.push(prices[j]);
				break;
			}


			if (prices[i] <= prices[j]) {
				stk.push(prices[j]);
				chk = true;
			}
			
				
		}

		if (stk.empty()) {					//�ٷ� �ߴܵƾ 1�ʵ��� �� ���� ���̶�� �Ǵ�
			answer.push_back(1);
		}
		else {
			
			while (!stk.empty()) {
				
				stk.pop();
				cnt++;
			}

			answer.push_back(cnt);

		}

	}

	return answer;
}



int main() {

	vector<int> prices = { 1,2,3,4,5 };
	vector<int> res = solution(prices);

	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	}


	return 0;

}