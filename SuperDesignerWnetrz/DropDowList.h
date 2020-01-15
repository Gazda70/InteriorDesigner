#pragma once
#include "UIElement.h"
#include "Furniture.h"
#include "Button.h"

class DropDownList : public UIElement
{

public:
	enum listType { furnitureT, colorT };
	DropDownList(unsigned int width, unsigned int height, unsigned int x_axis, unsigned int y_axis, Color myColor,
		unsigned int textSize, Color tColor, Text::Style tBold, Text::Style tUnderline, int ouThick, Color ouColor);
	void addPart(string another,Color myColor, Furniture* toFollow);
	void drawList(vector<Button*>& myList, RenderWindow & window);
	void setGlobalTarget(Furniture* toFollow);
	Furniture* goThrough(Vector2i mouse,listType change);
	vector<Button*> ourlist;
private:
	Color myColor;
	unsigned int textSize;
	unsigned int helpy;
	unsigned int helpx;
	Color tColor;
	Text::Style tBold;
	Text::Style tUnderline;
	int ouThick;
	Color ouColor;
};