#pragma once
#include "UIElement.h"
#include "Furniture.h"
#include "Button.h"

class DropDownList : public UIElement
{

public:
	DropDownList(unsigned int width, unsigned int height, unsigned int x_axis, unsigned int y_axis, Color myColor,
		unsigned int textSize, Color tColor, Text::Style tBold, Text::Style tUnderline, int ouThick, Color ouColor);
	void manageMouseInput(Vector2i mousePos);
	bool isActivated();
	void addPart(string another,Color myColor, Furniture* toFollow);
	void drawMe(RenderWindow & window, RenderStates state);
	void setGlobalTarget(Furniture* toFollow);
	Furniture* chosen;
	vector<Element*> ourlist;
	listType getType();
private:
	bool activated;
	listType ourType;
	unsigned int textSize;
	unsigned int helpy;
	unsigned int helpx;
	Color tColor;
	Text::Style tBold;
	Text::Style tUnderline;
	int ouThick;
	Color ouColor;
};