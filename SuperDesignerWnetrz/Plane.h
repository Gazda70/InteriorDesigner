#pragma once
#include "Element.h"
#include "Furniture.h"

class Furniture;

class Plane : public Element
	{
	public:
		Plane(unsigned int width, unsigned int height, unsigned int x_axis, unsigned int  y_axis,
			Color myColor, Color oColor, int oThick);
		 void drawMe(RenderWindow& window, RenderStates state);
		 void manageInput(Vector2i mousePos, Keyboard::Key pressed, change mode);
		 Element* manageScreenBehaviour(change mode);
		 istream& operator>>(istream& is);
		 ostream& operator<<(ostream& os);
		 void setPosition(Vector2i position);
		bool isActivated();
		RectangleShape myplane();
		Element* traveler;
	private:
		RectangleShape myPlane;
		bool isInside;
		void setColor(Color& myColor, change mode);
		void setSize(unsigned int width, unsigned int height);
		// void setOffset(unsigned int x_axis, unsigned int y_axis);
		 void setOutline(Color oColor,int oThick);
	};
