#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;


string findMenu(vector<string> orders) {

	string res = "";

	for (int i = 0; i < orders.size(); i++) {

		string str = orders[i];
		for (int j = 0; j < str.length(); j++) {

			if (res.find(str[j], 0) == -1) {	//없으면
				res += str[j];
			}
		}
	}



	sort(res.begin(), res.end());
	return res;


}
string combMenu = "";
vector<string> comb;
string menu;
vector<bool> chk;

void pick(int n, string picked, int toPick, string order) {

	if (toPick == 0) {
		comb.push_back(picked);
		return;
	}



	for (int i = 0; i < n; i++) {

		if (chk[i] == false) {
			picked += order[i];
			chk[i] = true;
			pick(n, picked, toPick - 1, order);
			picked.erase(i, 1);
			chk[i] = false;
		}

	}

}








vector<string> solution(vector<string> orders, vector<int> course) {
	vector<string> answer;
	menu = findMenu(orders);

	for (int i = 0; i < course.size(); i++) {
		for (int j = 0; j < orders.size(); j++) {
			for (int a = 0; a < orders[j].length(); a++) {
				chk.push_back(0);
			}
			string str = "";
			pick(orders[j].length(), str, course[i], orders[j]);			//comb 에 쌓임 
			chk.clear();
		}

		int maxCnt = count(comb.begin(), comb.end(), comb[0]);
		string maxComb = comb[0];
		for (int k = 0; k < comb.size(); k++) {

			int cnt = count(comb.begin(), comb.end(), comb[k]);
			if (maxCnt < cnt) {
				maxCnt = cnt;
				maxComb = comb[k];

			}
		}
		answer.push_back(maxComb);
		comb.clear();

	}






	return answer;
}


int main() {


	vector<string> order = {"XYZ", "XWY", "WXA"};
		//= { "ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH" };
	vector<int> course = { 2,3,4 };

	vector<string> res = solution(order, course);

	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	}

	return 0;
}