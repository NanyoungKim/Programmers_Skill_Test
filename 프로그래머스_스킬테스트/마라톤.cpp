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
		newparticipant.insert(pair<string, bool>(participant[i], false));
	}


	
	for (int i = 0; i < completion.size(); i++) {

		chk = newparticipant.find(completion[i]);

		if (chk->second == 0) {
			chk->second += 1;	//방문했다고 체크
			cout << "방문된 곳: " << chk->first << " ";

		}
		else {
			
		}
	}
	cout << endl;

	for (it = newparticipant.begin(); it != newparticipant.end(); it++) {

		cout << it->first << " " << it->second << endl;
	}

	for (it = newparticipant.begin(); it != newparticipant.end(); it++) {

		if (it->second == false) {
			
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