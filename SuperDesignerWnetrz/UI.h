#pragma once
#include "DropDowList.h"
#include "Furniture.h"
#include "Plane.h"
#include "Enums.h"

class UI
{
public:
	UI() = default;
	UI(unsigned int res_x, unsigned int res_y);
	void createMainMenu();
	void createWorkplace();
	void displayCurrent(UIPart current, RenderWindow& window, Plane &myPlane, bool showList);
	int indexList(UIPart current, RenderWindow& window, Vector2i mousePos);
	bool showFurnitureList;
	bool showColorList;
	//bool isMouseOverHim(UIPart current, RenderWindow& window, Vector2i mousePos);
	vector<Element*>& getList(UIPart current);
	DropDownList* furnitureList;
	DropDownList* colorList;
private:
	vector<Element*> mainMenu;
	vector<Element*> workPlace;
	unsigned int res_x;
	unsigned int res_y;
	void displayUI(vector<Element*>& myList, RenderWindow& window);
};
