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
	void manageInput(Vector2i mousePos, Keyboard::Key pressed, change mode);
	Element* manageScreenBehaviour(change mode);
	void drawMe(RenderWindow& window, RenderStates state);
	void setPosition(Vector2i position);
	void setColor(Color& myColor, change mode);
	bool isActivated();
	istream& operator>>(istream& is);
	ostream& operator<<(ostream& os);
	RectangleShape getInteractionWindow();
protected:
	void setText(const string myMes, unsigned int mySize, Color color, Text::Style ifBold, Text::Style ifUnderline);
	void setShape(unsigned int width, unsigned int height, unsigned int x_axis, unsigned int y_axis, float degrees, Color myColor);
	RectangleShape interactionWindow;
	Text myText;
	Font myFont;
	bool activate;
};