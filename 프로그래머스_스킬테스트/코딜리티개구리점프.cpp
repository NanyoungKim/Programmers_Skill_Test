#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
using namespace std;



int solution(int X, int Y, int D) {

	

	if (X == Y) return 0;
	
	
	if ((Y - X) % D == 0) {
		return (Y-X) / D;
	}
	else {
		return ((Y - X) / D) + 1;
	}



}


int main() {

	int res = solution(10, 85, 30);
	cout << res;

	return 0;
}