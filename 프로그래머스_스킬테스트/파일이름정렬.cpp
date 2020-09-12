#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


vector<string> head;
vector<int> num;
vector<string> tail;


void splitFunc(vector<string> vec) {

	string h = "";
	string n = "";
	string t = "";

	for (int i = 0; i < vec.size(); i++) {

		
		for (int j = 0; j < vec[i].length(); j++) {

			if (sizeof(vec[i].at(j)) == sizeof(char)) {
				

			}


		}


	}


}


vector<string> solution(vector<string> files) {
	vector<string> answer;
	
	sort(files.begin(), files.end());
	
	answer = files;
	return answer;
}



int main() {
	
	vector<string> vec = { "img12.png", "img10.png", "img02.png", "img1.png", "IMG01.GIF", "img2.JPG" };

	vector<string> resVec = solution(vec);

	for (int i = 0; i < resVec.size(); i++) {
		cout << resVec[i] << "\n";
	}
	return 0;
}