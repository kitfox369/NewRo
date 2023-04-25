#include"Hierarchy.h"

HierarchyWindow::HierarchyWindow() {
	objectNum = 0;
	for(int i=0;i<10;i++)
		activeOBJList.push_back(new OBJect());
	objectNum = activeOBJList.size();
}

void HierarchyWindow::createOBJ(int type)
{
	OBJect* temp = new OBJect();
	if (type == 0) {
		temp = new BuiltInCube(0);
	}
	else if (type == 1) {
		temp = new BuiltInSphere();
	}
	else if (type == 2) {
		temp = new BuiltInCylinder();
	}
	else if (type == 3) {		//obj loader
		temp = new LoadedModelObj("../Asset/nanosuit/nanosuit.obj","modelTexture",true);
	}
	else if (type == 4) {		//Light
		temp = new Light(10,10,0);
		//Light 정보값 입력
					
	}

	activeOBJList.push_back(temp);
	objectNum = activeOBJList.size();
	if (type == 4) {
		activeLightList.push_back(activeOBJList[objectNum-1]);		//Light information in activeOBJList Slot 1
	}
	temp->id = objectNum;

	std::cout << "add:"<<temp->name << std::endl;
	
}

void HierarchyWindow::drawOutline() {

}

void HierarchyWindow::drawList(glm::mat4* modelArray, glm::mat4& view, glm::mat4& projection, glm::mat4& location, glm::vec3 camPosition, glm::vec3 lightPosition) {
	for (int i = 0; i < objectNum; i++) {
		glm::mat4 origin = glm::mat4(1.0f);
		activeOBJList[i]->RenderModel(modelArray[i], view, projection, origin, camPosition, activeLightList[0]->getPositon());
	}
}