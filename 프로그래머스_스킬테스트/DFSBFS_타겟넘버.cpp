#include <iostream>
#include <vector>

using namespace std;


int ans = 0;

void dfs(vector<int> numbers, int sum, int t, int cnt) {

	if (cnt == numbers.size()) {
		if (sum == t) {
			ans++;
		}
		return;
	}

	dfs(numbers, sum + numbers[cnt], t, cnt + 1);
	dfs(numbers, sum - numbers[cnt], t, cnt + 1);



}

int solution(vector<int> numbers, int target) {
	int answer = 0;

	dfs(numbers, 0, target, 0);

	answer = ans;
	return answer;
}

