//
// Created by robsc on 6/2/26.
//

#include "include/properties/Properties.h"

namespace SpEngine {
Transform::Transform():
	position(0.0f),
	scale(1.0f),
	rotation(glm::quat(1.0f, 0.0f, 0.0f, 0.0f)){

}

Transform::~Transform() = default;

void Transform::setParent(Transform* parent) {
	parent_.reset(parent);
}

std::shared_ptr<Transform> Transform::getParent() {
	return parent_;
}

glm::vec3 Transform::getLocalPosition() {
	if (parent_) {
		const glm::vec3 result = position - parent_->position;
		return result;
	}
	return position;


}


}
