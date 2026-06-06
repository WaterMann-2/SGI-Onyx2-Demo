//
// Created by robsc on 6/6/26.
//

#ifndef SILICONGRAPHICS_NODE_H
#define SILICONGRAPHICS_NODE_H

#include <vector>
#include <memory>
#include <../../engine/include/Components/Component.h>


namespace SpEngine {
class Scene;

class Node {
public:


	void addComponent(Component& component);

	std::shared_ptr<Node> GetParent();
	std::vector<std::shared_ptr<Node>>& GetChildren();

	void addChild(std::shared_ptr<Node> childNode);
private:
	bool isTopLevel = false;
	std::shared_ptr<Scene> rootScene;

	std::shared_ptr<Node> Parent;
	std::vector<std::shared_ptr<Node>> Children;
};

} // SpEngine

#endif //SILICONGRAPHICS_NODE_H
