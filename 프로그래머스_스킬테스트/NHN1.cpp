#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;





void solution(int numOfAllPlayers, int numOfQuickPlayers, char *namesOfQuickPlayers, int numOfGames, int *numOfMovesPerGame) {
	// TODO: 이곳에 코드를 작성하세요. 추가로 필요한 함수와 전역변수를 선언해서 사용하셔도 됩니다.
	
	int startIdx;
	int playerIdx;
	int towelIdx;
	bool flagQuick;
	vector<char>::iterator it;
	

	vector<char> playerVec;
	vector<char> ansP;
	vector<int> ansC;

	for (int i = 0; i < numOfAllPlayers - 1; i++) {	// A 빼고
		playerVec.push_back('B' + i);
	}
	for (int i = 0; i < numOfAllPlayers; i++) {
		ansP.push_back('A'+i);
		ansC.push_back(0);
	}
	ansC[0] = 1;


	bool chk = false;
	
	for (int i = 0; i < numOfGames; i++) {		//전체 게임 수만큼 반복
		static char player;


		if (chk == true) {
			player = ansP[0];
		}
		flagQuick = false;
		if (i == 0) {
			player = 'A';
			startIdx = 0;
		
		}
		
		cout << "Player : " << player << endl;
		//어디에 수건 놓을지 체크
		it = find(playerVec.begin(), playerVec.end(), player);

		int dis = (distance(playerVec.begin(), it) + numOfMovesPerGame[i]);
		if (dis < 0) {
			dis += numOfAllPlayers - 1;
		}
		towelIdx = dis % (numOfAllPlayers - 1);


		cout << "towelIdx : " << towelIdx << endl;
		
		//수건 놓은 자리가 빠른 사람 자리인지 확인
		for (int i = 0; i < numOfAllPlayers; i++) {
			if (ansP[towelIdx+1] == namesOfQuickPlayers[i]) {
				flagQuick = true;
			}
		}
		cout << "flag : " << flagQuick << endl;

		char tmpP;
		int tmpC;
		char tmp;
		if (flagQuick == true) {	//빠른 사람이면 술래 그대로 

			chk = true;
			player = ansP[0];
			ansC[0]++;
			
		}
		else {		//느린 사람이라 걸린거면 선수 교체
			
			
			player = playerVec[towelIdx];
			startIdx = towelIdx;

			tmpP = ansP[0];
			tmpC = ansC[0];
		

			ansP[0] = ansP[towelIdx + 1];
			ansC[0] = ansC[towelIdx + 1] + 1;
			playerVec[towelIdx] = ansP[0];

			ansP[towelIdx + 1] = tmpP;
			ansC[towelIdx + 1] = tmpC;








		}
		
		cout << "술래: " << ansP[0] << "  ///   " << ansC[0] << endl << endl;



		
		
		





	}
	for (int i = 1; i < numOfAllPlayers; i++) {
		cout << ansP[i] << " " << ansC[i] << endl;
	}
	cout << ansP[0] << " " << ansC[0] << endl;
	

}

struct input_data {
	int numOfAllPlayers;
	int numOfQuickPlayers;
	char *namesOfQuickPlayers;
	int numOfGames;
	int *numOfMovesPerGame;
};

void process_stdin(struct input_data& inputData) {
	string line;
	istringstream iss;

	getline(cin, line);
	iss.str(line);
	iss >> inputData.numOfAllPlayers;

	getline(cin, line);
	iss.clear();
	iss.str(line);
	iss >> inputData.numOfQuickPlayers;

	getline(cin, line);
	iss.clear();
	iss.str(line);
	inputData.namesOfQuickPlayers = new char[inputData.numOfQuickPlayers];
	for (int i = 0; i < inputData.numOfQuickPlayers; i++) {
		iss >> inputData.namesOfQuickPlayers[i];
	}

	getline(cin, line);
	iss.clear();
	iss.str(line);
	iss >> inputData.numOfGames;

	getline(cin, line);
	iss.clear();
	iss.str(line);
	inputData.numOfMovesPerGame = new int[inputData.numOfGames];
	for (int i = 0; i < inputData.numOfGames; i++) {
		iss >> inputData.numOfMovesPerGame[i];
	}
}

int main() {
	struct input_data inputData;
	process_stdin(inputData);

	solution(inputData.numOfAllPlayers, inputData.numOfQuickPlayers, inputData.namesOfQuickPlayers, inputData.numOfGames, inputData.numOfMovesPerGame);
	return 0;
}