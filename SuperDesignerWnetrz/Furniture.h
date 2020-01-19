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
			unsigned int x, unsigned int y, float degrees, Color myColor, string textureFile);
		Furniture(const Furniture &toCopy);
		void drawMe(RenderWindow& window, RenderStates state);
		void manageInput(Vector2i mousePos, Keyboard::Key pressed, change mode);
		Element* manageScreenBehaviour( change mode);
		void setPosition(Vector2i position);
		bool isActivated();
		void setColor(Color& color, change mode);
	istream& operator>>(istream& is);
	ostream& operator<<(ostream& os);
	private:
		void correctOrigin();
		void setSize(float width, float height);
		void setSize(unsigned int width, unsigned int height);
		void setRotation(float degrees);
		void fixScale(int incr, int dcr);
		float x_scale;
		float y_scale;
		int incr_scale;
		int dcr_scale;
		float angle;
		Keyboard::Key previous;
		Texture ourTexture;
		Sprite ourImage;
		string textureFile;
		bool guided;
	};
