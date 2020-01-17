#include "Button.h"

Button::Button(unsigned int width, unsigned int height, unsigned int x_axis, unsigned int y_axis, 
	Color myColor, unsigned int textSize, Color tColor, Text::Style tBold, 
	Text::Style tUnderline, int ouThick, Color ouColor, string message, Furniture* toactivate):UIElement(width,height,x_axis,y_axis,
		myColor,textSize,tColor,tBold,
		tUnderline,ouThick,ouColor,message)
{
	this->toActivate = toactivate;
}

void Button::manageInput(Vector2f mousePos, Keyboard pressed)
{
}

void Button::manageScreenBehaviour(Element* toManage, change mode)
{

	if (mode == furnitureT)
	{
		toManage = toActivate;
	}
	else if (mode == colorT)
	{
		toManage->setColor(myColor);
		toManage = nullptr;
	}
	else if (mode == set)
	{
		this->toActivate = toManage;
	}
}
void Button::setColor(Color myColor)
{
	this->myColor = myColor;
}
void Button::setAct(Furniture * toFollow)
{
	toActivate = toFollow;
}
void Button::drawMe(RenderWindow & window, RenderStates state)
{
	window.draw(this->interactionWindow, state);
	window.draw(this->myText, state);
}
