#pragma once
#include "Element.h"
#include "Furniture.h"

class Furniture;

class Plane : public Element
	{
	public:
		Plane(unsigned int width, unsigned int height, unsigned int x_axis, unsigned int  y_axis,
			Color myColor, Color oColor, int oThick);
		virtual void draw(RenderTarget& target, RenderStates state) const;
		bool isInside(Furniture* traveler, Vector2i mousePos);
		RectangleShape myplane();
		//	static int projectNumber;
	private:
		RectangleShape myPlane;
		void setSize(unsigned int width, unsigned int height);
		void setOffset(unsigned int x_axis, unsigned int  y_axis);
		void setRotation(float degrees);
		void setColor(Color myColor);
		void setOutline(Color oColor, int oThick);
	};
