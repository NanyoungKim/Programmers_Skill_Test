#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


//int solution(vector<int> &a) {
//	if (a.size() == 1) {
//		return a[0];
//	}
//
//
//
//
//	sort(a.begin(), a.end());
//
//	for (int i = 0; i < a.size() - 2; i++) {
//
//
//		if (a.size() == 1) {
//			return a[0];
//		}
//
//
//		if (a[i] == a[i + 1]) {
//
//			a.erase(a.begin() + i, a.begin() + (i + 2));
//
//			/*for (int k = 0; k < a.size(); k++) {
//				cout << a[k] << " ";
//			}*/
//			i = i - 1;
//		}
//		else {
//			if (a[i + 1] == a[i + 2]) {
//				return a[i];
//			}
//
//		}
//
//	}
//
//	if (a.size() == 1) {
//		return a[0];
//	}
//
//}
//	


	
int solution(vector<int> &a) {

	priority_queue<int> pq;

	for (int i = 0; i < a.size(); i++) {
		pq.push(a[i]);
	}

	while (pq.size() != 1) {

		int tmp = pq.top();
		pq.pop();
		int next = pq.top();
		pq.pop();

		if (tmp != next) {
			int third = pq.top();
			if (next == third) {
				return tmp;
			}

		}
	}


	if (pq.size() == 1) {
		return pq.top();
	}

}





int main() {



	vector<int> arr = { 1 };

	int res = solution(arr);
	cout << res;

	return 0;
}


