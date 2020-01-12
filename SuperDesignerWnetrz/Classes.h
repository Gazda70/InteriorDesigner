#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string.h>
#include <iostream>
#include <vector>

constexpr auto temp_x = 1600;
constexpr auto temp_y = 900;
constexpr auto fontFile = "times.ttf";
constexpr auto textureFile = "DobreLozko.png";

using namespace sf;
using namespace std;

enum UIPart { MainMenu, WorkPlace };
class Plane;
class Element 
{
protected:
	Element() = default;
	Element(unsigned int width, unsigned int height, unsigned int x_axis, unsigned int y_axis, float degrees, Color myColor);
private:
	unsigned int width;
	unsigned int height;
	unsigned int x_axis;
	unsigned int y_axis;
	float degrees;
	Color myColor;
	virtual void setSize(unsigned int width, unsigned int height) = 0;
	virtual void setOffset(unsigned int x_axis, unsigned int  y_axis) = 0;
	virtual void setRotation(float degrees) = 0;
	virtual void setColor(Color myColor) = 0;
};
class Furniture : public Element
{
public:
	Furniture() = default;
	Furniture(unsigned int width, unsigned int height,
		unsigned int x_axis, unsigned int y_axis, float degrees, Color myColor, string textureFile);
	void shallGuide(Vector2i mousePos, bool& isGuide);
	void moveAround(Vector2i mousePos, Plane& playground);
	void stopGuide();
	void setSize(unsigned int width, unsigned int height);
	void setOffset(unsigned int x_axis, unsigned int  y_axis);
	void setRotation(float degrees);
	void setColor(Color myColor);
	virtual void draw(RenderTarget& target, RenderStates state) const;
private:
	Texture ourTexture;
	Sprite ourImage;
	bool guided;
};
class Plane : public Element
{
public :
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
class UIElement : public Element, public Drawable
{
public:
	UIElement() = default;
	UIElement(unsigned int width, unsigned int height, unsigned int xS_axis, unsigned int yS_axis, 
		 float degrees, Color myColor, string message,
		unsigned int textSize, Color tColor, Text::Style tBold, Text::Style tUnderline);
	RectangleShape getInteractionWindow();
	Text getText();
	UIElement* next = nullptr;
protected:
	void setText(const string myMes, unsigned int mySize, Color color, Text::Style ifBold, Text::Style ifUnderline);
	void setShape(unsigned int width, unsigned int height, unsigned int x_axis, unsigned int y_axis, float degrees, Color myColor);
	void setSize(unsigned int width, unsigned int height);
	void setOffset(unsigned int x_axis, unsigned int  y_axis);
	void setRotation(float degrees);
	void setColor(Color myColor);
	virtual void draw(RenderTarget& target, RenderStates state) const override;
//private:
	Text myText;
	RectangleShape interactionWindow;
	Vector2f size;//wektor okreslajacy wysokosc i szerokosc obiektu
	Color myColor;
	Font myFont;
};
class Button : public UIElement
{
public:
	Button(unsigned int width, unsigned int height, unsigned int xS_axis, unsigned int yS_axis,
		 float degrees, Color myColor, string message,
		unsigned int textSize, Color tColor, Text::Style tBold, Text::Style tUnderline);
	virtual void draw(RenderTarget& target, RenderStates state) const override;
};
class DropDownList : public UIElement
{
public:
	DropDownList(Vector2f startPos, unsigned int width, unsigned int height, Color myColor,
		unsigned int textSize, Color tColor, Text::Style tBold, Text::Style tUnderline, int ouThick, Color ouColor);
	vector<UIElement*>& getList();
	void addPart(string another);
	 void drawList(RenderWindow& window);
private:
	vector<UIElement*> elements;
	Vector2f startPosition;
	unsigned int width;
	unsigned int height;
	Color myColor;
	unsigned int textSize;
	Color tColor;
	Text::Style tBold;
	Text::Style tUnderline;
	int ouThick;
	Color ouColor;
};
class UI 
{
public:
	void createMainMenu();
	void createWorkplace();
	void displayCurrent(UIPart current, RenderWindow &window, Plane &myPlane, bool showList, VertexArray& test);
	int indexList(UIPart current, RenderWindow& window, Vector2i mousePos);
	vector<UIElement*>& getList(UIPart current);
private:
	vector<UIElement*> mainMenu;
	vector<UIElement*> workPlace;
	DropDownList* furnitureList;
	unsigned int res_x;
	unsigned int res_y;
	void displayUI(vector<UIElement*>& myList, RenderWindow &window);
};

class Project 
{

};
