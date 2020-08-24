#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;





bool solution(vector<string> phone_book) {
	bool answer = true;
	int idx = 0;
	
	sort(phone_book.begin(), phone_book.end());


	for ( int i = 0; i < phone_book.size(); i++) {

	
		for ( int j = 0; j < phone_book.size(); j++) {


			if (i != j) {

				

				idx = phone_book[j].find(phone_book[i], 0);
				cout << idx << endl;

				if (idx == 0) return false;
				else return true;
			
				



			}
			else continue;



		}

	}



}



int main() {


	vector<string> phone_book;
	phone_book.push_back("119");
	phone_book.push_back("97674223");
	phone_book.push_back("1195524421");
		
	
	if (solution(phone_book) == 1) {
		cout << "true" << endl;
	}
	else {
		cout << "false" << endl;
	}

	return 0;
}