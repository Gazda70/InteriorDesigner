#include "Project.h"


Project::Project(unsigned int screen_res_width, unsigned int screen_res_height, string fileName)
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
	this->fileName = fileName;
	mySwitch = change::MainMenu;
}

void Project::addFurniture(string textureFile, change mode)
{
	Furniture* temp = new Furniture(0.2f, 0.2f, projectPlane->myplane().getSize().x / 2,
		projectPlane->myplane().getSize().y / 1.5f, 0, Color::Red, textureFile);
	if (mode == dflt)
	{
		int help = textureFile.size();
		string name = textureFile.erase(help - 4);
		this->projectInterface->furnitureList->addPart(name, Color::Green, temp);
		zbiorMebli.push_back(temp);
	}
	else if(mode == set)
	{
		naScenie.push_back(temp);
	}
}

void Project::runProject(RenderWindow& window)
{
	Element* toSpawn = nullptr;
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
				fstream file;
				if (!mouseGuide)
				{
					Vector2i mPosition = Mouse::getPosition(window);
					int count = projectInterface->indexList(mySwitch, window, mPosition);
					if (mySwitch == MainMenu)	//jesteœmy w menu g³ównym
					{
						switch (count)
						{
						case 3:
							window.close();
							break;
						case 1:
							mySwitch = WorkPlace;
							file.open(fileName,ios::trunc);
							file.close();
							break;
							case 2:
								file.open(fileName, ios::in);
								if (file.is_open())
								{
									while (!file.eof())
									{
										Element* help = new Furniture();
										help->operator>>(file);
										naScenie.push_back(help);
									}
									file.close();
								}
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
						case 2:
							file.open(fileName, ios::out | ios::trunc);
							if (file.is_open())
							{
								for (int k = 0; k < naScenie.size(); k++)
								{
									 naScenie[k]->operator<<(file);
								}
								file.close();
							}
							break;
						case 3:
							mySwitch = MainMenu;
							naScenie.clear();
								break;
						}
						if (projectInterface->showFurnitureList)
						{
						 projectInterface->furnitureList->manageInput(mPosition,Keyboard::Key::Unknown,set);
						 toSpawn = projectInterface->furnitureList->chosen;
						 projectInterface->furnitureList->chosen = nullptr;
							if (toSpawn)
							{
								addFurniture(toSpawn->file, set);
								toSpawn = nullptr;
							}
						}
						if (projectInterface->showColorList)
						{
							projectInterface->colorList->manageInput(mPosition, Keyboard::Key::Unknown, color);
						}
						if (!naScenie.empty())
						{
							int i = 0;
							while (i < naScenie.size() && !mouseGuide)
							{
								naScenie[i]->manageInput(mPosition,Keyboard::Key::Unknown,set);
								if (naScenie[i]->isActivated())
								{
									toGuide = naScenie[i];
									 projectInterface->colorList->chosen = toGuide;
									mouseGuide = true;
								}
								i++;
							}
						}
					}
				}
			}
			else if (event.type == Event::MouseButtonReleased)
			{
				if (toGuide)
				{
					toGuide->manageScreenBehaviour(unset);
					mouseGuide = false;
				}
			}
			else if (event.type ==Event::KeyPressed)
			{
				if (toGuide)
				{
					if (event.key.code == Keyboard::E)
					{
						removeFromScene(toGuide);
						mouseGuide = false;
						projectInterface->furnitureList->chosen = nullptr;
					}
					else
					{
						toGuide->manageInput({ 0,0 },event.key.code,set);
					}
				}
			}
			if (mouseGuide)
			{
				if ((event.type == Event::MouseMoved))
				{
					if (toGuide)
					{
						projectPlane->traveler = toGuide->manageScreenBehaviour(set);// polimorfizm
						projectPlane->manageInput(Mouse::getPosition(window), Keyboard::Key::Unknown, dflt);
						if (projectPlane->isActivated())
						{
							toGuide->setPosition(Mouse::getPosition(window));
						}
					}

				}
				else if ((event.type == Event::MouseButtonReleased))
				{
					toGuide->manageScreenBehaviour(unset);
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
			naScenie[k]->drawMe(window, RenderStates::Default);//polimorfizm
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
			return;
		}
		else
		{
			i++;
		}
	}
}
