#include <bits/stdc++.h>
#include <vector>
#include <array>
using namespace std;

typedef vector<int> vi;


vi selection_sort(vi list) {
	vi sorted_list;
	int min_index;
	int size = list.size();

	for (int i=0; i<size; i++) {
		int min = list[0];
		for (int j=0; j<list.size(); j++) {
			if (list[j] <= min) {
				min = list[j];
				min_index = j;
			}
		}
		sorted_list.push_back(min);
		list.erase(list.begin()+min_index);
	}
	return sorted_list;
}


int main() {
	
	vi list = {1,3,-1,15,76,-33,45,102};
	for (int item : selection_sort(list)) {
		printf("Item : %d \n", item);
	}
}