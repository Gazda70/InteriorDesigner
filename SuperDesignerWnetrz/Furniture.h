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
		void shallGuide(Vector2i mousePos, bool& isGuide);
		void moveAround(Vector2i mousePos,Plane& playground);
		void stopGuide();
		void setSize(Keyboard::Key inputBut);
		void setSize(float width, float height);
		void setSize(unsigned int width, unsigned int height);
		void setOffset(unsigned int x_axis, unsigned int  y_axis);
		void setRotation(float degrees);
		void setColor(Color myColor);
		virtual void draw(RenderTarget& target, RenderStates state) const;
	private:
		float w_scale;
		float h_scale;
		Keyboard::Key previous;
		Texture ourTexture;
		Sprite ourImage;
		bool guided;
	};