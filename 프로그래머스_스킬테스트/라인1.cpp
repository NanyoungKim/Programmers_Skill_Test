#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;




int solution(vector<vector<int>> boxes) {
	int answer = 0;
	vector<int> vec1, vec2;

	int row = boxes.size();
	int col = boxes[0].size();

	for (int i = 0; i < boxes.size(); i++) {	//행크기만큼

		vec1.push_back(boxes[i][0]);

	}
	for (int i = 0; i < boxes.size(); i++) {	//행크기만큼

		vec2.push_back(boxes[i][1]);

	}

	sort(vec1.begin(), vec1.end());
	sort(vec2.begin(), vec2.end());

	int cnt = 0;

	while ((vec1.size() != 0) && (vec2.size() != 0)) {

		for (int i = 0; i < vec1.size(); i++) {
			if (vec1[i] == vec2[i]) {
				
				vec1.erase(vec1.begin());
				vec2.erase(vec2.begin());
				--i;
				break;
			}
			else{
				
				cnt++;
				if (vec1[i] >= vec2[i]) {
					vec2.erase(vec2.begin());
					--i;
				}
				else {
					vec1.erase(vec1.begin());
					--i;
				}
				break;
			}
		}

		
	}
	
	cnt = cnt + vec1.size() + vec2.size();
	answer = cnt / 2;





	return answer;
}


int main() {

	vector<vector<int>> boxes = { {1,2}, {2,1}, {3,3}, {4,5}, {5,6}, {7,8} };
	int res = solution(boxes);
	//cout << boxes[0].size();
	//cout << boxes.size();
	cout << res;

	return 0;
}