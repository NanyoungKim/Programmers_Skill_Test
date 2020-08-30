#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;

	int genrCnt = 0;
	vector<string> uniqueGenr;
	vector<string> ::iterator it;

	for (int i = 0; i < genres.size(); i++) {

		it = find(uniqueGenr.begin(), uniqueGenr.end(), genres[i]);

		if (it == uniqueGenr.end()) {//¾øÀ¸¸é
			
			uniqueGenr.push_back(genres[i]);

		}
		else continue;


	}









	return answer;
}



int main() {


	vector<string> genres;
	genres.push_back("classic");
	genres.push_back("pop");
	genres.push_back("classic");
	genres.push_back("classic");
	genres.push_back("pop");


	vector<int> plays;
	plays.push_back(500);
	plays.push_back(600);
	plays.push_back(150);
	plays.push_back(800);
	plays.push_back(2500);


	vector<int> res = solution(genres, plays);
	
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << endl;
	}


	return 0;

}


	