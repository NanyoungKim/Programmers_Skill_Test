#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int maxFind(int a, int b, int c) {

	vector<int> v = { a,b,c };
	sort(v.begin(), v.end());

	return v[2];
}

vector<int> solution(vector<int> answers) {
	vector<int> answer;
	int x = 0;
	int y = 0;
	int z = 0;

	int cnt1 = 0;
	int cnt2 = 0;
	int cnt3 = 0;

	int firstArr[5] = { 1,2,3,4,5 };
	int secondArr[8] = { 2,1,2,3,2,4,2,5 };
	int thirdArr[10] = { 3,3,1,1,2,2,4,4,5,5 };


	for (int i = 0; i < answers.size(); i++) {

		if ((i != 0) && (i % 5 == 0)) x++;
		if ((i != 0) && (i % 8 == 0)) y++;
		if ((i != 0) && (i % 10 == 0)) z++;

		if (answers[i] == firstArr[i - 5 * x]) cnt1++;
		if (answers[i] == secondArr[i - 8 * y])	cnt2++;
		if (answers[i] == thirdArr[i - 10 * z])	cnt3++;

	}


	int m = maxFind(cnt1, cnt2, cnt3);

	if (m == cnt1) answer.push_back(1);
	if (m == cnt2) answer.push_back(2);
	if (m == cnt3) answer.push_back(3);


	return answer;
}

int main() {

	vector<int> array = { 1,3,2,4,2 };
	
	vector<int> res = solution(array);



	for (int i = 0; i < res.size(); i++) {
		cout << i << " : " << res[i] << endl;
	}

	return 0;
}
