#pragma once
#include "UIElement.h"
#include "Furniture.h"

class Button :
	public UIElement
{
public:
	Button(unsigned int width, unsigned int height, unsigned int x_axis, unsigned int y_axis, Color myColor,
		unsigned int textSize, Color tColor, Text::Style tBold, Text::Style tUnderline, int ouThick, Color ouColor, string message, Furniture* toactivate);
	Furniture* getAct();
	void setAct(Furniture* toFollow);
	Color getMyColor();
private:
	Furniture* toActivate;
};

