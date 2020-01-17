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
		 void manageMouseInput(Vector2i mousePos);
		 bool isActivated();
		RectangleShape myplane();
		Furniture* traveler;
		//	static int projectNumber;
	private:
		RectangleShape myPlane;
		bool isInside;
		void setSize(unsigned int width, unsigned int height);
		void setOffset(unsigned int x_axis, unsigned int  y_axis);
		void setRotation(float degrees);
		void setColor(Color myColor);
		void setOutline(Color oColor, int oThick);
	};
