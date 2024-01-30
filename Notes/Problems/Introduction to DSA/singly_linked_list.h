#include <bits/stdc++.h>
#include <vector>
using namespace std;

typedef vector<int> vi;


class Node {

public:
	int value;
	Node* next;
};

class SinglyLinkedList {

	public:
		Node* head;
		Node* tail;

		SinglyLinkedList() {
			head = NULL;
			tail = NULL;
		}

		// Works
		void append(int new_value) {
			Node* new_node = new Node();
			new_node -> value = new_value;
			new_node -> next = NULL;

			if (head == NULL && tail == NULL) {
				head = new_node;
			} else if (head != NULL && tail == NULL) {
				head -> next = new_node;
				tail = new_node;
			} else if (head != NULL && tail != NULL) {
				tail -> next = new_node;
				tail = new_node;
			}
		}

		// Works
		vi get_list() {
			vi singly_linked_list;
			Node* node = head;

			while (node != NULL) {
				singly_linked_list.push_back(node -> value);
				node = node -> next;
			}

			return singly_linked_list;	
		}

		// Works
		int get_node(int index) {
			int counter=0;

			Node* node = head;
			while (counter < index) {
				node = node -> next;
				counter++;
			}

			return node -> value;
		}

		// Works
		int size() {
			return get_list().size();
		}

		SinglyLinkedList* split_pointer(int start_index, int end_index) {
			SinglyLinkedList* split_list;
			split_list = new SinglyLinkedList();

			int counter = start_index;
			while (counter <= end_index) {
				split_list -> append(get_node(counter));
				counter++;
			}

			return split_list;
		}

		SinglyLinkedList split(int start_index, int end_index) {
			SinglyLinkedList split_list;

			int counter = start_index;
			while (counter <= end_index) {
				split_list.append(get_node(counter));
				counter++;
			}

			return split_list;
		}

};

