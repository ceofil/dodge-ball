#pragma once
#include "Graphics.h"
#include "Colors.h"
#include "Face.h"
class Goal
{
public:
	void spawn(int xs, int ys);
	void draw(Graphics& gfx);
	void track(Face& face);
	bool testColliding(Face& face);
	bool spawned = false;
	bool deposit = true;
	void cheat();
private:
	int x=5;
	int y=5;
	int r=10;
	Color c = Colors::Yellow;
};