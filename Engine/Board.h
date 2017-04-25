#pragma once
#include "Graphics.h"

class Board
{
public:
	Board(Graphics& gfx, int xup, int yup, int xd, int yd, int wi, int he);
	void DrawCell(int x, int y, Color c);
	void DrawLine(int x, Color c);
	void Draw4Line(int poz, int y, Color c);
	void Draw4LineStroke(int poz, int y, Color c);
	void DrawCol(int y, Color c);
	void DrawColUp(int y, Color c);
	void DrawColDown(int y, Color c);
	void DrawCellStroke(int x, int y, Color c);

	
		void draw1(int poz, Color c);
		void draw2(int poz, Color c);
		void draw3(int poz, Color c);
		void draw4(int poz, Color c);
		void draw5(int poz, Color c);
		void draw6(int poz, Color c);
		void draw7(int poz, Color c);
		void draw8(int poz, Color c);
		void draw9(int poz, Color c);
		void draw0(int poz, Color c);

		void drawint(int n, Color c, int poz);
		void drawG(int x, int y, Color c);
	
	int getw();
	int geth();
	int xboard = 1;
	int yboard = 1;
private:
	int xdim=10;
	int ydim=10;
	int w = gfx.ScreenWidth / xdim;
	int h = gfx.ScreenHeight / ydim;
	Graphics& gfx;
};