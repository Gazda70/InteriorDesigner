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
		system("pause");
		//cin.get();
	return 0;
}