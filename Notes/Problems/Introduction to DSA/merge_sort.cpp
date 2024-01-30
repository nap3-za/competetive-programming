#include <bits/stdc++.h> 
#include <vector>
using namespace std;

typedef vector<int> vi;

vi merge(vi left_half, vi right_half) {
	vi merged;

	while (left_half.size() > 0 || right_half.size() > 0) {

		if (left_half.size() > 0 && right_half.size() > 0) {
			if (left_half[0] > right_half[0]) {
				merged.push_back(left_half[0]);
				left_half.erase(left_half.begin());

			} else if (left_half[0] < right_half[0]) {
				merged.push_back(right_half[0]);
				right_half.erase(right_half.begin());

			} else if (left_half[0] == right_half[0]) {
				merged.push_back(left_half[0]);
				left_half.erase(left_half.begin());

				merged.push_back(right_half[0]);
				right_half.erase(right_half.begin());
			}
		} else if (left_half.size() > 0) {
			merged.push_back(left_half[0]);
			left_half.erase(left_half.begin());

		} else if (right_half.size() > 0) {
			merged.push_back(right_half[0]);
			right_half.erase(right_half.begin());
		}
	}

	return merged;
}

vi merge_sort(vi list) {

	if (list.size() == 1) 
		return list;

	vi left_copy = list;
	vi right_copy = list;

	int middle = round(list.size()/2);

	left_copy.erase(left_copy.begin()+middle, left_copy.end());
	vi left_half = merge_sort(left_copy);

	right_copy.erase(right_copy.begin(), right_copy.begin()+middle);
	vi right_half = merge_sort(right_copy);

	return merge(left_half, right_half);
}


int main() {

	vi list = {13,3,5,1,33,25,102,86};
	for (int item : merge_sort(list)) {
		printf("Item : %d \n", item);
	}

}