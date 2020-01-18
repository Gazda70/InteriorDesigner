#include "DropDowList.h"

void DropDownList::addPart(string another, Color myColor, Furniture* toFollow)
{
	unsigned int temp = helpy;
	helpy += height;
	helpx += x_axis;
	Button* nextone = new Button(width, height, helpx, temp, myColor,
		textSize,tColor, tBold, tUnderline, ouThick, ouColor, another, toFollow);
	ourlist.push_back(nextone);
}
void DropDownList::drawMe( RenderWindow & window, RenderStates state)
{

	for (int c = 0; c < ourlist.size(); c++)
	{
		(*ourlist[c]).drawMe(window,state);
	}
	return;
}

Element* DropDownList::manageScreenBehaviour(change mode)
{
	for (auto iter : ourlist)
	{
		iter->manageScreenBehaviour(mode);
	}
	return nullptr;
}
change DropDownList::getType()
{
	return this->ourType;
}
void DropDownList::setColor(Color& myColor, change mode)
{
	this->myColor = myColor;
}
DropDownList::DropDownList(unsigned int width, unsigned int height, unsigned int x_axis, unsigned int y_axis, Color myColor,
	unsigned int textSize, Color tColor, Text::Style tBold, Text::Style tUnderline, int ouThick, Color ouColor)
	:UIElement(width, height, x_axis, y_axis, myColor, textSize, tColor, tBold, tUnderline, ouThick, ouColor, "")
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

void DropDownList::manageInput(Vector2i mousePos, Keyboard::Key pressed, change mode)
{
	for (int i = 0; i < ourlist.size(); i++)
	{
		ourlist[i]->manageInput(mousePos,pressed,mode);
		if (ourlist[i]->isActivated())
		{
			if (mode == set)
			{
				this->chosen = ourlist[i]->manageScreenBehaviour(set);
			}
			else if (mode == color)
			{
				Color hColor;
				Color& tmpC = hColor;
				ourlist[i]->setColor(tmpC,set);
				if(chosen)
				this->chosen->setColor(hColor,dflt);
			}
			return;
		}
	}
}

bool DropDownList::isActivated()
{
	return activated;
}


