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
	void drawOnScene(RenderWindow& window);
	void removeFromScene(Furniture* toRemove);
private:
	vector<Furniture*> zbiorMebli;
	vector<Furniture*> naScenie;
	UI* projectInterface;
	Plane* projectPlane;
	UIPart mySwitch;
	RenderWindow* window;
	unsigned int screen_res_width;
	unsigned int screen_res_height;
	bool mouseGuide;
};