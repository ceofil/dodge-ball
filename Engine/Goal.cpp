#include "Goal.h"

void Goal::spawn(int xs, int ys)
{
	if (!spawned && deposit==true) {
		x = xs;
		y = ys;
		spawned = true;
		deposit = false;
	}
}

void Goal::draw(Graphics & gfx)
{
	gfx.DrawCircle(x, y, r, c);
	gfx.DrawCircle(x, y, r * 2 / 3, Colors::Blue);
}
void Goal::track(Face & face)
{
	x = face.GetX();
	y = face.GetY();
}
bool Goal::testColliding(Face& face)
{
	const int faceright = face.GetX() + face.GetW();
	const int facebot = face.GetY() + face.GetH();
	const int goalright = x + r;
	const int goalbot = y + r;

	return
		(
			faceright >= x - r &&
			face.GetX() <= goalright &&
			facebot >= y - r &&
			face.GetY() <= goalbot
		);
}

void Goal::cheat()
{
	x = 20;
	y = Graphics::ScreenHeight - 70;
}
