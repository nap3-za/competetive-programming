#include <bits/stdc++.h>
#include <vector>
#include <array>
using namespace std;

typedef vector<int> vi;


// Linear Search : Traverse through all elements until target is found
int linear_search(vi list, int count, int target) {
	count--;
	while (count--) {
		if (list[count] == target) {
			return count+1;
		}
	}
	return -1;
}


int main() {
	
	//=== Input
	const int count_const = 10;
	int count = count_const;

	vi list = {63, 1, 25, 92, 44, 12, 51, 70, 32, 86};
	vi sorted_list = {1, 12, 25, 32, 44, 51, 63, 70, 86, 92};

	int pos = 0, target = 51;
	bool found = false;

	pos = linear_search(list, count, target);

	//=== Output
	if (pos > 0) 
		printf("Element %d at position %d \n", target, pos);
	else
		printf("Element %d not found \n", target);

}