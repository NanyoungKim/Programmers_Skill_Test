#include <string>
#include <iostream>
#include <vector>
#include <hash_map>

using namespace std;

hash_map<int, string> hMap;
vector<string> dict = { "A", "B", "C", "D", "E", "F", "G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z" };


vector<int> solution(string msg) {
	vector<int> answer;





	return answer;
}



int main() {

	string msg = "KAKAO";
	vector<int> res = solution(msg);

	for (int i = 1; i < 27; i++) {
		hMap.insert(hash_map<int, string>::value_type(i, dict[i-1]));
	}
	
	


	
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	}
	return 0;
}