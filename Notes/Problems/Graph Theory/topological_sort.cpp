#include <bits/stdc++.h> 
#include <vector>
#include <map>
#include <set>
using namespace std;

typedef vector<char> vc;

vc dfs(map<char, vc> adjacency_list, map<char, bool>& visited, char start) {
	vc order_of_nodes;

	for (char node : adjacency_list[start]) {
		if (not visited[node]) {
			visited[node] = true;
			vc sub_nodes = dfs(adjacency_list, visited, node);
			for (char sub_node : sub_nodes) order_of_nodes.push_back(sub_node);
			order_of_nodes.insert(order_of_nodes.begin(), node);
		}
	}

	if (not visited[start]) {
		order_of_nodes.push_back(start);
		visited[start] = true;
	}
	return order_of_nodes;
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
	

	map<char, bool>&& visited = {{'A',false}};
	for (char l='A'; l<='M'; l++) {
		visited[l] = false;
	}

	char start = 'C';
	visited[start] = true;
	vc order_of_nodes = dfs(adjacency_list, visited, start);
	for (char node : order_of_nodes) printf("Node : %c \n", node);


	return 0;


}