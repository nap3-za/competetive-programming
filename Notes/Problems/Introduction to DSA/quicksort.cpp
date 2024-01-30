#include <bits/stdc++.h>
#include <vector>
using namespace std;

typedef vector<int> vi;


vi merge(vi less_than, int pivot, vi greater_than) {
	vi merged;

	if (less_than.size() > 0)
		for (int item : less_than) 
			merged.push_back(item);

	merged.push_back(pivot);

	if (greater_than.size() > 0)
		for (int item : greater_than)
			merged.push_back(item);

	return merged;
}

// Worst case : O(n^2) Best case : O(n log(n))
// Commonly used than merge sort because of the executed repetitions.
vi quicksort(vi list) {

	// base case
	if (list.size() <= 1)
		return list;

	vi sorted_list;
	int pivot = list[0];
	vi less_than, greater_than;
	
	list.erase(list.begin()); // remove the pivot

	for (int item : list ) {
		if (item >= pivot)
			greater_than.push_back(item); 
		else 
			less_than.push_back(item);
	}

	less_than = quicksort(less_than);
	greater_than = quicksort(greater_than);

	return merge(less_than, pivot, greater_than);
}

int main() {
	vi list = {13,3,5,1,33,25,102,86};
	for (int item : quicksort(list)) {
		printf("Item : %d \n", item);
	}
}