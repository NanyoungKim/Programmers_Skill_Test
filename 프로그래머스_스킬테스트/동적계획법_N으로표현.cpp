//ÃâÃ³ : https://junho0956.tistory.com/266

#include <iostream>


using namespace std;

int goal;

int Min = 9;


void dfs(int number, int cnt, int N) {
	
	if (cnt >= 9) {
		return;
	}

	if (number == goal) { 
		 
		if (Min > cnt) {
			Min = cnt;
			
		}
		return;
	}


	int n = 0;
	for (int i = 1; i < 9; i++) {

		n *= 10;
		n += N;

		dfs(number + n, cnt + i, N);
		dfs(number - n, cnt + i, N);

		if (number != 0) {
			dfs(number * n, cnt + i, N);
			dfs(number / n, cnt + i, N);
		}




	}







}




int solution(int N, int number) {
	int answer = 0;

	goal = number; //12

	dfs(0, 0, N);
	
	if (Min > 8) {
		answer = -1;
	}
	else {
		answer = Min;
	}

	return answer;
}





int main() {

	int N = 5;
	int number = 12;
	cout << solution(N, number);



	return 0;
}


