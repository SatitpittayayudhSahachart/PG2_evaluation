#pragma once
#include <Novice.h>

#define WIDTH 1280
#define HEIGHT 720

class Object {
public:
	virtual void Update() = 0;
	virtual void Draw() = 0;

	int GetPosX() const { return posX; }
	int GetPosY() const { return posY; }
	int GetRadius() const { return radius; }
	void SetPosX(int x) { posX = x; }
	void SetPosY(int y) { posY = y; }
	void SetRadius(int r) { radius = r; }

	Object(int posX, int posY, int radius) : posX(posX), posY(posY), radius(radius) {}

protected:
	int posX;
	int posY;
	int radius;
};
