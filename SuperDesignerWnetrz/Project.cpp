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
	 UIPart mySwitch = UIPart::MainMenu;
}

void Project::addFurniture(string textureFile)
{
	Furniture* temp = new Furniture(0.2f, 0.2f, projectPlane->myplane().getSize().x / 2,
		projectPlane->myplane().getSize().y / 1.5f, 0, Color::Red, textureFile);
	int help = textureFile.size();
	string name = textureFile.erase(help-4);
	this->projectInterface->furnitureList->addPart(name, temp);
	zbiorMebli.push_back(temp);
}

void Project::runProject(RenderWindow& window)
{
	window.setVerticalSyncEnabled(true);
	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
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
					if (mySwitch == MainMenu)	//jesteœmy w menu g³ównym
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
							if (projectInterface->showList)
								projectInterface->showList = 0;
							else
								projectInterface->showList = 1;
							break;
						case 3:
							window.close();
							break;
						}
						zbiorMebli[0]->shallGuide(mPosition, mouseGuide);
					}
				}
			}
			else if (event.type == sf::Event::KeyPressed)
			{
				zbiorMebli[0]->handleKey(event.key.code);
			}
			if (mouseGuide)
			{
				if ((event.type == Event::MouseMoved))
				{
					zbiorMebli[0]->moveAround(Mouse::getPosition(window), *projectPlane);
				}
				else if ((event.type == Event::MouseButtonReleased))
				{
					zbiorMebli[0]->stopGuide();
					mouseGuide = false;
				}
			}

			window.clear(Color::Blue);
			projectInterface->displayCurrent(mySwitch, window, *projectPlane, projectInterface->showList, zbiorMebli[0]);
			window.display();
		}
	}
}
