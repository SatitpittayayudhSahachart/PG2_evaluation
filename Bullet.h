#pragma once
#include "Object.h"

class Bullet {
public:
    int GetPosX() const { return posX; }
    int GetPosY() const { return posY; }
    bool GetIsShot() const { return isShot; }
    int GetSize() const { return size; }
    int GetSpeed() const { return speed; }

    void SetPosX(int x) { posX = x; }
    void SetPosY(int y) { posY = y; }
    void SetIsShot(bool shot) { isShot = shot; }
    void SetSize(int s) { size = s; }
    void SetSpeed(int s) { speed = s; }

    Bullet();
    ~Bullet();
    void Update();
    void Shoot(int startPosX, int startPosY);
    void Draw();

private:
    int posX;
    int posY;
    bool isShot;
    int size;
    int speed;
};
