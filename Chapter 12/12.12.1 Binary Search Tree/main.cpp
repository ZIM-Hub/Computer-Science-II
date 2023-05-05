
#include "Node.h"
#include <iostream>

using namespace std;

Node::Node(int t_data, Node* t_left, Node* t_right) {
	data = t_data;
	left = t_left;
	right = t_right;
}

void Node::insert(int new_data) {
	if (new_data < data) {
		if (left == nullptr) {
			left = new Node(new_data);
		} else {
			left->insert(new_data);
		}
	} else {
		if (right == nullptr) {
			right = new Node(new_data);
		} else {
			right->insert(new_data);
		}
	}
}

bool Node::isLeaf() {
	return left == nullptr && right == nullptr;
}

uint32_t Node::height() {
	if (isLeaf()) {
		return 0;
	}
	uint32_t leftHeight = left == nullptr ? 0 : left->height();
	uint32_t rightHeight = right == nullptr ? 0 : right->height();
	return 1 + max(leftHeight, rightHeight);
}

bool Node::isFull(){
	if (left == nullptr && right == nullptr) {
		return true;
	}
	else if (left != nullptr && right != nullptr) {
		return left->isFull() && right->isFull();
	}
	else {
		return false;
	}
}
uint32_t Node::countNodes() {
	uint32_t count = 1;
	if (left != nullptr) {
		count += left->countNodes();
	}
	if (right != nullptr) {
		count += right->countNodes();
	}
	return count;
}
