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

			if (res.find(str[j], 0) == -1) {	//¾øÀ¸¸é
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

void pick(int n, string picked, int toPick) {

	if (toPick == 0) {
		comb.push_back(picked);
		return;
	}


	
	for (int i = 0; i < n; i++) {

		if (chk[i] == false) {
			picked += menu[i];
			chk[i] = true;
			pick(n, picked, toPick - 1);
			picked.erase(i, 1);
			chk[i] = false;
		}
		
	}

}








vector<string> solution(vector<string> orders, vector<int> course) {
	vector<string> answer;
	menu =  findMenu(orders);
	

	
	int cnt = 0;
	int orderedCnt = 0;

	map<int, int> hMap;
	vector<int> hMapVec;
	
	for (int i = 0; i < course.size(); i++) {
		string str = "";
		for (int i = 0; i < menu.length(); i++) {
			chk.push_back(0);
		}
		pick(menu.length(), str, course[i]);

		for (int j = 0; j < comb.size(); j++) {

			for (int p = 0; p < orders.size(); p++) {

				string combStr = comb[j];
				
				for (int q = 0; q < combStr.length(); q++) {
					int findchk = orders[p].find_first_of(combStr[q]);
					//cout << findchk << endl;
					if (findchk != -1) {
						cnt++;
					//	cout << cnt << "\n";
					}
					else {
						break;
					}
				}

				if (combStr.length() == cnt) {
					orderedCnt++;
				//	cout << orderedCnt << "\n";
				}
				cnt = 0;

			}
			hMapVec.push_back(orderedCnt);
			orderedCnt = 0;


		}

		int max = hMapVec[0];
		int b = 0;

		for (int a = 0; a < hMapVec.size()-1; a++) {
			if (max < hMapVec[a + 1]) {
				max = hMapVec[a + 1];
				b = a + 1;
			}

		}
		answer.push_back(comb[b]);
		
		comb.clear();
		hMapVec.clear();
		chk.clear();
		
	}




	return answer;
}


int main() {


	vector<string> order = { "ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH" };
	vector<int> course = { 2,3,4 };

	vector<string> res = solution(order, course);

	for (int i = 0; i < res.size(); i++) {
		cout << res[i]  <<" ";
	}

	return 0;
}