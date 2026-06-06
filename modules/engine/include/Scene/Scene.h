//
// Created by robsc on 6/6/26.
//

#ifndef SILICONGRAPHICS_SCENE_H
#define SILICONGRAPHICS_SCENE_H
#include <vector>

#include "../Components/Component.h"
#include "Node.h"

namespace SpEngine {
class Scene {
public:


	void addComponent(Component component, std::unique_ptr<Node> node);
private:
	std::vector<std::shared_ptr<Component>> components;

};
} // SpEngine

#endif //SILICONGRAPHICS_SCENE_H
