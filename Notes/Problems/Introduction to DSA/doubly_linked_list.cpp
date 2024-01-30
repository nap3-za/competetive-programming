#include <bits/stdc++.h>
#include <vector>
using namespace std;

typedef vector<int> vi;


class Node {

public:
	int value;
	Node* previous;
	Node* next;
};

vi DoublyLinkedList(Node* node, bool foward) {
	vi doulby_linked_list;
	
	if (foward) {
		while (node != NULL) {
			doulby_linked_list.push_back(node -> value);
			node = node -> next;
		}
	} else {
		while (node != NULL) {
			doulby_linked_list.push_back(node -> value);
			node = node -> previous;
		}	
	}

	return doulby_linked_list;
}

void ListAdd(Node* end_node, Node* new_node) {

	if (end_node -> previous == NULL) {
		new_node -> previous = end_node;
		new_node -> next = end_node -> next;

		end_node -> next -> previous = new_node;
		end_node -> next = new_node;
	} else	if (end_node -> next == NULL) {
		new_node -> next = end_node;
		new_node -> previous = end_node -> previous;

		end_node -> previous -> next = new_node;
		end_node -> previous = new_node;
	}
}

int main() {

	Node* head = new Node();
	head -> value = 1;
	head -> previous = NULL;

	Node* second = new Node();
	second -> value = 3;
	head -> next = second;
	second -> previous = head;

	Node* third = new Node();
	third -> value = 5;
	second -> next = third;
	third -> previous = second;

	Node* fourth = new Node();
	fourth -> value = 2;
	third -> next = fourth;
	fourth -> previous = third;

	fourth -> next = NULL;

	printf("Foward Doubly Linked List Pre-Addition \n");
	vi foward_linked_list = DoublyLinkedList(head, true);
	for (int index=0; index<foward_linked_list.size(); index++) {
		printf("%d : %d \n", index+1, foward_linked_list[index]);
	}

	Node* new_node = new Node();
	new_node -> value = 4;
	ListAdd(fourth, new_node);

	printf("Foward Doubly Linked List Post-Addition \n");
	foward_linked_list = DoublyLinkedList(head, true);
	for (int index=0; index<foward_linked_list.size(); index++) {
		printf("%d : %d \n", index+1, foward_linked_list[index]);
	}

	printf("\n");

	printf("Backwards Doubly Linked List Pre-Addition \n");
	vi backwards_linked_list = DoublyLinkedList(fourth, false);
	for (int index=0; index<backwards_linked_list.size(); index++) {
		printf("%d : %d \n", index+1, backwards_linked_list[index]);
	}

	Node* new_new_node = new Node();
	new_new_node -> value = 4;
	ListAdd(head, new_new_node);

	printf("Backwards Doubly Linked List Post-Addition\n");
	backwards_linked_list = DoublyLinkedList(fourth, false);
	for (int index=0; index<backwards_linked_list.size(); index++) {
		printf("%d : %d \n", index+1, backwards_linked_list[index]);
	}


	return 0;

}