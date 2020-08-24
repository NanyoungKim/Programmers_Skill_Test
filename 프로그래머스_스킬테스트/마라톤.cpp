#include <string>
#include <unordered_map>
#include <iostream>
#include <vector>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";
	
	unordered_multimap<string, int>::iterator it;
	unordered_multimap<string, int>::iterator chk;
	unordered_multimap<string, int> newparticipant;

	for (int i = 0; i < participant.size(); i++) {

		if (newparticipant.find(participant[i]) == newparticipant.end()) {
			newparticipant.insert(pair<string, int>(participant[i], 1));

		}
		else {
			newparticipant.find(participant[i])->second += 1;


		}

	}
	for (it = newparticipant.begin(); it != newparticipant.end(); it++) {

		cout << it->first << " " << it->second << endl;
	}

	
	for (int i = 0; i < completion.size(); i++) {

		chk = newparticipant.find(completion[i]);

			chk->second -= 1;
		
	}
	cout << endl;

	for (it = newparticipant.begin(); it != newparticipant.end(); it++) {

		cout << it->first << " " << it->second << endl;
	}

	for (it = newparticipant.begin(); it != newparticipant.end(); it++) {

		if (it->second == 1) {
			
			answer = it->first;
		}

	}



	return answer;
}

int main() {


	vector<string> participant = { "a", "b", "a", "c" ,"a", "d" };

	vector<string> completion = {"a", "b", "a", "d", "a" };


	
	string ans = solution(participant, completion);
	cout << ans << endl;

	return 0;
}