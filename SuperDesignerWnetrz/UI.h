#pragma once
#include "DropDowList.h"
#include "Furniture.h"
#include "Plane.h"
#include "UIPart.h"

class UI
{
public:
	UI() = default;
	UI(unsigned int res_x, unsigned int res_y);
	void createMainMenu();
	void createWorkplace();
	void displayCurrent(UIPart current, RenderWindow& window, Plane &myPlane, bool showList, Furniture* testowy);
	int indexList(UIPart current, RenderWindow& window, Vector2i mousePos);
	bool showList;
	bool isMouseOverHim(UIPart current, RenderWindow& window, Vector2i mousePos);
	vector<UIElement*>& getList(UIPart current);
	DropDownList* furnitureList;
private:
	vector<UIElement*> mainMenu;
	vector<UIElement*> workPlace;
	unsigned int res_x;
	unsigned int res_y;
	void displayUI(vector<UIElement*>& myList, RenderWindow& window);
};
