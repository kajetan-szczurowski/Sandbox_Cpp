#include <memory>
#include <iostream>
#include <string>
#include <vector>

template <typename T> class SinglyLinkedList {

	struct Node {
		T value;
		std::unique_ptr<Node> next;
		Node(T initialValue = 0) : value{ initialValue }, next{ nullptr } { }
		//Node(T initialValue = 0) : value{ initialValue }, next{ nullptr } { std::cout << "Creating Node" << std::endl; }
		//~Node() {std::cout << "Destroying Node" << std::endl; }
	};

public:

	SinglyLinkedList() : head{ nullptr }, length{0} {};
	SinglyLinkedList(std::vector<T> initialVector) {
		head = nullptr;
		for (T value : initialVector) insertAtEnd(value);
	}

	~SinglyLinkedList() { while (head) head = std::move(head->next); }


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
		length--;
		if (length == 0) {
			head = nullptr;
			return;
		}
		Node* newLastNode;
		if (length > 1) newLastNode = iterate(FIND, length - 1);
		else newLastNode = head.get();

		newLastNode->next = nullptr;
	}

	void removeFromBeginning() {
		if (head == nullptr) return;
		length--;
		if (length == 0) {
			head = nullptr;
			return;
		}
		head = std::move(head.get()->next);
	}

	void removeFromPosition(short position) {
		if (position < 0) return;
		if (head == nullptr) return;
		if (length == 1) {
			removeFromBeginning();
			return;
		}
		if (position >= length) {
			removeFromEnd();
			return;
		}
		length--;
		Node* previousNode = iterate(FIND, position - 1);
		previousNode->next = std::move(previousNode->next.get()->next);
	}

	Node* getHead() {
		return head.get();
	}

	void printList() {
		if (!length) {
			std::cout << "List is empty \n";
			return;
		}
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

	SinglyLinkedList<int> intList;
	intList.insertAtEnd(6);
	intList.insertAtEnd(2);
	intList.insertAtEnd(8);
	intList.insertAtEnd(14);
	intList.insertAtEnd(6);
	intList.printList();
	std::cout << std::endl;

	intList.removeFromPosition(1);
	intList.printList();
	std::cout << std::endl;

	std::vector<int> myVector = { 4, 2, 0, 16, 24, 85, 76 };
	SinglyLinkedList<int> vectorList(myVector);
	vectorList.printList();


}