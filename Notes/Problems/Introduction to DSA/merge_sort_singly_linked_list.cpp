#include <bits/stdc++.h>
#include <vector>
#include "singly_linked_list.h"
using namespace std;

typedef vector<int> vi;


SinglyLinkedList merge(SinglyLinkedList left_half, SinglyLinkedList right_half) {
	SinglyLinkedList merged_list;

	Node* left_node;
	Node* right_node;

	left_node = left_half.head;
	right_node = right_half.head;

	while (left_node || right_node) {
		if (left_node && right_node) {
			if (left_node -> value > right_node -> value) {
				merged_list.append(left_node -> value);
				left_node = left_node -> next;

			} else if (left_node -> value < right_node -> value) {
				merged_list.append(right_node -> value);
				right_node = right_node -> next;

			} else if (right_node -> value == left_node -> value) {
				merged_list.append(left_node -> value);
				merged_list.append(right_node -> value);

				left_node = left_node -> next;
				right_node = right_node -> next;
			}

		} else if (left_node == NULL && right_node) {
			merged_list.append(right_node -> value);
			right_node = right_node -> next;

		} else if (left_node && right_node == NULL) {
			merged_list.append(left_node -> value);
			left_node = left_node -> next;
		}
	}

	return merged_list;
}

// O(n log(n))
SinglyLinkedList merge_sort(SinglyLinkedList list,  int size) {

	// Base case
	if (size == 1) return list;

	// Else merge sort the halves of the list
	int middle = round(size/2);

	SinglyLinkedList left_half = merge_sort(list.split(0, middle-1), middle);
	SinglyLinkedList right_half = merge_sort(list.split(middle, size-1), size-middle);

	return merge(left_half, right_half);
}


int main() {

	SinglyLinkedList sl_list;
	sl_list.append(5);
	sl_list.append(1);
	sl_list.append(10);
	sl_list.append(16);
	sl_list.append(8);
	sl_list.append(23);

	printf("Pre-Sorting \n");
	for (int node : sl_list.get_list()) {
		printf("Node : %d \n", node);
	}

	sl_list = merge_sort(sl_list, sl_list.size());
	printf("\n");

	printf("Post-Sorting \n");
	for (int node : sl_list.get_list()) {
		printf("Node : %d \n", node);
	}

	return 0;
}
