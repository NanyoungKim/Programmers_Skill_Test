#include <string>
#include <vector>

using namespace std;

string solution(string m, string k) {
	string answer = "";


	for (int i = 0; i < m.length(); i++) {

		for (int j = 0; j < k.length(); j++) {
			if (m[i] == k[j]) {
				m.erase(i, 1);
				k.erase(j, 1);
				break;
			}
		}
	}

	answer = m;
	return answer;
}