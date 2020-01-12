#include <iostream>
#include "Classes.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <windows.h>
using namespace std;
using namespace sf;

int main(int argc, char * argv[])
{
	//int count = Plane::projectNumber = 0;
	int x = 0, y = 0;
	/*cout << "Podaj wymiary plaszczyzny"<<endl;
	cin >> x;
	cin >> y;*/
	Plane nowy = Plane(temp_x - (temp_x/16),temp_y - ((temp_y/18)*5),(temp_x/32), ((temp_y /18)*4),Color::Magenta, Color::Black, -5);
	UI UInstance;
	UInstance.createMainMenu();
	UInstance.createWorkplace();
	bool showList = 0;
	UIPart mySwitch = UIPart:: MainMenu;
	RenderWindow window{ VideoMode(temp_x,temp_y),"Project " };
	Furniture* testowy = new Furniture(1000, 1000, 0, 0, 0, Color::Yellow, textureFile);
	bool mouseGuide = false; // okre�la czy mysz jest w trakcie przeci�gania jakiego� elementu
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
			else
			{




				/* if ((event.type == Event::MouseButtonPressed))
			{
				if (!mouseGuide)
				{
					Vector2i mPosition = Mouse::getPosition(window);
					int count = UInstance.indexList(mySwitch, window, mPosition);
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
							showList = 1;
						case 3:
							window.close();
							break;
						}
						testowy->shallGuide(mPosition, mouseGuide);
					}
				}
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

		}*/
				window.clear(Color::Red);
				(*testowy).draw(window, RenderStates::Default);
				//UInstance.displayCurrent(mySwitch, window,nowy,showList,triangle);
				window.display();
			}
		}
	}

		system("pause");
		//cin.get();
	return 0;
}