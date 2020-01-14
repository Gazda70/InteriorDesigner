#include "DropDowList.h"

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

	for (int c = 0; c < myList.size(); c++)
	{
		(*myList[c]).draw(window, RenderStates::Default);
	}
	return;
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
