#pragma once
#include "Graphics.h"
#include "Keyboard.h"
class Face
{
public:
	void contain();
	void draw(Graphics & gfx) const;
	void Update(const Keyboard& kbd);
	int GetX()const;
	int GetY()const;
	int GetW()const;
	int GetH()const;
	int GetSpeed()const;
	void setspeed(int s);
	void safezone(int k);
	bool active=true;
	void ala();
private:
	int x = (Graphics::ScreenWidth - w)/2; 
	int y = Graphics::ScreenHeight - h;
	int speed = 5;
	static constexpr int w = 20;
	static constexpr int h = 20;
};

