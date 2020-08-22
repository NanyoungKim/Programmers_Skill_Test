#include <string>
#include <vector>

using namespace std;
int Leftcur[2] = { 3,0 };
int Rightcur[2] = { 3,2 };


vector<int> func(int n) {

	vector<int> v;
	switch (n) {
	case 1:
		v.push_back(0);
		v.push_back(0);
	case 2:
		v.push_back(0);
		v.push_back(1);
	case 3:
		v.push_back(0);
		v.push_back(0);
	case 4:
		v.push_back(0);
		v.push_back(0);
	case 5:
		v.push_back(0);
		v.push_back(0);
	case 6:
		v.push_back(0);
		v.push_back(0);
	case 7:
		v.push_back(0);
		v.push_back(0);
	case 8:
		v.push_back(0);
		v.push_back(0);
	case 9:
		v.push_back(0);
		v.push_back(0);
	case :
		v.push_back(0);
		v.push_back(0);
	case 2:
		v.push_back(0);
		v.push_back(0);
	case 2:
		v.push_back(0);
		v.push_back(0);
	}
	

}


int distance(int cur, int next) {
	
	int x1, y1, x2, y2;


}


string solution(vector<int> numbers, string hand) {
	string answer = "";


	for (int i = 0; i < numbers.size(); i++) {

		if (numbers[i] == 1) {
			answer.append("L");
			Leftcur[0] = 0;
			Leftcur[1] = 0;
		}
		else if (numbers[i] == 4) {
			answer.append("L");
			Leftcur[0] = 1;
			Leftcur[1] = 0;
		}
		else if (numbers[i] == 7) {
			answer.append("L");
			Leftcur[0] = 2;
			Leftcur[1] = 0;
		}
		else if (numbers[i] == 3) {
			answer.append("L");
			Rightcur[0] = 0;
			Rightcur[1] = 2;
		}
		else if (numbers[i] == 6) {
			answer.append("L");
			Rightcur[0] = 1;
			Rightcur[1] = 2;
		}
		else if (numbers[i] == 9) {
			answer.append("L");
			Rightcur[0] = 2;
			Rightcur[1] = 2;
		}
		else {





		}




	}




	return answer;
}


int main() {

	vector<int> numbers = { 1,3,4,5,8,2,1,4,5,9,5 };
	string hand = "right";

	solution(numbers, hand);
	


	return 0;
}