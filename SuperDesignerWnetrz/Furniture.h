#pragma once

#include "Element.h"
#include "Plane.h"

class Plane;

using namespace std;

class Furniture : public Element
	{
	public:
		Furniture() = default;
		Furniture(float width, float height,
			unsigned int x_axis, unsigned int y_axis, float degrees, Color myColor, string textureFile);
		Furniture(const Furniture &toCopy);
		void drawMe(RenderWindow& window, RenderStates state);
		void manageInput(Vector2i mousePos, Keyboard::Key pressed, change mode);
		Element* manageScreenBehaviour( change mode);
		void setPosition(Vector2i position);
		bool isActivated();
		void setColor(Color& myColor, change mode);
	private:
		void setSize(float width, float height);
		void setSize(unsigned int width, unsigned int height);
		void setOffset(unsigned int x_axis, unsigned int  y_axis);
		void setRotation(float degrees);
		float w_scale;
		float h_scale;
		float angle;
		Keyboard::Key previous;
		Texture ourTexture;
		Sprite ourImage;
		bool guided;
	};
