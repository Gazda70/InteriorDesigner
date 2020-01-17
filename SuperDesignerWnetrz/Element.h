#pragma once
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
	virtual void manageMouseInput(Vector2i mousePos) = 0;
	virtual bool isActivated() = 0;
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