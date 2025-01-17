#pragma once
#include "Furniture.h"
#include "UI.h"
#include "Plane.h"

class Project
{
public:
	Project(unsigned int screen_res_width, unsigned int screen_res_height, string fileName);
	void addFurniture(string textureFile, change mode);
	void runProject(RenderWindow& window);
	void drawOnScene(RenderWindow& window);
	void removeFromScene(Element* toRemove);
private:
	vector<Element*> zbiorMebli;
	vector<Element*> naScenie;
	UI* projectInterface;
	Plane* projectPlane;
	change mySwitch;
	RenderWindow* window;
	unsigned int screen_res_width;
	unsigned int screen_res_height;
	bool mouseGuide;
	string fileName;
};