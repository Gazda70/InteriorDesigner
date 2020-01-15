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
void DropDownList::drawList(vector<Button*>& myList, RenderWindow & window)
{

	for (int c = 0; c < myList.size(); c++)
	{
		(*myList[c]).draw(window, RenderStates::Default);
	}
	return;
}

void DropDownList::setGlobalTarget(Furniture * toFollow)
{
	for (auto iter : ourlist)
	{
		iter->setAct(toFollow);
	}

}

Furniture* DropDownList::goThrough(Vector2i mouse, listType change)
{
	for (int i = 0; i < ourlist.size(); i++)
	{
		if (ourlist[i]->getInteractionWindow().getGlobalBounds()
			.contains(static_cast<float>(mouse.x), static_cast<float>(mouse.y)))
		{
			if (change == furnitureT)
			{
				return ourlist[i]->getAct();
			}
			else if (change == colorT)
			{
				ourlist[i]->getAct()->setColor(ourlist[i]->getMyColor());
				return nullptr;
			}
		}
	}
	return nullptr;
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


