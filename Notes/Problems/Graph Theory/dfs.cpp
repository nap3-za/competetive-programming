#include <bits/stdc++.h> 
#include <vector>
#include <map>
using namespace std;

typedef vector<char> vc;

vc dfs(map<char, vc> adjacency_list, char start) {
	vc order_of_nodes = {start};

	if (adjacency_list[start].size() == 0) 
		return order_of_nodes;

	for (char node : adjacency_list[start]) {
		vc sub_nodes = dfs(adjacency_list, node);
		for (char sub_node : sub_nodes) {
			order_of_nodes.push_back(sub_node);
		}
	}

	return order_of_nodes;
}



int main() {

	map<char, vc> adjacency_list;
	adjacency_list['A'] = {'B', 'C'};
	adjacency_list['B'] = {'D', 'E'};
	adjacency_list['D'] = {};
	adjacency_list['E'] = {'F', 'G', 'H'};
	adjacency_list['C'] = {};

	vc order_of_nodes = dfs(adjacency_list, 'A');
	for (char node : order_of_nodes) printf("Node : %c \n", node);


	return 0;


}