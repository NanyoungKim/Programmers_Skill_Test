#include <string>
#include <vector>
#include <iostream>
#include <cctype>
using namespace std;




string solution(string new_id) {
	string answer = "";
	bool chk = false;

	int idLen = new_id.length();

	//1�ܰ� : �빮�� -> �ҹ���
	for (int i = 0; i < new_id.length(); i++) {
		new_id[i] = tolower(new_id[i]);
	}
	cout << "1 : " << new_id << "\n";


	//2�ܰ� �ҹ���, ����, -, _, . ���� �����
	for (int i = 0; i < new_id.length(); i++) {

		if ((new_id[i] == '-') || (new_id[i] == '_') || (new_id[i] == '.') ||
			(isdigit(new_id[i])) || (('a' <= new_id[i]) && (new_id[i] <= 'z'))) {
			continue;

		}
		else {
			new_id.erase(i,1);
			--i;
		}

	}


		cout << "2 : " << new_id << "\n";

		//3�ܰ� : ��ħǥ 2�� �̻� ���ӵǸ� 1����
		vector<int> startThridVec;
		vector<int> cntThridVec;
		int cntThird = 1;
		bool chkThird = false;
		int startThird = 0;
		for (int i = 0; i < new_id.length() - 1; i++) {
			if ((new_id[i] == '.') && (new_id[i + 1] == '.')) {
				cntThird++;
				if ((cntThird == 2)) {
					startThridVec.push_back(i);
				}
				chkThird = true;
			}


			if ((chkThird == true) && ((new_id[i] == '.') && (new_id[i+1] != '.'))) {
				cntThridVec.push_back(cntThird);
				chkThird = false;
				cntThird = 1;

			}


			
		}

		for (int i = 0; i < cntThridVec.size(); i++) {

			for (int st = startThridVec[i]; st < startThridVec[i] + cntThridVec[i]-1; st++) {
				new_id[st] = '*';
			}

		}

		for (int i = 0; i < new_id.length(); i++) {
			if (new_id[i] == '*') {
				new_id.erase(i,1);
				--i;
			}
		}
		cout << "3 : " << new_id << "\n";


		//4�ܰ� 
		if (new_id[0] == '.') {
			new_id.erase(0,1);
		}
		if (new_id[new_id.length() - 1] == '.') {
			new_id.erase(new_id.length() - 1,1);
		}
		cout << "4 : " << new_id << "\n";


		//5�ܰ� ���ڿ��̸� a ����
		if (new_id.length() == 0) {
			new_id = "a";
		}
		cout << "5 : " << new_id << "\n";

		//6�ܰ� 16���̻��̸� 15���� �ڸ�
		if (new_id.length() > 15) {
			new_id = new_id.substr(0, 15);
		}
		if (new_id[new_id.length() - 1] == '.') {
			new_id.erase(new_id.length() - 1,1);
		}
		cout << "6 : " << new_id << "\n";

		//7�ܰ�
		if (new_id.length() <= 2) {
			while (new_id.length() != 3) {
				new_id += new_id[new_id.length() - 1];
			}
		}

		cout << "7 : " << new_id << "\n";




		return new_id;
	}




int main() {

	string res = solution("123_.def");


	cout << res << endl;
	return 0;
}
