#include "Project.h"


Project::Project(unsigned int screen_res_width, unsigned int screen_res_height)
{
	 projectInterface = new UI(screen_res_width, screen_res_height);
	 projectInterface->createMainMenu();
	 projectInterface->createWorkplace();
		projectPlane = new  Plane(screen_res_width - (screen_res_width / 16),
		screen_res_height - ((screen_res_height / 18) * 5), (screen_res_width / 32),
		((screen_res_height / 18) * 4), Color::Magenta, Color::Black, -5);
	this->screen_res_width = screen_res_width;
	this->screen_res_height = screen_res_height;
	 mouseGuide = false;
	 change mySwitch = change::MainMenu;
}

void Project::addFurniture(string textureFile)
{
	Furniture* temp = new Furniture(0.2f, 0.2f, projectPlane->myplane().getSize().x / 2,
		projectPlane->myplane().getSize().y / 1.5f, 0, Color::Red, textureFile);
	int help = textureFile.size();
	string name = textureFile.erase(help-4);
	this->projectInterface->furnitureList->addPart(name,Color::Green, temp);
	zbiorMebli.push_back(temp);
}

void Project::runProject(RenderWindow& window)
{
	Element* toSpawn;
	Element* toGuide = nullptr;
	window.setVerticalSyncEnabled(true);
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}
			else if ((event.type == Event::MouseButtonPressed))
			{
				if (!mouseGuide)
				{
					Vector2i mPosition = Mouse::getPosition(window);
					int count = projectInterface->indexList(mySwitch, window, mPosition);
					if (mySwitch == MainMenu)	//jeste�my w menu g��wnym
					{
						switch (count)
						{
						case 4:
							window.close();
							break;
						case 1:
							mySwitch = WorkPlace;
							break;
						}
					}
					else if (mySwitch == WorkPlace)
					{
						switch (count)
						{
						case 0:
							if (projectInterface->showFurnitureList)
								projectInterface->showFurnitureList = 0;
							else
								projectInterface->showFurnitureList = 1;
							break;
						case 1:
							if (projectInterface->showColorList)
								projectInterface->showColorList = 0;
							else
								projectInterface->showColorList = 1;
							break;
						case 3:
							window.close();
							break;
						}
						if (projectInterface->showFurnitureList)
						{
						 projectInterface->furnitureList->manageInput(mPosition,Keyboard::Key::Unknown);
						 toSpawn = projectInterface->furnitureList->chosen;
						if (toSpawn)
						{
							Element* help = toSpawn;
							naScenie.push_back(help);
						}
						}
						if (!naScenie.empty())
						{
							int i = 0;
							while (i < naScenie.size() && !mouseGuide)
							{
								naScenie[i]->manageInput(mPosition,Keyboard::Key::Unknown);
								if (naScenie[i]->isActivated())
								{
									toGuide = naScenie[i];
									projectInterface->colorList->manageScreenBehaviour(toGuide,set);
								}
								i++;
							}
						}
						if (projectInterface->showColorList)
						{
							projectInterface->furnitureList->manageInput(mPosition, Keyboard::Key::Unknown);
						}
					}
				}
			}
			else if (event.type == Event::MouseButtonReleased)
			{
				toGuide->manageScreenBehaviour(nullptr, unset);
				mouseGuide = false;
			}
			else if (event.type ==Event::KeyPressed)
			{
				if (toGuide)
				{
					if (event.key.code == Keyboard::E)
					{
						removeFromScene(toGuide);
						mouseGuide = false;
					}
					else
					{
						toGuide->manageInput({ 0,0 },event.key.code);
					}
				}
			}
			if (mouseGuide)
			{
				if ((event.type == Event::MouseMoved))
				{
					if (toGuide)
					{
						toGuide->manageScreenBehaviour(projectPlane->traveler, set);
						projectPlane->manageInput(Mouse::getPosition(window), Keyboard::Key::Unknown);
						if (projectPlane->isActivated())
						{
							toGuide->setPosition(Mouse::getPosition(window));
						}
					}

				}
				else if ((event.type == Event::MouseButtonReleased))
				{
					toGuide->manageScreenBehaviour(nullptr,unset);
					mouseGuide = false;
				}
			}

			window.clear(Color::Blue);
			projectInterface->displayCurrent(mySwitch, window, *projectPlane, projectInterface->showFurnitureList);
			drawOnScene(window);
			window.display();
		}
	}
}

void Project::drawOnScene(RenderWindow & window)
{
	if (!naScenie.empty())
	{
		for (int k = 0; k < naScenie.size(); k++)
			naScenie[k]->drawMe(window, RenderStates::Default);
	}
}

void Project::removeFromScene(Element * toRemove)
{
	int i = 0;
	while (i < naScenie.size())
	{
		if (naScenie[i] == toRemove)
		{
			naScenie.erase(naScenie.begin()+i);
		}
		else
		{
			i++;
		}
	}
}
