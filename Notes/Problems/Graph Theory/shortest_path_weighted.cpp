#include <bits/stdc++.h> 
#include <vector>
#include <map>
#include <set>
#include <utility>
using namespace std;

typedef vector<char> vc;
#define INF 100
;

vc dfs(map<char, vector<pair<char, int>>>& graph, map<char, bool>& visited, map<char, double>& distance, char start) {
	pair<vc, map<char, double>> order_of_nodes;

	for (pair<char, int> weighted_edge : graph[start]) {
		if (visited[weighted_edge.first]) {
			if (distance[weighted_edge.first] > (distance[start] + weighted_edge.second)) {
				distance[weighted_edge.first] = distance[start] + weighted_edge.second;
			}
		} else if (not visited[weighted_edge.first]) {
			visited[weighted_edge.first] = true;

			distance[weighted_edge.first] = distance[start] + weighted_edge.second;

			pair<vc, map<char, double>> sub_nodes = dfs(graph, visited, distance, weighted_edge.first);
			for (char sub_node : sub_nodes.first) order_of_nodes.first.push_back(sub_node);
			order_of_nodes.first.insert(order_of_nodes.first.begin(), weighted_edge.first);
		}
	}

	if (not visited[start]) {
		order_of_nodes.first.push_back(start);
		visited[start] = true;
	}

	order_of_nodes.second = distance;
	return order_of_nodes;
}


int main() {

	map<char, vector<pair<char, int>>>&& adjacency_list_weighted = {{'A', {{'B', 3}, {'C', 6}}}};
	adjacency_list_weighted['A'] = {{'B', 3}, {'C', 6}};
	adjacency_list_weighted['B'] = {{'C', 4}, {'D', 4}, {'E', 11}};
	adjacency_list_weighted['C'] = {{'D', 8}, {'G', 11}};
	adjacency_list_weighted['D'] = {{'E', -4}, {'F', 5}, {'G', 2}};
	adjacency_list_weighted['E'] = {{'H', 9}};
	adjacency_list_weighted['F'] = {{'H', 1}};
	adjacency_list_weighted['G'] = {{'H', 2}};


	map<char, bool>&& visited = {{'A',true}};
	for (char l='B'; l<='G'; l++) visited[l] = false;

	map<char, double> distance = {{'A', 0}};
	for (char l='B'; l<='G'; l++) distance[l] = INF;

	char start = 'A';
	pair<vc, map<char, double>> order_of_nodes = dfs(adjacency_list_weighted, visited, distance, start);
	for (char node : order_of_nodes.first) printf("Node & Distance from %c : %c, %d \n", start, node, order_of_nodes.second[node]);


	return 0;


}