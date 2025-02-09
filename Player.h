#pragma once
#include "Object.h"
#include "Bullet.h"
#include "Enemy.h"

const int BULLET_NUM = 10;

class Player : public Object {
public:
    bool GetIsAlive() const { return isAlive; }
    void SetIsAlive(bool alive) { isAlive = alive; }

    Player(int posX, int posY, int radius, int speedX, int speedY, unsigned int color);
    ~Player();
    void Update() override;
    void Draw() override;
    void Move(char *keys);
    Bullet *GetBullets();
    bool CheckCollision(Enemy &enemy);
    void Reset(); // Add this function

private:
    Bullet bullets[BULLET_NUM];
    float bulletCoolTime;
    int speedX_;
    int speedY_;
    unsigned int color_;
    bool isAlive;
};
