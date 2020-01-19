#include"Plane.h"
#include"Furniture.h"

void Plane::setSize(unsigned int width, unsigned int height)
{
	Vector2f temp;
	temp.x = width;
	temp.y = height;
	this->myPlane.setSize(temp);
}

void Plane::setColor(Color& myColor, change mode)
{
	this->myPlane.setFillColor(myColor);
}
void Plane::setOutline(Color oColor, int oThick)
{
	myPlane.setOutlineThickness(oThick);
	myPlane.setOutlineColor(oColor);
}
void Plane::drawMe(RenderWindow& window, RenderStates state)
{
	window.draw(this->myPlane);
}

RectangleShape Plane::myplane()
{
	return this->myPlane;
}
Plane::Plane(unsigned int width, unsigned int height, unsigned int x_axis, unsigned int  y_axis,
	Color myColor, Color oColor, int oThick)
{
	Vector2i position = {static_cast<int>(x_axis),static_cast<int>(y_axis)};
	setSize(width, height);
	setColor(myColor,dflt);
	setPosition(position);
	setOutline(oColor, oThick);
}

void Plane::manageInput(Vector2i mousePos, Keyboard::Key pressed, change mode)
{

	FloatRect ourBounds = this->myPlane.getGlobalBounds();
	if (ourBounds.contains(Vector2f(mousePos)))
	{
		isInside =  true;
	}
	else
	{
		isInside = false;
	}
}

Element *Plane::manageScreenBehaviour(change mode)
{
	return nullptr;
}

istream & Plane::operator>>(istream & is)
{
	return is;
}

ostream & Plane::operator<<(ostream & os)
{
	return os;
}

void Plane::setPosition(Vector2i position)
{
	this->myPlane.setPosition(static_cast<Vector2f>(position));
}

bool Plane::isActivated()
{
	return isInside;
}
