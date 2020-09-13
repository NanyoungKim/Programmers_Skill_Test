#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool visit[10000];

vector<int> sumVec;
vector<int> resVec;
int cnt = 0;
void recurse(vector<int> v, int sum, int toPick) {
	

	cout << "toPick" << toPick << endl;
	if (toPick == 0) {
		int num = 0;
		for (int i = 0; i < sumVec.size(); i++) {
			num += sumVec[i];
		}

		resVec.push_back(num);
		return;
	}

	else {
		for (int i = 0; i < v.size(); i++) {

			if (visit[i] == true) {

				sum += v[i];
				cnt++;
				if (cnt > 1) {
					sumVec.push_back(sum);		//350, 1350
				}
				visit[i] = false;
				recurse(v, sum, toPick - 1);

				sum -= v[i];
				cnt--;
				if (cnt > 1) {
					sumVec.pop_back();
				}
				visit[i] = true;

			}

		}
	}
	



}



int solution(vector<int> &A) {
	// write your code in C++14 (g++ 6.2.0)

	for (int i = 0; i < 10000; i++) {
		visit[i] = true;
	}

	recurse(A, 0,  A.size());

	sort(resVec.begin(), resVec.end());

	for (int i = 0; i < resVec.size(); i++) {
		cout << resVec[i] << endl;
	}


	return resVec[0];


}


int main() {

	vector<int> v = { 1,2,3,4,5 };

	cout << solution(v);

	return 0;
}