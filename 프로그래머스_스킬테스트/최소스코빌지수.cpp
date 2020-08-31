#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;



int solution(vector<int> scoville, int K) {
	int answer = 0;

	int check = 0;
	int size;

	
	priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());

	while (pq.top() < K) {		//젤 작은게 기준치보다 크면 끝나는것임
		 
		if (pq.size() == 1) {
			return -1;
		}
		
		answer++;
		int firstMin = pq.top();
		pq.pop();
		int secondMin = pq.top();
		pq.pop();
		int newSco = firstMin + (2 * secondMin);
		pq.push(newSco);


		

		

		



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