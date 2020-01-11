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
	Plane nowy = Plane(temp_x - (temp_x/16),temp_y - ((temp_y/18)*5),(temp_x/32), ((temp_y /18)*4),Color::White, Color::Black, -5);
	UI UInstance;
	UInstance.createMainMenu();
	UInstance.createWorkplace();
	bool showList = 0;
	UIPart mySwitch = UIPart:: MainMenu;
	RenderWindow window{ VideoMode(temp_x,temp_y),"Project " };
	Furniture* testowy = new Furniture(1000, 1000, 100, 100, 0, Color::Yellow, textureFile);
	bool mouseGuide = false; // okreœla czy mysz jest w trakcie przeci¹gania jakiegoœ elementu
	window.setVerticalSyncEnabled(true);
	VertexArray triangleFan(TriangleFan, 4);

	triangleFan[0].position = Vector2f(50, 150);
	triangleFan[0].color = Color::Red;

	triangleFan[1].position = Vector2f(200, 75);
	triangleFan[1].color = Color::Green;

	triangleFan[2].position = Vector2f(400, 456);
	triangleFan[2].color = Color::Cyan;

	triangleFan[3].position = Vector2f(600, 90);
	triangleFan[3].color = Color::Blue;

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
				window.clear(Color::White);
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