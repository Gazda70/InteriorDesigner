#include "Element.h"
Element::Element(unsigned int width, unsigned int height, unsigned int x_axis, unsigned int y_axis, float degrees, Color myColor)
{
	this->width = width;
	this->height = height;
	this->x_axis = x_axis;
	this->y_axis = y_axis;
	this->degrees = degrees;
	this->myColor = myColor;
}