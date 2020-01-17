#include "Furniture.h"
#include "Plane.h"

using namespace std;
using namespace sf;

Furniture::Furniture(float width, float height,
	unsigned int x_axis, unsigned int y_axis, float degrees, Color myColor, string textureFile)
	:Element(width, height, x_axis, y_axis, degrees, myColor)
{
	if (!ourTexture.loadFromFile(textureFile))
	{
		cerr << "Nie dziala plik z tekstura!" << endl;
		return;
	}
	else
	{
		ourImage.setTexture(ourTexture);
	}
	FloatRect temp = ourImage.getGlobalBounds();
	Vector2f origin = ourImage.getOrigin();
	origin.x += temp.width / 2;
	origin.y += temp.height / 2;
	ourImage.setOrigin(origin);
	w_scale = 1;
	h_scale = 1;
	angle = 0;
	setSize(width, height);
	setOffset(x_axis, y_axis);
	setRotation(degrees);
	setColor(myColor);
}

Furniture::Furniture(const Furniture & toCopy)
{
	ourImage.setTexture(toCopy.ourTexture);
	FloatRect temp = ourImage.getGlobalBounds();
	Vector2f origin = ourImage.getOrigin();
	origin.x += temp.width / 2;
	origin.y += temp.height / 2;
	ourImage.setOrigin(origin);
	w_scale = 1;
	h_scale = 1;
	angle = 0;
	setSize(w_scale/2, h_scale/2);
	setOffset(toCopy.x_axis, toCopy.y_axis);
	setRotation(toCopy.degrees);
	setColor(toCopy.myColor);

}

bool Furniture::isActivated()
{
	return guided;
}

void Furniture::manageInput(Vector2i mousePos, Keyboard::Key pressed)
{
	if (pressed == Keyboard::Key::Unknown)
	{
			if (ourImage.getGlobalBounds().contains(Vector2f(mousePos)))
				//	&& Mouse::isButtonPressed(Mouse::Left))
			{
				guided = true;
			}
		
		else
		{
		guided = false;
		}
	}
	else
	{
		if (pressed == Keyboard::Right)
		{
			angle += 4.0f;
			ourImage.setRotation(angle);
		}
		else if (pressed == Keyboard::Left)
		{
			angle -= 4.0f;
			ourImage.setRotation(angle);
		}

		if (previous != pressed)
		{
			w_scale = 1;
			h_scale = 1;
		}
		if (pressed == Keyboard::P)
		{
			w_scale *= 1.001f;
			h_scale *= 1.001f;
			ourImage.scale(w_scale, h_scale);
		}
		else if (pressed == Keyboard::O)
		{
			w_scale *= 0.999f;
			h_scale *= 0.999f;
			ourImage.scale(w_scale, h_scale);
		}
		previous = pressed;
	}
}

void Furniture::manageScreenBehaviour(Element * toManage, change mode)
{
	if (mode == set)
	{
		*toManage = *this;
	}
	else if (mode == unset)
	{
		this->guided = false;
	}
}

void Furniture::setPosition(Vector2i position)
{
	Vector2f temp{ static_cast<float>(position.x),static_cast<float>(position.y) };
	ourImage.setPosition(temp);
	//this->travPos = temp;
}

void Furniture::setSize(float width, float height)
{
	this->ourImage.setScale(width, height);
}
void Furniture::setSize(unsigned int width, unsigned int height)
{
	this->ourImage.setScale(width, height);
}
void Furniture::setOffset(unsigned int x_axis, unsigned int y_axis)
{
	Vector2f temp = Vector2f{ static_cast<float> (x_axis) ,static_cast<float> (y_axis) };
	ourImage.setPosition(temp);
}
void Furniture::setRotation(float degrees)
{
	ourImage.setRotation(degrees);
}
void Furniture::setColor(Color myColor)
{
	ourImage.setColor(myColor);
}


void Furniture:: drawMe(RenderWindow& window, RenderStates state)
{
	window.draw(this->ourImage, state);
}
