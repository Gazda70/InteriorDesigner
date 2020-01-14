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
protected:
	Element() = default;
	Element(unsigned int width, unsigned int height, unsigned int x_axis, unsigned int y_axis, float degrees, Color myColor);
	unsigned int width;
	unsigned int height;
	unsigned int x_axis;
	unsigned int y_axis;
	float degrees;
	Color myColor;
private:
	virtual void setSize(unsigned int width, unsigned int height) = 0;
	virtual void setOffset(unsigned int x_axis, unsigned int  y_axis) = 0;
	virtual void setRotation(float degrees) = 0;
	virtual void setColor(Color myColor) = 0;
};