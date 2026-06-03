//
// Created by robsc on 6/2/26.
//

#ifndef SILICONGRAPHICS_PROPERTIES_H
#define SILICONGRAPHICS_PROPERTIES_H

#include <memory>
#include <glm/gtc/quaternion.hpp>

namespace SpEngine {

class Transform {
public:
	glm::vec3 position;
	glm::vec3 scale;
	glm::quat rotation;


	Transform();
	~Transform();

	void setParent(Transform* parent);
	std::shared_ptr<Transform> getParent();

	glm::vec3 getLocalPosition();



private:
	std::shared_ptr<Transform> parent_{};



};

}

#endif //SILICONGRAPHICS_PROPERTIES_H
