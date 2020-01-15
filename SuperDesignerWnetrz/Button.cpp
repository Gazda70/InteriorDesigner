#include "Button.h"

Button::Button(unsigned int width, unsigned int height, unsigned int x_axis, unsigned int y_axis, 
	Color myColor, unsigned int textSize, Color tColor, Text::Style tBold, 
	Text::Style tUnderline, int ouThick, Color ouColor, string message, Furniture* toactivate):UIElement(width,height,x_axis,y_axis,
		myColor,textSize,tColor,tBold,
		tUnderline,ouThick,ouColor,message)
{
	this->toActivate = toactivate;
}

Furniture * Button::getAct()
{
	return this->toActivate;
}

void Button::setAct(Furniture * toFollow)
{
	toActivate = toFollow;
}

Color Button::getMyColor()
{
	return this->myColor;
}
