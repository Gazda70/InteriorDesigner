#include "Button.h"

Button::Button(unsigned int width, unsigned int height, unsigned int x_axis, unsigned int y_axis, 
	Color myColor, unsigned int textSize, Color tColor, Text::Style tBold, 
	Text::Style tUnderline, int ouThick, Color ouColor, string message, Furniture* toactivate):UIElement(width,height,x_axis,y_axis,
		myColor,textSize,tColor,tBold,
		tUnderline,ouThick,ouColor,message)
{
	this->toActivate = toactivate;
	this->myColor = myColor;
}

void Button::manageInput(Vector2i mousePos, Keyboard pressed, change mode)
{
	if (this->getInteractionWindow().getGlobalBounds()
		.contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
	{
		activate = 1;
	}
	else
	{
		activate = 0;
	}
}

Element* Button::manageScreenBehaviour(change mode)
{
		return this->toActivate;
}

void Button::setColor(Color & myColor, change mode)
{
	if (mode == set)
	{
		myColor = this->myColor;
	}
	else if (mode == dflt)
	{
		this->myColor = myColor;
	}
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
