#ifndef _HIERARCHY_WINDOW_H_
#define _HIERARCHY_WINDOW_H_

#include"3DObjects/BuiltInCylinderObj.h"
#include"3DObjects/BuiltInSphereObj.h"
#include"3DObjects/BuiltInCubeObj.h"
#include"3DObjects/LoadedModelObj.h"
#include "SKybox.h"
//#include"3DObjects/FBX_importer.h"
#include"Lights/Light.h"

class HierarchyWindow {
public:
	HierarchyWindow();
	void createOBJ(int type);
	void drawList(glm::mat4* modelArray, glm::mat4& view, glm::mat4& projection, glm::mat4& location,
		glm::vec3 camPosition, glm::vec3 lightPosition, glm::mat4& lightSpace, Shadow* shadow, Animation* animation);

	unsigned int objectNum;

	std::vector<OBJect*> activeOBJList;
};


#endif