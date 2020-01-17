#pragma once
#pragma once
#include "Element.h"
#include "Enums.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string>
#include <iostream>
#include <vector>

using namespace sf;
using namespace std;

class UIElement : public Element
{
public:
	UIElement() = default;
	UIElement(unsigned int width, unsigned int height, unsigned int x_axis, unsigned int y_axis, Color myColor,
		unsigned int textSize, Color tColor, Text::Style tBold, Text::Style tUnderline, int ouThick, Color ouColor, string message);
	void manageInput(Vector2i mousePos, Keyboard::Key pressed);
	void manageScreenBehaviour(Element* toManage, change mode);
	void setPosition(Vector2i position);
	void drawMe(RenderWindow& window, RenderStates state);
	bool isActivated();
	RectangleShape getInteractionWindow();
	Text getText();
	RectangleShape interactionWindow;
	bool whenMouseOverMe();
protected:
	void setText(const string myMes, unsigned int mySize, Color color, Text::Style ifBold, Text::Style ifUnderline);
	void setShape(unsigned int width, unsigned int height, unsigned int x_axis, unsigned int y_axis, float degrees, Color myColor);
	void setSize(unsigned int width, unsigned int height);
	void setOffset(unsigned int x_axis, unsigned int  y_axis);
	void setRotation(float degrees);
	void setColor(Color myColor);
	Text myText;
	Vector2f size;
	Font myFont;
private:
	bool activate;
};