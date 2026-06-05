//
// Created by robsc on 6/3/26.
//

#ifndef SILICONGRAPHICS_COMPONENT_H
#define SILICONGRAPHICS_COMPONENT_H


namespace SpComponent {

class Component {
public:
	Component() = default;
	virtual ~Component() = default;

	virtual void Start();

	virtual void OnTick(const double& deltaTime);

protected:



private:


};

}

#endif //SILICONGRAPHICS_COMPONENT_H
