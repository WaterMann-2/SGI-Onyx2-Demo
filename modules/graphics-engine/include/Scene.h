//
// Created by robsc on 4/23/26.
//

#ifndef SILICONGRAPHICS_SCENE_H
#define SILICONGRAPHICS_SCENE_H

#include "properties/Properties.h"

namespace SpEngine {

class spNode {
public:
	spNode();
	~spNode();

	//TODO Do I keep global transform or add an option to move to local transform
	void SetParent(spNode parent);
	spNode* GetParent();
	
	spNode* GetChild();
	void AddChild();

	void DeleteChild();
	void DeleteAllChildren();

private:
	spNode* Parent;
	spNode** children;

	//TODO Assign transform parent to parent!
	Transform transform;
};

} // SpGL

#endif //SILICONGRAPHICS_SCENE_H
