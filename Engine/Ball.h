#pragma once
#include "Graphics.h"
#include "Colors.h"
#include "Face.h"

class Ball
{
public:
	void initialize(int inx, int iny, int invx, int invy, int inr);
	void Update();
	void draw(Graphics& gfx);
	void contain();
	bool testColliding(Face & face);
	int getx();
	int gety();
	void acc();
	void setspeed(int s);
	int getspeed();
	void rpp(int v);
	void rmm(int v);
	int getr();
	int r2 = 0;
private:
	int x=300;
	int y=300;
	int r=4;
	Color c = Colors::Brown;
	int vx=1;
	int vy=1;
	int speed = 1;
	int safelen = 50;
};