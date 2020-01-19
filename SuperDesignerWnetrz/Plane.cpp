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
	setSize(width, height);
	setColor(myColor,dflt);
	setOffset(x_axis, y_axis);
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
	//implement
	return nullptr;
}

istream & Plane::operator>>(istream & is)
{
	// TODO: insert return statement here
	return is;
}

ostream & Plane::operator<<(ostream & os)
{
	// TODO: insert return statement here
	return os;
}

void Plane::setPosition(Vector2i position)
{
	//implement
}

bool Plane::isActivated()
{
	return isInside;
}
