#include "Project.h"
#include "Enums.h"
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
	super->addFurniture("DobreKrzeslo.png",dflt);
	super->addFurniture("DobryFotel.png", dflt);
	super->addFurniture("LepszyStol.png", dflt);
	super->addFurniture("DobreLozko.png", dflt);
	super->runProject(window);
		system("pause");
		//cin.get();
	return 0;
}