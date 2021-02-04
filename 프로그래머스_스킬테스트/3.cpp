
using namespace std;

//string ltrim(const string &);
//string rtrim(const string &);
//vector<string> split(const string &);



/*
 * Complete the 'order' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. UNWEIGHTED_INTEGER_GRAPH city
 *  2. INTEGER company
 */

 /*
  * For the unweighted graph, <name>:
  *
  * 1. The number of nodes is <name>_nodes.
  * 2. The number of edges is <name>_edges.
  * 3. An edge exists between <name>_from[i] and <name>_to[i].
  *
  */

#include <string.h>
#include <queue>
#include <vector>
#include <iostream>

vector<int> connect[100001];
int visited[100001] = { 0 };
vector<int> ansVec;
queue<int> que;


void bfs() {

	while (!que.empty()) {
		int s = que.front();
		que.pop();

		for (int i = 0; i < connect[s].size(); i++) {
			int next = connect[s][i];

			if (visited[next] == 0) {
				ansVec.push_back(next);
				visited[next] = 1;
				que.push(next);

			}

		}
	}


}
vector<int> order(int city_nodes, vector<int> city_from, vector<int> city_to, int company) {

	// visited = new int* [city_nodes];
	// for(int i = 0; i<city_nodes; i++){
	//     visited[i] = new int[city_nodes];
	//     memset(visited[i], 0, sizeof(int)*city_nodes);
	// }


	for (int i = 0; i < city_from.size(); i++) {
		int f = city_from[i];
		int t = city_to[i];
		connect[f].push_back(t);
		connect[t].push_back(f);
	}
	visited[company] = 1;
	que.push(company);

	bfs();

	return ansVec;

	//for(int i = 0; i<city_nodes; i++){delete[] visited[i];} delete[] visited;

}
int main() {
	vector<int> from = { 1,1,2,3,1 };
	vector<int> to = { 2,3,4,5,5 };

	vector<int> ret =  order(5, from, to, 1);

	for (int i = 0; i < ret.size(); i++) {
		cout << ret[i] << " ";
	}
}