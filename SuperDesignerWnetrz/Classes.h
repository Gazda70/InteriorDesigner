#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string.h>
#include <iostream>
#include <vector>

constexpr auto temp_x = 1600;
constexpr auto temp_y = 900;
constexpr auto fontFile = "times.ttf";
constexpr auto textureFile = "DobreKrzeslo.png";

using namespace sf;
using namespace std;

enum UIPart { MainMenu, WorkPlace };
class Plane;
class Element 
{
protected:
	Element() = default;
	Element(unsigned int width, unsigned int height, unsigned int x_axis, unsigned int y_axis, float degrees, Color myColor);
	unsigned int width;
	unsigned int height;
	unsigned int x_axis;
	unsigned int y_axis;
	float degrees;
	Color myColor;
private:
	virtual void setSize(unsigned int width, unsigned int height) = 0;
	virtual void setOffset(unsigned int x_axis, unsigned int  y_axis) = 0;
	virtual void setRotation(float degrees) = 0;
	virtual void setColor(Color myColor) = 0;
};
class Furniture : public Element
{
public:
	Furniture() = default;
	Furniture(float width, float height,
		unsigned int x_axis, unsigned int y_axis, float degrees, Color myColor, string textureFile);
	void shallGuide(Vector2i mousePos, bool& isGuide);
	void moveAround(Vector2i mousePos, Plane& playground);
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
	UIElement(unsigned int width, unsigned int height, unsigned int x_axis, unsigned int y_axis, Color myColor,
		unsigned int textSize, Color tColor, Text::Style tBold, Text::Style tUnderline, int ouThick, Color ouColor, string message);
	RectangleShape getInteractionWindow();
	Text getText();
	UIElement* next = nullptr;
	RectangleShape interactionWindow;
	bool whenMouseOverMe();
	virtual void draw(RenderTarget& target, RenderStates state) const override;
protected:
	void setText(const string myMes, unsigned int mySize, Color color, Text::Style ifBold, Text::Style ifUnderline);
	void setShape(unsigned int width, unsigned int height, unsigned int x_axis, unsigned int y_axis, float degrees, Color myColor);
	void setSize(unsigned int width, unsigned int height);
	void setOffset(unsigned int x_axis, unsigned int  y_axis);
	void setRotation(float degrees);
	void setColor(Color myColor);
//private:
	Text myText;
	Vector2f size;//wektor okreslajacy wysokosc i szerokosc obiektu
//	Color myColor;
	Font myFont;
};
class DropDownList : public UIElement
{
public:
	DropDownList(unsigned int width, unsigned int height, unsigned int x_axis, unsigned int y_axis, Color myColor,
		unsigned int textSize, Color tColor, Text::Style tBold, Text::Style tUnderline, int ouThick, Color ouColor);
	void addPart(string another);
	void drawList(vector<UIElement*>& myList, RenderWindow & window);
	vector<UIElement*> ourlist;
private:
	Color myColor;
	unsigned int textSize;
	unsigned int helpy;
	Color tColor;
	Text::Style tBold;
	Text::Style tUnderline;
	int ouThick;
	Color ouColor;
	//friend void UI::displayCurrent(UIPart current, RenderWindow &window, Plane &myPlane, bool showList, Furniture* testowy);
};
class UI 
{
public:
	void createMainMenu();
	void createWorkplace();
	void displayCurrent(UIPart current, RenderWindow &window, Plane &myPlane, bool showList, Furniture* testowy);
	int indexList(UIPart current, RenderWindow& window, Vector2i mousePos);
	bool isMouseOverHim(UIPart current, RenderWindow& window, Vector2i mousePos);
	vector<UIElement*>& getList(UIPart current);
	DropDownList* furnitureList;
private:
	vector<UIElement*> mainMenu;
	vector<UIElement*> workPlace;
	unsigned int res_x;
	unsigned int res_y;
	void displayUI(vector<UIElement*>& myList, RenderWindow &window);
};

class Project 
{

};
