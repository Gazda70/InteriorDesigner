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

bool Furniture::shallGuide(Vector2i mousePos, bool& isGuide)
{
	if (!isGuide)
	{
		if (ourImage.getGlobalBounds().contains(Vector2f(mousePos)))
		//	&& Mouse::isButtonPressed(Mouse::Left))
		{
			isGuide = true;
			guided = true;
			return true;
		}
	}
	return false;
}

void Furniture::moveAround(Vector2i mousePos, Plane& playground)
{
	FloatRect ourBounds = playground.myplane().getLocalBounds();
	FloatRect imageBnd = ourImage.getLocalBounds();
	Vector2f travPos = Vector2f(mousePos);

	float width = ourImage.getLocalBounds().width;
	float height = ourImage.getLocalBounds().height;
	if ((guided) && (playground.isInside(this, mousePos)))
	{
		//	if	(ourBounds.contains(travPos) && ourBounds.contains(travPos + Vector2f(width, 0)))
				//&& ourBounds.contains(travPos + Vector2f(0, height))&& ourBounds.contains(travPos + Vector2f(width, height)))
		{

			ourImage.setPosition(travPos);
			/*
			Vector2f toMove = travPos - ourImage.getPosition();
			ourImage.move(toMove);
			*/
		}
	}
}

void Furniture::stopGuide()
{
	guided = false;
}

void Furniture::handleKey(Keyboard::Key inputBut)
{
	if (inputBut == Keyboard::Right)
	{
		angle += 4.0f;
		ourImage.setRotation(angle);
	}
	else if (inputBut == Keyboard::Left)
	{
		angle -= 4.0f;
		ourImage.setRotation(angle);
	}

		if (previous != inputBut)
		{
			w_scale = 1;
			h_scale = 1;
		}
		if (inputBut == Keyboard::P)
		{
			w_scale *= 1.001f;
			h_scale *= 1.001f;
			ourImage.scale(w_scale, h_scale);
		}
		else if (inputBut == Keyboard::O)
		{
			w_scale *= 0.999f;
			h_scale *= 0.999f;
			ourImage.scale(w_scale, h_scale);
		}
		previous = inputBut;

}
void Furniture::saySpawn(bool spawn)
{
	if (spawn == true)
	{
		spawned = true;
	}
	else if(spawn == false)
	{
		spawned = false;
	}
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


void Furniture::draw(RenderTarget & target, RenderStates state) const
{
	target.draw(this->ourImage, state);
}
