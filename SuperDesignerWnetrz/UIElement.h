#pragma once
#pragma once
#include "Element.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string>
#include <iostream>
#include <vector>

using namespace sf;
using namespace std;

class UIElement : public Element, public Drawable
{
public:
	UIElement() = default;
	UIElement(unsigned int width, unsigned int height, unsigned int x_axis, unsigned int y_axis, Color myColor,
		unsigned int textSize, Color tColor, Text::Style tBold, Text::Style tUnderline, int ouThick, Color ouColor, string message);
	RectangleShape getInteractionWindow();
	Text getText();
	UIElement* next = nullptr;
	RectangleShape interactionWindow;
	bool whenMouseOverMe();
	virtual void draw(RenderTarget& target, RenderStates state) const override;
protected:
	void setText(const string myMes, unsigned int mySize, Color color, Text::Style ifBold, Text::Style ifUnderline);
	void setShape(unsigned int width, unsigned int height, unsigned int x_axis, unsigned int y_axis, float degrees, Color myColor);
	void setSize(unsigned int width, unsigned int height);
	void setOffset(unsigned int x_axis, unsigned int  y_axis);
	void setRotation(float degrees);
	void setColor(Color myColor);
	//private:
	Text myText;
	Vector2f size;//wektor okreslajacy wysokosc i szerokosc obiektu
//	Color myColor;
	Font myFont;
};