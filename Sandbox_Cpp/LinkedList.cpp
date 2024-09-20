#include <memory>
#include <iostream>

struct Node {
	int value;
	std::unique_ptr<Node> next;
	Node(int initialValue = 0) : value{ initialValue }, next{ nullptr } {}
};

class SinglyLinkedList {
public:

	SinglyLinkedList() : head{ nullptr } {};


	void insertAtEnd(int value) {
		std::unique_ptr<Node> newNode{ std::make_unique<Node>(value) };
		if (!head) {
			head = std::move(newNode);
			return;
		}

		Node* lastNode = getLastNode();
		lastNode->next = std::move(newNode);
	}

	void insertAtBeginning(int value) {
		std::unique_ptr<Node> newNode{ std::make_unique<Node>(value) };
		if (!head) {
			head = std::move(newNode);
			return;
		}
		newNode->next = std::move(head);
		head = std::move(newNode);
	}

	Node* getHead() {
		return head.get();
	}

	void printList() {
		iterate(PRINT);
	}
	

private:
	std::unique_ptr<Node> head;

	const enum ITERATION_ORDERS { PRINT, FIND, FIND_LAST };

	Node* iterate(enum ITERATION_ORDERS order = FIND_LAST, unsigned index = -1) {
		if (!head) return nullptr;
		std::unique_ptr<Node> temporary;
		Node* current = head.get();
		while (current != nullptr) {
			if (order == PRINT) std::cout << current->value << " -> "; //TODO: remove arrow from last element
			if (!current->next) return current;
			current = current->next.get();
		}
		return nullptr;
	}

	Node* getLastNode() {
		return iterate();

	}


};




void workWithLinkedList() {

	SinglyLinkedList myList;
	myList.insertAtEnd(28);
	myList.insertAtEnd(13);
	myList.insertAtBeginning(41);
	myList.insertAtEnd(7);
	//std::cout << myList.getHead()->value;
	myList.printList();

	std::cin.get();
}