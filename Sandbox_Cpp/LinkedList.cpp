#include <memory>
#include <iostream>
#include <string>

template <typename T> class SinglyLinkedList {

	struct Node {
		T value;
		std::unique_ptr<Node> next;
		Node(T initialValue = 0) : value{ initialValue }, next{ nullptr } {}
	};

public:

	SinglyLinkedList() : head{ nullptr }, length{0} {};


	void insertAtEnd(T value) {
		length++;
		std::unique_ptr<Node> newNode{ std::make_unique<Node>(value) };
		if (!head) {
			head = std::move(newNode);
			return;
		}

		Node* lastNode = getLastNode();
		lastNode->next = std::move(newNode);
	}

	void insertAtBeginning(T value) {
		length++;
		std::unique_ptr<Node> newNode{ std::make_unique<Node>(value) };
		if (!head) {
			head = std::move(newNode);
			return;
		}
		newNode->next = std::move(head);
		head = std::move(newNode);
	}

	void insertAtPosition(T value, short position) {
		if (position < 0) return;
		if (position == 0) {
			insertAtBeginning(value);
			return;
		}
		if (position >= length) {
			insertAtEnd(value);
			return;
		}
		length++;
		std::unique_ptr<Node> newNode{ std::make_unique<Node>(value) };
		Node* previousNode = iterate(FIND, position -1);
		std::unique_ptr<Node> nextNode = std::move(previousNode->next);
		newNode.get()->next = std::move(nextNode);
		previousNode->next = std::move(newNode);
	}

	void removeFromEnd() {
		if (head == nullptr) return;
		if (length == 1) {
			head = nullptr;
			return;
		}
		Node* newLastNode = iterate(FIND, length - 2);
		std::cout << newLastNode->value;
		newLastNode->next = nullptr;
	}

	Node* getHead() {
		return head.get();
	}

	void printList() {
		iterate(PRINT);
	}
	

private:
	std::unique_ptr<Node> head;
	unsigned short length;

	const enum ITERATION_ORDERS { PRINT, FIND, FIND_LAST };

	Node* iterate(enum ITERATION_ORDERS order = FIND_LAST, short position = -1) {
		if (!head) return nullptr;
		short currentNodeIndex = 0;
		std::unique_ptr<Node> temporary;
		Node* current = head.get();
		if (order == FIND && position <= 0) return current;
		while (current != nullptr) {
			if (order == FIND && position == currentNodeIndex) return current;
			if (order == PRINT) std::cout << current->value << " -> "; //TODO: remove arrow from last element
			if (!current->next) return current;
			current = current->next.get();
			currentNodeIndex++;
		}
		return nullptr;
	}

	Node* getLastNode() {
		return iterate();

	}


};




void workWithLinkedList() {

	//SinglyLinkedList<int> myList;
	//myList.insertAtEnd(28);
	//myList.insertAtEnd(13);
	//myList.insertAtBeginning(41);
	//myList.insertAtEnd(7);
	//myList.printList();

	//std::cout << std::endl;

	//SinglyLinkedList<std::string> textList;
	//textList.insertAtEnd("Hi");
	//textList.insertAtEnd("I am a text Linked List");
	//textList.insertAtEnd("My name is Andrew");
	//textList.printList();

	SinglyLinkedList<int> intList;
	intList.insertAtEnd(5);
	intList.printList();
	std::cout << std::endl;

	intList.removeFromEnd();
	std::cout << std::endl;
	intList.insertAtEnd(6);
	intList.printList();
	std::cout << std::endl;
	intList.removeFromEnd();
	std::cout << std::endl;

	intList.insertAtEnd(8);
	intList.removeFromEnd();
	std::cout << std::endl;

	intList.printList();
	std::cout << std::endl;
	intList.insertAtPosition(2, 0);
	intList.insertAtPosition(16, 1);
	intList.insertAtPosition(100, 800);
	intList.insertAtPosition(64, 3);
	intList.printList();
	std::cout << std::endl;

	intList.removeFromEnd();
	



	std::cin.get();
}