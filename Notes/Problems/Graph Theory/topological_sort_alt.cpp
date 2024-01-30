#include <bits/stdc++.h> 
#include <vector>
#include <map>
#include <set>
using namespace std;

typedef vector<char> vc;

vc ordering;
map<char, bool> V;

int dfs(int i, char at, map<char, vc> graph) {
	V[at] = true;
	for (char child : graph[at]) {
		if (V[child] == false) {
			dfs(i, child, graph);
		}
	}
	ordering[i] = at;
	return i - 1;
}

vc topsort(map<char, vc> graph) {
	int N = graph.size();

	// map<char, bool>&& V = {{'A',false}};
	for (char l='A'; l<='M'; l++) {
		V[l] = false;
	}

	// vc&& ordering = {};
	for (int i=0; i<N; i++) {
		ordering.push_back(' ');
	}

	int i = N - 1;

	for (char at='A'; at<='M'; at++) {
		if (not V[at]) {
			i = dfs(i, at, graph);
		}
	}

	return ordering;
}

int main() {

	map<char, vc> adjacency_list;
	adjacency_list['A'] = {'D'};
	adjacency_list['B'] = {'D'};
	adjacency_list['C'] = {'A', 'B'};
	adjacency_list['D'] = {'H', 'G'};
	adjacency_list['E'] = {'A', 'D', 'F'};
	adjacency_list['F'] = {'J', 'K'};
	adjacency_list['G'] = {'I'};
	adjacency_list['H'] = {'I', 'J'};
	adjacency_list['I'] = {'L'};
	adjacency_list['J'] = {'M', 'L'};
	adjacency_list['K'] = {'J'};
	adjacency_list['L'] = {};
	adjacency_list['M'] = {};
	

	// map<char, bool>&& visited = {{'A',false}};
	// for (char l='A'; l<='M'; l++) {
	// 	visited[l] = false;
	// }

	// char start = 'H';
	// visited[start] = true;
	// vc order_of_nodes = dfs(adjacency_list, visited, start);
	// for (char node : order_of_nodes) printf("Node : %c \n", node);

	vc sorted_nodes = topsort(adjacency_list);
	for (char node : sorted_nodes) printf("Node : %c \n", node);

	return 0;


}