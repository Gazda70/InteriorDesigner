#include "Project.h"
#include "UIPart.h"
#include "Element.h"
#include "Furniture.h"
#include "Plane.h"
#include "UI.h"
#include "UIElement.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <windows.h>

using namespace std;
using namespace sf;

int main(int argc, char * argv[])
{
	RenderWindow window { VideoMode(1600,900),"Project " };
	Project* super = new Project(1600, 900);
	super->addFurniture("DobreKrzeslo.png");
	super->addFurniture("DobryFotel.png");
	super->addFurniture("LepszyStol.png");
	super->addFurniture("DobreLozko.png");
	super->runProject(window);
	/*window.setVerticalSyncEnabled(true);
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
					int count = UInstance.indexList(mySwitch, window, mPosition);
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
								if (showList)
									showList = 0;
								else
									showList = 1;
								break;
						case 3:
							window.close();
							break;
						}
						testowy->shallGuide(mPosition, mouseGuide);
					}
				}
			}
			else if (event.type == sf::Event::KeyPressed)
			{
				testowy->handleKey(event.key.code);
			}
			if (mouseGuide)
			{
				if ((event.type == Event::MouseMoved))
				{
					testowy->moveAround(Mouse::getPosition(window),nowy);
				}
				else if ((event.type == Event::MouseButtonReleased))
				{
					testowy->stopGuide();
						mouseGuide = false;
				}
			}

				window.clear(Color::Blue);
				UInstance.displayCurrent(mySwitch, window,nowy,showList,testowy);
				window.display();
		}
	}*/

		system("pause");
		//cin.get();
	return 0;
}