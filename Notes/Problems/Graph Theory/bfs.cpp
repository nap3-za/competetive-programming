#include <bits/stdc++.h> 
#include <vector>
#include <map>
#include <queue>
using namespace std;

typedef vector<char> vc;


int main() {

	map<char, vc> adjacency_list;
	adjacency_list['A'] = {'B', 'C'};
	adjacency_list['B'] = {'D', 'E'};
	adjacency_list['D'] = {};
	adjacency_list['E'] = {'F', 'G', 'H'};
	adjacency_list['C'] = {};

	queue<char> list;
	char start = 'A';
	vc order_of_nodes;

	list.push(start);
	int size = 1;
	while (size > 0) {
		for (char child : adjacency_list[list.front()]) {
			list.push(child);
			size++;
		}
		order_of_nodes.push_back(list.front());
		list.pop();
		size--;
	}


	for (char node : order_of_nodes) printf("Node : %c \n", node);
	return 0;


}