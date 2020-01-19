#include "Furniture.h"
#include "Plane.h"

using namespace std;
using namespace sf;

Furniture::Furniture(float width, float height,
	unsigned int x, unsigned int y, float degrees, Color mycolor, string textureF)
	:Element(width, height, x, y, degrees, myColor)
{

	if (!ourTexture.loadFromFile(textureF))
	{
		cerr << "Nie dziala plik z tekstura!" << endl;
		return;
	}
	else
	{
		ourImage.setTexture(ourTexture);
	}
	correctOrigin();
	x_scale = 1;
	y_scale = 1;
	angle = 0;
	setSize(width, height);
	Vector2i help;
	help.x = x;
	help.y = y;
	setPosition(help);
	setRotation(degrees);
	setColor(mycolor,dflt);
	myColor = mycolor;
	textureFile = textureF;
	file = textureF;
}

Furniture::Furniture(const Furniture & toCopy)
{
	ourImage.setTexture(toCopy.ourTexture);
	FloatRect temp = ourImage.getGlobalBounds();
	Vector2f origin = ourImage.getOrigin();
	origin.x += temp.width / 2;
	origin.y += temp.height / 2;
	ourImage.setOrigin(origin);
	x_scale = 1;
	y_scale = 1;
	angle = 0;
	setSize(x_scale/2, y_scale/2);
	x_axis = toCopy.x_axis;
	y_axis = toCopy.y_axis;
	setRotation(toCopy.degrees);
	this->myColor = toCopy.myColor;
}

bool Furniture::isActivated()
{
	return guided;
}

void Furniture::manageInput(Vector2i mousePos, Keyboard::Key pressed, change mode)
{
	if (pressed == Keyboard::Key::Unknown)
	{
			if (ourImage.getGlobalBounds().contains(Vector2f(mousePos)))
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
			angle += 3.0f;
			ourImage.setRotation(angle);
		}
		else if (pressed == Keyboard::Left)
		{
			angle -= 3.0f;
			ourImage.setRotation(angle);
		}

		if (previous != pressed)
		{
			x_scale = 1;
			y_scale = 1;
		}
		if (pressed == Keyboard::P)
		{
			x_scale *= 1.001f;
			y_scale *= 1.001f;
			ourImage.scale(x_scale, y_scale);
			incr_scale++;
		}
		else if (pressed == Keyboard::O)
		{
			x_scale *= 0.999f;
			y_scale *= 0.999f;
			dcr_scale++;
			ourImage.scale(x_scale, y_scale);
		}
		previous = pressed;
	}
}

Element* Furniture::manageScreenBehaviour(change mode)
{
		if (mode == set)
		{
			return this;
		}
		else if (mode == unset)
		{
			this->guided = false;
			return nullptr;
		}
}

void Furniture::setPosition(Vector2i position)
{
	Vector2f temp{ static_cast<float>(position.x),static_cast<float>(position.y) };
	this->x_axis = position.x;
	this->y_axis = position.y;
	ourImage.setPosition(temp);
}

void Furniture::correctOrigin()
{
	FloatRect temp = ourImage.getGlobalBounds();
	Vector2f origin = ourImage.getOrigin();
	origin.x += temp.width / 2;
	origin.y += temp.height / 2;
	ourImage.setOrigin(origin);
}

void Furniture::setSize(float width, float height)
{
	ourImage.setScale(width, height);
}
void Furniture::setRotation(float degrees)
{
	ourImage.setRotation(degrees);
}
void Furniture::fixScale(int incr, int dcr)
{
	for (int n = 0; n < incr; n++)
	{
		x_scale *= 1.001f;
		y_scale *= 1.001f;
		ourImage.scale(x_scale, y_scale);
	}
	for (int n = 0; n < dcr; n++)
	{
		x_scale *= 0.999f;
		y_scale *= 0.999f;
		ourImage.scale(x_scale, y_scale);
	}
}
void Furniture::setColor(Color& color, change mode)
{
	this->myColor = color;
	ourImage.setColor(color);
}
istream &Furniture:: operator>>(istream& is)
{
	string color;
	is >> textureFile;
	if(ourTexture.loadFromFile(textureFile))
		ourImage.setTexture(ourTexture);
	correctOrigin();
	is >> x_axis;
	is >> y_axis;
	is >> incr_scale;
	is >> dcr_scale;
	Vector2i help;
	help.x = x_axis;
	help.y = y_axis;
	setPosition(help);
	ourImage.setScale(0.2f, 0.2f);
	x_scale = 1;
	y_scale = 1;
	fixScale(incr_scale, dcr_scale);
	is >> angle;
	setRotation(angle);
	is >> color;
	if (color == "G")
	{
		myColor = Color::Green;
	}
	else if (color == "R")
	{
		myColor = Color::Red;
	}
	else if (color == "B")
	{
		myColor = Color::Blue;
	}
	else if (color == "Y")
	{
		myColor = Color::Yellow;
	}
	setColor(myColor, dflt);
	return is;
}
ostream & Furniture::operator<<(ostream& os)
{
	if (textureFile != "")
	{
		os << textureFile << endl;
		os << x_axis << endl;
		os << y_axis << endl;
		os << incr_scale << endl;
		os << dcr_scale << endl;
		os << angle << endl;
		if (myColor == Color::Green)
		{
			os << "G"<<endl;
		}
		else if (myColor == Color::Red)
		{
			os << "R" << endl;
		}
		else if (myColor == Color::Blue)
		{
			os << "B" << endl;
		}
		else if (myColor == Color::Yellow)
		{
			os << "Y" << endl;
		}
	}
	return os;
}
void Furniture:: drawMe(RenderWindow& window, RenderStates state)
{
	window.draw(this->ourImage, state);
}

