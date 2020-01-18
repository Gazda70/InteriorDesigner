#pragma once
#include "Enums.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string>
#include <iostream>
#include <vector>

constexpr const char* fontFile = "times.ttf";
constexpr const int temp_x = 1600;
constexpr const int temp_y = 900;

using namespace sf;
class Element
{
public:
	virtual void drawMe(RenderWindow& window, RenderStates state) = 0;
	virtual void manageInput(Vector2i mousePos, Keyboard::Key pressed, change mode) = 0;
	virtual Element* manageScreenBehaviour(change mode) = 0;
	virtual void setColor(Color& myColor,change mode) = 0;
	virtual bool isActivated() = 0;
	virtual void setPosition(Vector2i position) = 0;
protected:
	Element() = default;
	Element(unsigned int width, unsigned int height, unsigned int x_axis, unsigned int y_axis, float degrees, Color myColor);
	unsigned int width;
	unsigned int height;
	unsigned int x_axis;
	unsigned int y_axis;
	float degrees;
	Color myColor;
};