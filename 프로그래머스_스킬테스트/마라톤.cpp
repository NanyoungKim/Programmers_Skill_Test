#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";
	bool chk = true;
	bool chk2 = true;


	for (int i = 0; i < participant.size(); i++) {
		bool chk = true;
		bool chk2 = true;
		for (int j = 0; j < completion.size(); j++) {
		
			if (participant[i] != completion[j]) {
				chk = false;
				//cout << participant[i] << " " << completion[j] << endl;
			}
			else if((participant[i] == completion[j])){
				chk = true;
				//cout << participant[i] << " " << completion[j] << endl;
				completion.erase(completion.begin() + j, completion.begin() + j + 1);
				break;
			}

			if ((chk == false) && (j == (completion.size() - 1))) {
				//cout << participant[i] << " " << completion[j] << endl;
				answer = participant[i];
				chk2 = false;
				break;
			}
		}
		if (!chk2) break;
	}


	return answer;
}

int main() {

	vector<string> participant = { "mislav", "stanko", "mislav", "ana" };
	vector<string> completion = {"stanko", "ana", "mislav" };
	
	string ans = solution(participant, completion);
	cout << ans << endl;

	return 0;
}