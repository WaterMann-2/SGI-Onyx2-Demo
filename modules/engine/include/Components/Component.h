//
// Created by robsc on 6/3/26.
//

#ifndef SILICONGRAPHICS_COMPONENT_H
#define SILICONGRAPHICS_COMPONENT_H
#include <memory>

namespace SpEngine {
class Scene;
}

namespace SpEngine {

class Component {
public:
	Component() = default;
	virtual ~Component() = default;
	Component(SpEngine::Scene& scene);

	virtual void Start();

	virtual void OnTick(const double& deltaTime);

protected:



private:
	std::shared_ptr<SpEngine::Scene> scene;

};

}

#endif //SILICONGRAPHICS_COMPONENT_H
