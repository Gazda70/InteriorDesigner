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
	//nowy.myplane().getSize().x/2
	//nowy.myplane().getSize().y/2
	Furniture* testowy = new Furniture(0.2f, 0.2f, nowy.myplane().getSize().x / 2,
		nowy.myplane().getSize().y / 1.5f, 0, Color::Red, textureFile);
	bool mouseGuide = false; // okreœla czy mysz jest w trakcie przeci¹gania jakiegoœ elementu
	window.setVerticalSyncEnabled(true);
	RectangleShape test1;
	Vector2f help = Vector2f(200, 300);
	test1.setFillColor(Color::Black);
	test1.setSize(help);
	test1.setPosition(help);
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
				testowy->setSize(event.key.code);
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
			else
			{
				showList = UInstance.isMouseOverHim(mySwitch, window, Mouse::getPosition(window));
			}
				window.clear(Color::Blue);
			//	(*testowy).draw(window, RenderStates::Default);
				if (showList)
				{
			//		window.draw(test1);
					//UInstance.furnitureList->drawList(UInstance.furnitureList->ourlist, window);
				}
				UInstance.displayCurrent(mySwitch, window,nowy,showList,testowy);
				window.display();
		}
	}

		system("pause");
		//cin.get();
	return 0;
}