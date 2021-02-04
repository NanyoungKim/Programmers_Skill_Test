#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);



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

#include <vector>

vector<int> connect[100001];

void dfs(int start) {

	for (int i = 0; i < connect[i].size(); i++) {
		int next = connect[start][i];

	}


}
vector<int> order(int city_nodes, vector<int> city_from, vector<int> city_to, int company) {

	for (int i = 0; i < city_from.size(); i++) {
		connect[city_from[i]].push_back(city_to[i]);
		connect[city_to[i]].push_back(city_from[i]);
	}


	
	dfs(company);

}

int main() {


	return 0;
}




















