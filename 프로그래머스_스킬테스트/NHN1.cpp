#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;





void solution(int numOfAllPlayers, int numOfQuickPlayers, char *namesOfQuickPlayers, int numOfGames, int *numOfMovesPerGame) {
	// TODO: �̰��� �ڵ带 �ۼ��ϼ���. �߰��� �ʿ��� �Լ��� ���������� �����ؼ� ����ϼŵ� �˴ϴ�.
	
	int startIdx;
	int playerIdx;
	int towelIdx;
	bool flagQuick;
	vector<char>::iterator it;
	

	vector<char> playerVec;
	vector<char> ansP;
	vector<int> ansC;

	for (int i = 0; i < numOfAllPlayers - 1; i++) {	// A ����
		playerVec.push_back('B' + i);
	}
	for (int i = 0; i < numOfAllPlayers; i++) {
		ansP.push_back('A'+i);
		ansC.push_back(0);
	}
	ansC[0] = 1;


	bool chk = false;
	
	for (int i = 0; i < numOfGames; i++) {		//��ü ���� ����ŭ �ݺ�
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
		//��� ���� ������ üũ
		it = find(playerVec.begin(), playerVec.end(), player);

		int dis = (distance(playerVec.begin(), it) + numOfMovesPerGame[i]);
		if (dis < 0) {
			dis += numOfAllPlayers - 1;
		}
		towelIdx = dis % (numOfAllPlayers - 1);


		cout << "towelIdx : " << towelIdx << endl;
		
		//���� ���� �ڸ��� ���� ��� �ڸ����� Ȯ��
		for (int i = 0; i < numOfAllPlayers; i++) {
			if (ansP[towelIdx+1] == namesOfQuickPlayers[i]) {
				flagQuick = true;
			}
		}
		cout << "flag : " << flagQuick << endl;

		char tmpP;
		int tmpC;
		char tmp;
		if (flagQuick == true) {	//���� ����̸� ���� �״�� 

			chk = true;
			player = ansP[0];
			ansC[0]++;
			
		}
		else {		//���� ����̶� �ɸ��Ÿ� ���� ��ü
			
			
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
		
		cout << "����: " << ansP[0] << "  ///   " << ansC[0] << endl << endl;



		
		
		





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