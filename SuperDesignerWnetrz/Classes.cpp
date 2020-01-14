#include "Classes.h"
using namespace sf;
using namespace std;


Element::Element(unsigned int width, unsigned int height, unsigned int x_axis, unsigned int y_axis, float degrees, Color myColor)
{
	this->width = width;
	this->height = height;
	this->x_axis = x_axis;
	this->y_axis = y_axis;
	this->degrees = degrees;
	this->myColor = myColor;
}

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
bool Plane:: isInside(Furniture* traveler, Vector2i mousePos)
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
	setSize(width,height);
	setColor(myColor);
	setOffset( x_axis,y_axis);
	setOutline(oColor,oThick);
}
void UIElement::setOffset(unsigned int x_axis, unsigned int  y_axis)
{
	interactionWindow.setPosition(x_axis, y_axis);
}

void UIElement::setColor(Color myColor)
{
	interactionWindow.setFillColor(myColor);
}

RectangleShape UIElement::getInteractionWindow()
{
	RectangleShape shape = this->interactionWindow;
	return shape;
}
Text UIElement::getText()
{
	Text text = this->myText;
	return text;
}
void UIElement::setSize(unsigned int width, unsigned int height)
{
	Vector2f create;
	create.x = width;
	create.y = height;
	interactionWindow.setSize(create);
}
void UIElement::setRotation(float degrees)
{
	interactionWindow.setRotation({degrees});
}
void UIElement::setText(const string myMes,unsigned int mySize,Color color, Text ::Style ifBold, Text::Style ifUnderlined)
{
	myText.setFont(myFont); 
	// set the string to display
	myText.setString(myMes);
	// set the character size
	myText.setCharacterSize(mySize); // in pixels, not points!
	// set the color
	myText.setFillColor(color);
	// set the text style
	myText.setStyle(ifBold|ifUnderlined);
	//get the text size
	FloatRect textBounds = myText.getLocalBounds();
	//set the text origin to center
	myText.setOrigin(textBounds.width/2, textBounds.height);
	Vector2f shapePos = this->interactionWindow.getPosition();
	FloatRect shapeBounds = this->interactionWindow.getLocalBounds();

	// set the text position
	myText.setPosition(shapePos.x + shapeBounds.width/2, shapePos.y + shapeBounds.height / 2);
}

void UIElement::setShape(unsigned int width, unsigned int height, unsigned int x_axis, unsigned int y_axis, float degrees, Color myColor)
{
	Vector2f create;
	create.x = width;
	create.y = height;
	interactionWindow.setSize(create);
	interactionWindow.setPosition(x_axis, y_axis);
	interactionWindow.setFillColor(myColor);
	interactionWindow.setRotation({ degrees });
}

bool UIElement::whenMouseOverMe()
{
	if (this->myText.getString() == "Ksztalty")
	{
		return true;
	}
	else
	{
		return false;
	}
}

void UIElement::draw(RenderTarget & target, RenderStates state) const
{
	target.draw(this->interactionWindow, state);
	target.draw(this->myText, state);
}

void UI::createMainMenu()
{
	mainMenu.push_back( new UIElement((temp_x / 2), (temp_y / 9) * 2, temp_x / 4, (temp_y / 18),
		Color::Green,60, Color::Black, Text::Regular, Text::Regular, -1, Color::Black, "Super Designer Wnetrz"));// g³ówny zielony prostok¹t

	mainMenu.push_back( new UIElement((temp_x / 2), (temp_y / 18), temp_x / 4, (temp_y / 3),
		Color::Red, 40, Color::Black, Text::Regular, Text::Regular, - 1, Color::Black, "Nowy projekt" ));// nowy projekt

	mainMenu.push_back( new UIElement((temp_x / 2), (temp_y / 18), temp_x / 4, (int)(temp_y / 2.5),
		Color::Red, 40, Color::Black, Text::Regular, Text::Regular, - 1, Color::Black,"Otworz istniejacy" ));// otwórz istniej¹cy

	mainMenu.push_back( new UIElement((temp_x / 2), (temp_y / 18), temp_x / 4, (int)(temp_y / 2.13),
		Color::Red, 40, Color::Black, Text::Regular, Text::Regular, - 1, Color::Black, "Ustawienia"));// ustawienia

	mainMenu.push_back( new UIElement((temp_x / 2), (temp_y / 18), temp_x / 4, (int)(temp_y / 1.85),
		Color::Red, 40, Color::Black, Text::Regular, Text::Regular, - 1, Color::Black,"Wyjdz" ));// wyjdz

}
void UI::displayCurrent(UIPart current, RenderWindow &window, Plane &myCanvas, bool showList,Furniture* testowy)
{
	switch (current)
	{
	case MainMenu:
		displayUI(this->mainMenu, window);
		break;
	case WorkPlace:
		displayUI(this->workPlace, window);
		myCanvas.draw(window, RenderStates::Default);
		if (showList)
		{
			this->furnitureList->drawList(this->furnitureList->ourlist, window);
		}
		//if(showList)
		testowy->draw(window, RenderStates::Default);
		break;
	}
}
int UI::indexList(UIPart current, RenderWindow& window, Vector2i mousePos)
{
	vector<UIElement*>* temp = nullptr;
	int size = 0;
	int count = 0;
	switch (current)
	{
	case MainMenu:
		temp = &mainMenu;
		size = temp->size();
		break;
	case WorkPlace:
		temp = &workPlace;
		size = temp->size();
		break;
	}
	if (temp)
	{
		while (count < size)
		{
			if ((*temp)[count]->getInteractionWindow().getGlobalBounds()
				.contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
			{
				return count;
			}
			else
			{
				count++;
			}
		}
	}
	else
	{
		return 10;
	}
	return count;
}
bool UI::isMouseOverHim(UIPart current, RenderWindow & window, Vector2i mousePos)
{
	int count = 0;
	int size = 0;
	vector<UIElement*>* temp = nullptr;
		temp = &workPlace;
		size = temp->size();

	if (temp)
	{
		while (count < size)
		{
			if ((*temp)[count]->getInteractionWindow().getGlobalBounds()
				.contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
			{
				if ((*temp)[count]->whenMouseOverMe())
					return true;
				count++;
			}
		}
	}
		return false;
}
void UI::displayUI(vector<UIElement*>& myList, RenderWindow &window)
{
	for (int i = 0;i < myList.size(); i++)
	{
		window.draw(*myList[i]);
	}
}

vector<UIElement*>& UI::getList(UIPart current)
{
	switch (current)
	{
	case MainMenu:
		return this->mainMenu;
		break;
	case WorkPlace:
		return this->workPlace;
		break;
	}
}

void UI::createWorkplace()
{
	UIElement *ksztalt = new UIElement(((temp_x / 16) * 3), (temp_y / 9), (temp_x / 32), (temp_y / 18),
		Color::Red,60, Color::Black, Text::Regular, Text::Regular,-1, Color::Black, "Ksztalty");

	workPlace.push_back(ksztalt);

	workPlace.push_back(new UIElement(((temp_x / 16) * 3), (temp_y / 9), ((temp_x / 32) * 9), (temp_y / 18),
		Color::Red, 60, Color::Black, Text::Regular, Text::Regular , -1, Color::Black, "Pomoc"));

	workPlace.push_back(new UIElement(((temp_x / 16) * 3), (temp_y / 9), ((temp_x / 32) * 17), (temp_y / 18),
		Color::Red, 60, Color::Black, Text::Regular, Text::Regular, -1, Color::Black,"Zapisz" ));

	workPlace.push_back(new UIElement(((temp_x / 16) * 3), (temp_y / 9), ((temp_x / 32) * 25), (temp_y / 18),
		Color::Red, 60, Color::Black, Text::Regular, Text::Regular, - 1, Color::Black,"Wyjdz" ));

	Vector2f startList = ksztalt->getInteractionWindow().getPosition();
	FloatRect hookSize = ksztalt->getInteractionWindow().getLocalBounds();
	cout << hookSize.width << endl;
	startList.y += hookSize.height;
	furnitureList = new DropDownList(static_cast<unsigned int>(hookSize.width),
		static_cast<unsigned int>(hookSize.height / 2), static_cast<unsigned int>(startList.x), static_cast<unsigned int>(startList.y),
		Color::Green, 15, Color::Black, Text::Style::Italic, Text::Style::Regular, -5, Color::Black );
	furnitureList->addPart("Stol");
	furnitureList->addPart("Fotel");
	furnitureList->addPart("Krzeslo");
	furnitureList->addPart("Lozko");
}
void DropDownList::addPart(string another)
{
	unsigned int temp = helpy;
	helpy += height;
	helpx += x_axis;
	UIElement* nextone = new UIElement(width, height, helpx, temp, myColor,
		textSize, tColor, tBold, tUnderline, ouThick, ouColor, another);
	ourlist.push_back(nextone);
}
void DropDownList::drawList(vector<UIElement*>& myList, RenderWindow & window)
{
	
	for (int c = 0;c< myList.size();c++)
	{
		(*myList[c]).draw(window, RenderStates::Default);
	}
	return;
}
UIElement::UIElement(unsigned int width, unsigned int height, unsigned int x_axis, unsigned int y_axis, Color myColor,
	unsigned int textSize, Color tColor, Text::Style tBold, Text::Style tUnderline, int ouThick, Color ouColor, string message)
{
	if (!this->myFont.loadFromFile(fontFile))
	{
		cout << "Niepoprawny plik czcionki!" << endl;
	}
	setShape(width, height, x_axis, y_axis, degrees, myColor);
	setText(message, textSize, tColor, tBold, tUnderline);
}
DropDownList::DropDownList(unsigned int width, unsigned int height, unsigned int x_axis, unsigned int y_axis, Color myColor,
	unsigned int textSize, Color tColor, Text::Style tBold, Text::Style tUnderline, int ouThick, Color ouColor)
	:UIElement(width, height, x_axis, y_axis, myColor, textSize, tColor, tBold, tUnderline, ouThick, ouColor,"")
{
	this->width = width;
	this->height = height;
	this->myColor = myColor;
	this->textSize = textSize;
	this->tColor = tColor;
	this->tBold = tBold;
	this->tUnderline = tUnderline;
	this->ouThick = ouThick;
	this->ouColor = ouColor;
	helpy = y_axis;
	helpx = x_axis;
}


Furniture::Furniture(float width, float height,
	unsigned int x_axis, unsigned int y_axis, float degrees, Color myColor, string textureFile)
:Element(width,height,x_axis,y_axis,degrees,myColor)
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
	setSize(width, height);
	setOffset(x_axis, y_axis);
	setRotation(degrees);
	setColor(myColor);
}

void Furniture::shallGuide(Vector2i mousePos, bool& isGuide)
{
	if (!isGuide)
	{
		if (ourImage.getLocalBounds().contains(Vector2f(mousePos))
			&& Mouse::isButtonPressed(Mouse::Left))
		{
			isGuide = true;
			guided = true;
		}
	}
}

void Furniture::moveAround(Vector2i mousePos, Plane& playground)
{
	FloatRect ourBounds = playground.myplane().getLocalBounds();
	FloatRect imageBnd = ourImage.getLocalBounds();
	Vector2f travPos = Vector2f(mousePos);

	float width = ourImage.getLocalBounds().width;
	float height = ourImage.getLocalBounds().height;
	if ((guided)&&(playground.isInside(this,mousePos)))
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

void Furniture::setSize(Keyboard::Key inputBut)
{
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
void Furniture::setSize(float width, float height)
{
	this->ourImage.setScale(width,height);
}
void Furniture::setSize(unsigned int width, unsigned int height)
{
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
	target.draw(this->ourImage,state);
}
