#pragma once
#include "Object.h"
#include "Vector2.h"
#include "Bullet.h"

class Enemy : public Object {
public:
	bool GetIsAlive() const { return isAlive; }
	void SetIsAlive(bool alive) { isAlive = alive; }
	int GetPosX() const { return posX; }
	int GetPosY() const { return posY; }
	int GetRadius() const { return radius; }

	Enemy(int posX, int posY, int radius, int speedX, int speedY, unsigned int color);
	~Enemy();
	void Update() override;
	void Draw() override;
	bool CheckCollision(Bullet &bullet);

private:
	int speedX_;
	int speedY_;
	unsigned int color_;
	bool isAlive;
};

