/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.h																				  *
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
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include <cmath>
#include <random>
#include "Board.h"
#include "Ball.h"
#include "Face.h"
#include "Goal.h"


class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel();
	
	/********************************/
	/*  User Functions              */

	void drawprogress();
	void accall();
	void rppall(int p);
	/********************************/
private:
	MainWindow& wnd;
	Graphics gfx;
	/********************************/
	/*  User Variables              */
	

	std::random_device rd;
	std::mt19937 rng;
	std::uniform_int_distribution<int> xrange;
	std::uniform_int_distribution<int> yrange;
	std::uniform_int_distribution<int> vrange;
	std::uniform_int_distribution<int> rgbrange;
	std::uniform_int_distribution<int> boolrange;
	std::uniform_int_distribution<int> krange;
	std::uniform_int_distribution<int> drange;

	Board nr;
	Board progress;
	static constexpr int num = 10;
	int n = 3;
	Ball ballz[num];
	Face face;
	Goal goal;

	int test = 0;
	int x = 300, y = 400;
	int r = 10;
	bool gameover = false;
	bool win = false;
	int klife = 0;
	int level = 0;
	

	/********************************/
};


