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
	vc order_of_nodes;
	int size = 1, moves = 0;
	char start = 'A', target = 'F';
	bool found = false;

	list.push(start);
	
	while (size > 0 && not found) {
		moves++;

		order_of_nodes.push_back(list.front());
		
		for (char child : adjacency_list[list.front()]) {
			list.push(child);
			size++;
			if (child == target) {
				order_of_nodes.push_back(child);
				found = true;
				break;
			}
		}

		list.pop();
		size--;
	}


	for (char node : order_of_nodes) printf("Node : %c \n", node);
	printf("\nMoves : %d \n", moves);
	return 0;


}