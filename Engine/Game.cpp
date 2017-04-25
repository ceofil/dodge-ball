/******************************************************************************************
 *	Chili DirectX Framework Version 16.07.20											  *
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"
#include <cmath>
#include <random>

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	rng(rd()),
	xrange(30, gfx.ScreenWidth-20),
	yrange(30, gfx.ScreenHeight/2),
	vrange(-1, 1),
	rgbrange(100,200),
	boolrange(-50,50),
	krange(0,14),
	drange(40,130),
	nr(gfx, Graphics::ScreenWidth / 2-20,50,3,3,50,7),
	progress(gfx,3,550, Graphics::ScreenWidth / 15,48,14,0)  //0,Graphics::ScreenWidth-100,Graphics::ScreenWidth/15,100,15,1)
{	
	for (int i = 0; i < num; i++) {
		
		int vex = vrange(rng);
		while (vex == 0) {
			vex = vrange(rng);
		}
		
		int vey = vrange(rng);
		while (vey == 0) {
			vey = vrange(rng);
		}

		ballz[i].initialize(xrange(rng), yrange(rng), vex, vey, r);
		goal.spawn(xrange(rng), yrange(rng));
		
	}
}

void Game::Go()
{
	gfx.BeginFrame();
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	if (!gameover) {
		if (!face.active) {
			if (face.GetY() < 550 - face.GetH()) {
				face.active = true;
			}
		}

		for (int i = 0; i < n; i++) {
			if (ballz[i].testColliding(face)) {
				face.safezone( (klife-1) * Graphics::ScreenWidth / 15 + Graphics::ScreenWidth / 15 / 2 - face.GetW()/2);
				face.active = false;
				klife--;
			}
		}
		if (goal.testColliding(face)) {
			
			goal.spawned = false;
			if (goal.deposit == true)
			{
				goal.spawn(xrange(rng), yrange(rng));
			}
			else {
				goal.track(face);
				if (face.GetY() > Graphics::ScreenHeight - 50) {
					goal.deposit = true;
					if (klife == level) {
						level++;
						if (level == 1) {
							accall();
						}
						if(level==2){
							accall();
						}
						if(level==3){
							accall();
						}
						if(level==4){
							accall();
						}
						if(level==5){
							n++;
						}
						if(level==6){
							//accall();
						}
						if(level==7){
							accall();
						}
						if(level==8){
							//accall();
						}
						if (level == 9) {
							//accall();
						}
						if (level == 10) {
							n++;
						}
						if(level==11){
							//rppall(2);
						}
						if (level == 12) {
							rppall(2);
						}
						if (level == 13) {
							rppall(2);
						}
						if (level == 14) {
							rppall(2);
						}
						if(level==15){
							n += 2;
						}

						

					}
					klife++;
					
				}
			}
		}
		for (int i = 0; i < n; i++) {
			ballz[i].Update();
		}
		face.Update(wnd.kbd);
	}
	
	if (klife < 0) {
		gameover = true;
		win = false;
	}
	else {
		if (klife > 15) {
			gameover = true;
			win = true;
		}
	}
	
	if (gameover == true && win == false) 
	{
		if (ballz[0].getr() < 1600) {
			for (int i = 0; i < num; i++) {
				ballz[i].rpp(10);
			}
		}
	}
	if (gameover && win) {
		if (ballz[0].getr() > ballz[0].r2 && ballz[0].getr()<5000) {
			for (int i = 0; i < num; i++) {
				ballz[i].rpp(4);
				ballz[i].r2 += 5;
			}
		}
		else {
			for (int i = 0; i < num; i++) {
				ballz[i].r2 = 0;
				ballz[i].rmm(ballz[num-1].getr());
			}
		}
		if (progress.yboard > 1) {
			progress.yboard--;
		}
		
			
		
	}
	if (wnd.kbd.KeyIsPressed(VK_RETURN))
		if (wnd.kbd.KeyIsPressed(VK_CONTROL)) {
			goal.cheat();
			face.ala();
		}
}





void Game::ComposeFrame()
{
	Color w(30, 30, 30);
	gfx.DrawCircle(gfx.ScreenWidth / 3 + 2, progress.yboard, 4, Colors::Red);
	gfx.DrawCircle(gfx.ScreenWidth / 3 * 2 + 1, progress.yboard, 4, Colors::Red);
	gfx.DrawRectPoints(0, progress.yboard, gfx.ScreenWidth, gfx.ScreenHeight, w);

	for (int i = 0; i < n; i++) {
		ballz[i].draw(gfx);
	}

	
	
	
	if (!gameover) {
		drawprogress();
		if (!face.active) {
			progress.DrawCellStroke(klife, 0, Colors::Yellow);
		}

		goal.draw(gfx);
		face.draw(gfx);
	}
	
	if (gameover&&win) {
		for (int i = 0; i < 15; i++) {
			for (int j = 0; j < 13; j++) {
				if (progress.yboard + j * 48 < gfx.ScreenHeight) {
					Color c(0, rgbrange(rng), 0);
					progress.DrawCellStroke(i, j, c);
					
				}
			}
		}
		Color c(0, drange(rng), 0);
		progress.drawG(3, 3, c);
		progress.drawG(8, 3, c);
	}
	/*
	nr.drawint(klife, Colors::White, 0);
	nr.drawint(level, Colors::White, 20);
	nr.drawint(ballz[0].getr(), Colors::White, 40);
	nr.drawint(ballz[0].getspeed(), Colors::White, 60);
	*/
	nr.drawint(klife, Colors::White, 0);
}




void Game::drawprogress()
{
	
	for (int i = 0; i < klife; i++) {
		progress.DrawCellStroke(i, 0, Colors::Green);
	}
	if (klife == 15 && gameover==false) {
		Color c(0, rgbrange(rng), 0);
		progress.DrawCellStroke(krange(rng), 0, c);
	}

}

void Game::accall()
{
	for (int i = 0; i < num; i++) {
		ballz[i].acc();
	}
}

void Game::rppall(int p)
{
	for (int i = 0; i < num; i++) {
		ballz[i].rpp(p);
	}
}

