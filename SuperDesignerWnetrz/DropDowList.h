#pragma once
#include "UIElement.h"

class DropDownList : public UIElement
{
public:
	DropDownList(unsigned int width, unsigned int height, unsigned int x_axis, unsigned int y_axis, Color myColor,
		unsigned int textSize, Color tColor, Text::Style tBold, Text::Style tUnderline, int ouThick, Color ouColor);
	void addPart(string another);
	void drawList(vector<UIElement*>& myList, RenderWindow & window);
	vector<UIElement*> ourlist;
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
	//friend void UI::displayCurrent(UIPart current, RenderWindow &window, Plane &myPlane, bool showList, Furniture* testowy);
};