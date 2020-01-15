#include "UIElement.h"

void UIElement::setOffset(unsigned int x_axis, unsigned int  y_axis)
{
	interactionWindow.setPosition(x_axis, y_axis);
}

void UIElement::setColor(Color myColor)
{
	interactionWindow.setFillColor(myColor);
}

RectangleShape UIElement::getInteractionWindow()
{
	RectangleShape shape = this->interactionWindow;
	return shape;
}
Text UIElement::getText()
{
	Text text = this->myText;
	return text;
}
void UIElement::setSize(unsigned int width, unsigned int height)
{
	Vector2f create;
	create.x = width;
	create.y = height;
	interactionWindow.setSize(create);
}
void UIElement::setRotation(float degrees)
{
	interactionWindow.setRotation({ degrees });
}
void UIElement::setText(const string myMes, unsigned int mySize, Color color, Text::Style ifBold, Text::Style ifUnderlined)
{
	myText.setFont(myFont);
	// set the string to display
	myText.setString(myMes);
	// set the character size
	myText.setCharacterSize(mySize); // in pixels, not points!
	// set the color
	myText.setFillColor(color);
	// set the text style
	myText.setStyle(ifBold | ifUnderlined);
	//get the text size
	FloatRect textBounds = myText.getLocalBounds();
	//set the text origin to center
	myText.setOrigin(textBounds.width / 2, textBounds.height);
	Vector2f shapePos = this->interactionWindow.getPosition();
	FloatRect shapeBounds = this->interactionWindow.getLocalBounds();

	// set the text position
	myText.setPosition(shapePos.x + shapeBounds.width / 2, shapePos.y + shapeBounds.height / 2);
}

void UIElement::setShape(unsigned int width, unsigned int height, unsigned int x_axis, unsigned int y_axis, float degrees, Color myColor)
{
	Vector2f create;
	create.x = width;
	create.y = height;
	interactionWindow.setSize(create);
	interactionWindow.setPosition(x_axis, y_axis);
	interactionWindow.setFillColor(myColor);
	interactionWindow.setRotation({ degrees });
}

bool UIElement::whenMouseOverMe()
{
	if (this->myText.getString() == "Ksztalty")
	{
		return true;
	}
	else
	{
		return false;
	}
}

void UIElement::draw(RenderTarget & target, RenderStates state) const
{
	target.draw(this->interactionWindow, state);
	target.draw(this->myText, state);
}
UIElement::UIElement(unsigned int width, unsigned int height, unsigned int x_axis, unsigned int y_axis, Color myColor,
	unsigned int textSize, Color tColor, Text::Style tBold, Text::Style tUnderline, int ouThick, Color ouColor, string message)
{
	if (!this->myFont.loadFromFile(fontFile))
	{
		cout << "Niepoprawny plik czcionki!" << endl;
	}
	setShape(width, height, x_axis, y_axis, degrees, myColor);
	setText(message, textSize, tColor, tBold, tUnderline);
	this->myColor = myColor;
}