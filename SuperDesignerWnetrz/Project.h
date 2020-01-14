#pragma once
#include "Furniture.h"
#include "UI.h"
#include "Plane.h"

class Project
{
public:
	Project(unsigned int screen_res_width, unsigned int screen_res_height);
	void addFurniture(string textureFile);
	void runProject(RenderWindow& window);
private:
	vector<Furniture*> zbiorMebli;
	UI* projectInterface;
	Plane* projectPlane;
	UIPart mySwitch;
	RenderWindow* window;
	unsigned int screen_res_width;
	unsigned int screen_res_height;
	bool mouseGuide;
};