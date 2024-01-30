#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;


int binary_search(vi list, int count, int target) {
	int start=0, mid, end=count-1;
	while (start <= end) {
		mid = round((start+end)/2);

		if (list[mid] == target) {
			return mid+1;
			break;
		} else if (target < list[mid] && mid != start) {
			end = mid-1; 
		} else if (target > list[mid] && mid != end){
			start = mid+1;			
		} else {
			break;
		}
	}

	return 0;
}

int recursive_binary_search(vi list, int start, int end, int target) {
	while (start <= end) {
		int mid = round((start+end)/2);

		// Base case
		if (list[mid] == target) {
			return mid+1;
		} 

		if (target < list[mid] && mid != start) {
			return recursive_binary_search(list, start, mid-1, target);
		} else if (target > list[mid] && mid != end){
			return recursive_binary_search(list, mid+1, end, target);
		} else {
			break;
		}
	}

	return 0;
}


int main() {
	
	//=== Input
	const int count_const = 10;
	int count = count_const;

	vi list = {63, 1, 25, 92, 44, 12, 51, 70, 32, 86};
	vi sorted_list = {1, 12, 25, 32, 44, 51, 63, 70, 86, 92};

	int pos = 0, target = 51;
	bool found = false;

	int start = 0, end = count-1;
	// pos = binary_search(sorted_list, count, target);
	pos = recursive_binary_search(sorted_list, start, end, target);

	//=== Output
	if (pos > 0) 
		printf("Element %d at position %d \n", target, pos);
	else
		printf("Element %d not found \n", target);
}