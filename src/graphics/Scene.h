//
// Created by robsc on 4/23/26.
//

#ifndef SILICONGRAPHICS_SCENE_H
#define SILICONGRAPHICS_SCENE_H

#include "../utils/SpUtils.h"
#include "../math/Matrix.h"

namespace SpGL {

class spNode {
public:
	spNode();
	~spNode();

	//TODO Do I keep global transform or add an option to move to local transform
	void SetParent(spNode parent);
	spNode* GetParent();

	//TODO Should I set a node or a pointer to a node
	spNode* GetChild();
	void AddChild();
	void RemoveChild();

private:
	spNode* Parent;
	spNode** children;

	Matrix4f Matrix;

};

} // SpGL

#endif //SILICONGRAPHICS_SCENE_H
