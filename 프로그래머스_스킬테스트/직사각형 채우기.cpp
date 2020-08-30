#include <string>
#include <vector>
#include <iostream>

using namespace std;


int answer = 0;
int width = 0;
int ans = 0;


void func(int n, int cnt) {

	

	if (width > n) {
		width -= 2;
		cnt -= 2;
		return;
	}


	if (n == width)
	{
		ans += 1;
		width -= 1;
		cnt -= 1;
		return;
	}


	for (int i = 0; i < pow(2, n); i++) {
		width += 1;
		cnt += 1;
		func(n, cnt);
		width += 2;
		cnt += 2;

	}

	



}




int solution(int n) {
	int count = 0;



	
	func(n,  count);



	answer = ans;

	return answer;
}


int main() {

	int n;
	cin >> n;

	cout << solution(n) << endl;

	return 0;
}