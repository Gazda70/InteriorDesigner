#include"UI.h"

void UI::createMainMenu()
{
	mainMenu.push_back(new UIElement((temp_x / 2), (temp_y / 9) * 2, temp_x / 4, (temp_y / 18),
		Color::Green, 60, Color::Black, Text::Regular, Text::Regular, -1, Color::Black, "Super Designer Wnetrz"));// g³ówny zielony prostok¹t

	mainMenu.push_back(new UIElement((temp_x / 2), (temp_y / 18), temp_x / 4, (temp_y / 3),
		Color::Red, 40, Color::Black, Text::Regular, Text::Regular, -1, Color::Black, "Nowy projekt"));// nowy projekt

	mainMenu.push_back(new UIElement((temp_x / 2), (temp_y / 18), temp_x / 4, (int)(temp_y / 2.5),
		Color::Red, 40, Color::Black, Text::Regular, Text::Regular, -1, Color::Black, "Otworz istniejacy"));// otwórz istniej¹cy

	mainMenu.push_back(new UIElement((temp_x / 2), (temp_y / 18), temp_x / 4, (int)(temp_y / 2.13),
		Color::Red, 40, Color::Black, Text::Regular, Text::Regular, -1, Color::Black, "Ustawienia"));// ustawienia

	mainMenu.push_back(new UIElement((temp_x / 2), (temp_y / 18), temp_x / 4, (int)(temp_y / 1.85),
		Color::Red, 40, Color::Black, Text::Regular, Text::Regular, -1, Color::Black, "Wyjdz"));// wyjdz

}
void UI::displayCurrent(UIPart current, RenderWindow &window, Plane &myCanvas, bool showList, Furniture* testowy)
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
	for (int i = 0; i < myList.size(); i++)
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
		Color::Red, 60, Color::Black, Text::Regular, Text::Regular, -1, Color::Black, "Ksztalty");

	workPlace.push_back(ksztalt);

	workPlace.push_back(new UIElement(((temp_x / 16) * 3), (temp_y / 9), ((temp_x / 32) * 9), (temp_y / 18),
		Color::Red, 60, Color::Black, Text::Regular, Text::Regular, -1, Color::Black, "Pomoc"));

	workPlace.push_back(new UIElement(((temp_x / 16) * 3), (temp_y / 9), ((temp_x / 32) * 17), (temp_y / 18),
		Color::Red, 60, Color::Black, Text::Regular, Text::Regular, -1, Color::Black, "Zapisz"));

	workPlace.push_back(new UIElement(((temp_x / 16) * 3), (temp_y / 9), ((temp_x / 32) * 25), (temp_y / 18),
		Color::Red, 60, Color::Black, Text::Regular, Text::Regular, -1, Color::Black, "Wyjdz"));

	Vector2f startList = ksztalt->getInteractionWindow().getPosition();
	FloatRect hookSize = ksztalt->getInteractionWindow().getLocalBounds();
	cout << hookSize.width << endl;
	startList.y += hookSize.height;
	furnitureList = new DropDownList(static_cast<unsigned int>(hookSize.width),
		static_cast<unsigned int>(hookSize.height / 2), static_cast<unsigned int>(startList.x), static_cast<unsigned int>(startList.y),
		Color::Green, 15, Color::Black, Text::Style::Italic, Text::Style::Regular, -5, Color::Black);
	furnitureList->addPart("Stol");
	furnitureList->addPart("Fotel");
	furnitureList->addPart("Krzeslo");
	furnitureList->addPart("Lozko");
}