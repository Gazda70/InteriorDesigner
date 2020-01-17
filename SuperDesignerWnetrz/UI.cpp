#include"UI.h"
UI::UI(unsigned int res_x, unsigned int res_y)
{
	this->res_x = res_x;
	this->res_y = res_y;
	this->showFurnitureList = 0;
	this->showColorList = 0;
}
void UI::createMainMenu()
{
	cout << res_x << endl;
	cout << res_y << endl;
	mainMenu.push_back(new UIElement((temp_x / 2), (temp_y / 9) * 2, temp_x / 4, (temp_y / 18),
		Color::Green, 60, Color::Black, Text::Regular, Text::Regular, -1, Color::Black, "Super Designer Wnetrz"));// glówny zielony prostokat

	mainMenu.push_back(new UIElement((temp_x / 2), (temp_y / 18), temp_x / 4, (temp_y / 3),
		Color::Red, 40, Color::Black, Text::Regular, Text::Regular, -1, Color::Black, "Nowy projekt"));// nowy projekt

	mainMenu.push_back(new UIElement((temp_x / 2), (temp_y / 18), temp_x / 4, (int)(temp_y / 2.5),
		Color::Red, 40, Color::Black, Text::Regular, Text::Regular, -1, Color::Black, "Otworz istniejacy"));// otwórz istniejacy

	mainMenu.push_back(new UIElement((temp_x / 2), (temp_y / 18), temp_x / 4, (int)(temp_y / 2.13),
		Color::Red, 40, Color::Black, Text::Regular, Text::Regular, -1, Color::Black, "Ustawienia"));// ustawienia

	mainMenu.push_back(new UIElement((temp_x / 2), (temp_y / 18), temp_x / 4, (int)(temp_y / 1.85),
		Color::Red, 40, Color::Black, Text::Regular, Text::Regular, -1, Color::Black, "Wyjdz"));// wyjdz
}
void UI::displayCurrent(change current, RenderWindow& window, Plane &myCanvas, bool showList)
{
	switch (current)
	{
	case MainMenu:
		displayUI(this->mainMenu, window);
		break;
	case WorkPlace:
		displayUI(this->workPlace, window);
		myCanvas.drawMe(window, RenderStates::Default);
		if (showFurnitureList)
		{
			this->furnitureList->drawMe(window, RenderStates::Default);
		}
		if (showColorList)
		{
			this->colorList->drawMe(window, RenderStates::Default);
		}
		break;
	}
}
int UI::indexList(change current, RenderWindow& window, Vector2i mousePos)
{
	vector<Element*>* temp = nullptr;
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
			(*temp)[count]->manageInput(mousePos, Keyboard::Key::Unknown);
			if ((*temp)[count]->isActivated())
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
void UI::displayUI(vector<Element*>& myList, RenderWindow& window)
{
	for (int i = 0; i < myList.size(); i++)
	{
		(*myList[i]).drawMe(window, RenderStates::Default);
	}
}

vector<Element*>& UI::getList(change current)
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
	UIElement *ksztalt = new UIElement(((res_x / 16) * 3), (res_y / 9), (res_x / 32), (res_y / 18),
		Color::Red, 60, Color::Black, Text::Regular, Text::Regular, -1, Color::Black, "Ksztalty");

	Vector2f startList = ksztalt->getInteractionWindow().getPosition();
	FloatRect hookSize = ksztalt->getInteractionWindow().getLocalBounds();
	cout << hookSize.width << endl;
	startList.y += hookSize.height;
	furnitureList = new DropDownList(static_cast<unsigned int>(hookSize.width),
		static_cast<unsigned int>(hookSize.height / 2), static_cast<unsigned int>(startList.x), static_cast<unsigned int>(startList.y),
		Color::Green, 15, Color::Black, Text::Style::Italic, Text::Style::Regular, -5, Color::Black);

	workPlace.push_back(ksztalt);
	ksztalt = new UIElement(((res_x / 16) * 3), (res_y / 9), ((res_x / 32) * 17), (res_y / 18),
		Color::Red, 60, Color::Black, Text::Regular, Text::Regular, -1, Color::Black, "Kolor");

	workPlace.push_back(ksztalt);
	workPlace.push_back(new UIElement(((res_x / 16) * 3), (res_y / 9), ((res_x / 32) * 9), (res_y / 18),
		Color::Red, 60, Color::Black, Text::Regular, Text::Regular, -1, Color::Black, "Pomoc"));

	startList = ksztalt->getInteractionWindow().getPosition();
	 hookSize = ksztalt->getInteractionWindow().getLocalBounds();
	cout << hookSize.width << endl;
	startList.y += hookSize.height;
	colorList = new DropDownList(static_cast<unsigned int>(hookSize.width),
		static_cast<unsigned int>(hookSize.height / 2), static_cast<unsigned int>(startList.x), static_cast<unsigned int>(startList.y),
		Color::Green, 15, Color::Black, Text::Style::Italic, Text::Style::Regular, -5, Color::Black);

	workPlace.push_back(new UIElement(((res_x / 16) * 3), (res_y / 9), ((res_x / 32) * 25), (res_y / 18),
		Color::Red, 60, Color::Black, Text::Regular, Text::Regular, -1, Color::Black, "Wyjdz"));
	colorList->addPart("Zielony",Color::Green, nullptr);
	colorList->addPart("Czerwony", Color::Red, nullptr);
	colorList->addPart("Niebieski", Color::Blue, nullptr);
	colorList->addPart("Zolty", Color::Yellow, nullptr);
}