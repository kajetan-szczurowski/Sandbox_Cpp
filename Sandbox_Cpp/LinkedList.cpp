#include <memory>
#include <iostream>

struct Node {
	int value;
	std::unique_ptr<Node> next;
};

Node makeNewNode(int value) {
	Node newNode;
	newNode.value = value;
	return newNode;
}

void workWithLinkedList() {
	std::cout << "Hi \n";
	Node node1 = makeNewNode(5);
	Node node2 = makeNewNode(8);
	node1.next = std::make_unique<Node>(node2);
	Node* currentNode = &node1;
	std::cout << currentNode->value << " \n";

	std::cin.get();
}