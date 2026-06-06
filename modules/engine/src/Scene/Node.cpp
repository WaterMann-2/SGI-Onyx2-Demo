//
// Created by robsc on 6/6/26.
//

#include "../../include/Scene/Node.h"

#include <functional>
#include <stdexcept>


namespace SpEngine {
std::shared_ptr<Node> Node::GetParent() {
	return Parent;
}

std::vector<std::shared_ptr<Node>>& Node::GetChildren(){
	return Children;
}

void Node::addChild(std::shared_ptr<Node> childNode) {
	constexpr int maxDepth = 1000;
	const Node* self = this;

	std::shared_ptr<Node> currentParent = childNode->Parent;
	for (int i = 0; i < maxDepth; ++i) {
		if (currentParent.get() == self) {
			throw std::runtime_error("Cannot add a parent/grandparent as child! Node::addChild()");
		}
		if (currentParent.get() == nullptr) {
			Children.push_back(childNode);
			return;
		}
		currentParent = currentParent->Parent;
	}
}

} // SpEngine