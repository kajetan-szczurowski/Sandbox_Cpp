#include <memory>
#include <iostream>

struct Node {
	int value;
	std::unique_ptr<Node> next;

	Node(int initialValue) {
		value = initialValue;
	}

	Node() {
		value = 0;
	}
};

Node makeNewNode(int value) {
	Node newNode;
	newNode.value = value;
	return newNode;
}

void workWithLinkedList() {
	//std::cout << "Hi \n";
	Node node1 = makeNewNode(5);
	//Node node2 = makeNewNode(8);
	//std::cout << node1.value;
	std::unique_ptr<Node> start = std::make_unique<Node>(8);
	start->next = std::make_unique<Node>(8);
	
	std::unique_ptr<Node> currentNode = start;

	std::cout << currentNode->value << " \n";
	currentNode = currentNode->next;

	std::cin.get();
}