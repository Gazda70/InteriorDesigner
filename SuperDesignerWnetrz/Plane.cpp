#include"Plane.h"
#include"Furniture.h"

void Plane::setSize(unsigned int width, unsigned int height)
{
	Vector2f temp;
	temp.x = width;
	temp.y = height;
	this->myPlane.setSize(temp);
}

void Plane::setOffset(unsigned int x_axis, unsigned int  y_axis)
{
	Vector2f temp;
	temp.x = x_axis;
	temp.y = y_axis;
	this->myPlane.setPosition(temp);
}
void Plane::setRotation(float degrees)
{
	this->myPlane.setRotation(degrees);
}

void Plane::setColor(Color myColor)
{
	this->myPlane.setFillColor(myColor);
}
void Plane::setOutline(Color oColor, int oThick)
{
	myPlane.setOutlineThickness(oThick);
	myPlane.setOutlineColor(oColor);
}
void Plane::draw(RenderTarget & target, RenderStates state) const
{
	target.draw(this->myPlane);
}
bool Plane::isInside(Furniture* traveler, Vector2i mousePos)
{
	FloatRect ourBounds = this->myPlane.getGlobalBounds();
	if (ourBounds.contains(Vector2f(mousePos)))
	{
		return true;
	}
	else
	{
		return false;
	}
}
RectangleShape Plane::myplane()
{
	return this->myPlane;
}
Plane::Plane(unsigned int width, unsigned int height, unsigned int x_axis, unsigned int  y_axis,
	Color myColor, Color oColor, int oThick)
{
	//	projectNumber++;
	setSize(width, height);
	setColor(myColor);
	setOffset(x_axis, y_axis);
	setOutline(oColor, oThick);
}