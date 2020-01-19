#include "UIElement.h"

void UIElement::setColor(Color& myColor, change mode)
{
	interactionWindow.setFillColor(myColor);
}

RectangleShape UIElement::getInteractionWindow()
{
	RectangleShape shape = this->interactionWindow;
	return shape;
}

void UIElement::setText(const string myMes, unsigned int mySize, Color color, Text::Style ifBold, Text::Style ifUnderlined)
{
	myText.setFont(myFont);
	myText.setString(myMes);
	myText.setCharacterSize(mySize); 
	myText.setFillColor(color);
	myText.setStyle(ifBold | ifUnderlined);
	FloatRect textBounds = myText.getLocalBounds();
	myText.setOrigin(textBounds.width / 2, textBounds.height/1.5);
	Vector2f shapePos = this->interactionWindow.getPosition();
	FloatRect shapeBounds = this->interactionWindow.getLocalBounds();
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

bool UIElement::isActivated()
{
	return activate;
}

istream & UIElement::operator>>(istream & is)
{
	return is;
}

ostream & UIElement::operator<<(ostream & os)
{
	return os;
}

void UIElement::setPosition(Vector2i position)
{
	Vector2f temp{ static_cast<float>(position.x),static_cast<float>(position.y) };
	this->interactionWindow.setPosition(temp);
}


void UIElement::drawMe(RenderWindow& window, RenderStates state)
{
	window.draw(this->interactionWindow, state);
	window.draw(this->myText, state);
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

void UIElement::manageInput(Vector2i mousePos, Keyboard::Key pressed, change mode)
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
Element* UIElement::manageScreenBehaviour(change mode)
{
	return nullptr;
}
