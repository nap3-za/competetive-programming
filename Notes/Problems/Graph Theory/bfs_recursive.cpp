#include <bits/stdc++.h> 
#include <vector>
#include <map>
using namespace std;

typedef vector<char> vc;

vc bfs(map<char, vc> adjacency_list, map<char, bool> visited, char start) {

	vc order_of_nodes;
	if (not visited[start]) order_of_nodes.push_back(start);

	for (char node : adjacency_list[start]) {
		order_of_nodes.push_back(node);
	}

	for (char child : adjacency_list[start]) {
		visited[child] = true;
		vc children_children = bfs(adjacency_list, visited, child);
		for (char sub_child : children_children) {
			order_of_nodes.push_back(sub_child);
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

	map<char, bool> visited;
	vc order_of_nodes = bfs(adjacency_list, visited, 'A');
	for (char node : order_of_nodes) printf("Node : %c \n", node);


	return 0;


}