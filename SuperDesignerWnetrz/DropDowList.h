#pragma once
#include "UIElement.h"
#include "Furniture.h"
#include "Button.h"

class DropDownList : public UIElement
{
public:
	DropDownList(unsigned int width, unsigned int height, unsigned int x_axis, unsigned int y_axis, Color myColor,
		unsigned int textSize, Color tColor, Text::Style tBold, Text::Style tUnderline, int ouThick, Color ouColor);
	void addPart(string another,Furniture* toFollow);
	void drawList(vector<Button*>& myList, RenderWindow & window);
	Furniture* goThrough(Vector2i mouse);
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