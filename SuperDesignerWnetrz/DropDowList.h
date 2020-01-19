#pragma once
#include "UIElement.h"
#include "Furniture.h"
#include "Button.h"

class DropDownList : public UIElement
{

public:
	DropDownList(unsigned int width, unsigned int height, unsigned int x_axis, unsigned int y_axis, Color myColor,
		unsigned int textSize, Color tColor, Text::Style tBold, Text::Style tUnderline, int ouThick, Color ouColor);
	void manageInput(Vector2i mousePos, Keyboard::Key pressed, change mode);
	bool isActivated();
	void addPart(string another,Color myColor, Furniture* toFollow);
	void drawMe(RenderWindow & window, RenderStates state);
	Element* manageScreenBehaviour(change mode);
	change getType();
	void setColor(Color& myColor, change mode);
	Element* chosen;
private:
	vector<Element*> ourlist;
	string saveFile;
	bool activated;
	change ourType;
	unsigned int	helpy;
	unsigned int   helpx;
	unsigned int textSize;
	Color tColor;
	Text::Style tBold;
	Text::Style tUnderline;
	int ouThick;
	Color ouColor;
};