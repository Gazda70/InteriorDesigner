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
	void displayCurrent(change current, RenderWindow& window, Plane &myPlane, bool showList);
	int indexList(change current, RenderWindow& window, Vector2i mousePos);
	bool showFurnitureList;
	bool showColorList;
	vector<Element*>& getList(change current);
	DropDownList* furnitureList;
	DropDownList* colorList;
private:
	vector<Element*> mainMenu;
	vector<Element*> workPlace;
	unsigned int res_x;
	unsigned int res_y;
	void displayUI(vector<Element*>& myList, RenderWindow& window);
};
