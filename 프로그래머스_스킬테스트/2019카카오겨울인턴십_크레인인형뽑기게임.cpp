#include <string>
#include <vector>
#include <stack>

using namespace std;

stack<int> stk;

int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0;
	int N = board.size();

	for (int i = 0; i < moves.size(); i++) {
		int c = moves[i] - 1;
		for (int r = 0; r < N; r++) {
			if (board[r][c] != 0) {

				if (!stk.empty()) {
					if (stk.top() == board[r][c]) {
						answer++;
						stk.pop();
					}
					else {
						stk.push(board[r][c]);
					}
				}

				else {
					stk.push(board[r][c]);
				}
				board[r][c] = 0;
				break;
			}
		}
	}
	answer *= 2;
	return answer;
}


int main() {



	return 0;
}