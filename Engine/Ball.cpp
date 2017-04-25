#include "Ball.h"

void Ball::initialize(int inx, int iny, int invx, int invy, int inr)
{
	x = inx;
	y = iny;
	vx = invx;
	vy = invy;
	r = inr;
}

void Ball::Update()
{
	x += vx * speed;
	y += vy * speed;
	contain();
}

void Ball::draw(Graphics& gfx)
{
	gfx.DrawCircleEmpty(x, y, r, r2,c);
}

void Ball::contain()
{
	if (x - r < 0) {
		x = r;
		vx = -vx;
	}
	if (y - r < 0) {
		y = r;
		vy = -vy;
	}
	if (x + r >= Graphics::ScreenWidth) {
		x = Graphics::ScreenWidth - r;
		vx = -vx;
	}
	if (y + r >= Graphics::ScreenHeight - safelen) {
		y = Graphics::ScreenHeight - safelen - r;
		vy = -vy;
	}
}

bool Ball::testColliding(Face& face) 
{
	const int faceright = face.GetX() + face.GetW();
	const int facebot = face.GetY() + face.GetH();
	const int ballright = x + r;
	const int ballbot = y + r;

	return
		(
			faceright >= x - r &&
			face.GetX()<= ballright &&
			facebot >= y - r &&
			face.GetY()<= ballbot
			);
}

int Ball::getx()
{
	return x;
}

int Ball::gety()
{
	return y;
}

void Ball::acc()
{
	speed++;
}

void Ball::setspeed(int s)
{
	speed = s;
}

int Ball::getspeed()
{
	return speed;
}

void Ball::rmm(int v)
{
	r -= v;
}

int Ball::getr()
{
	return r;
}

void Ball::rpp(int v)
{
	r += v;
}
