#include "Bullet.h"

Bullet::Bullet() : posX(0), posY(0), isShot(false), size(10), speed(20) {}

Bullet::~Bullet() {}

void Bullet::Update() {
    if (isShot) {
        posY -= speed;
        if (posY < 0 - size) {
            isShot = false;
            posX = 0;
            posY = 0;
        }
    }
}

void Bullet::Shoot(int startPosX, int startPosY) {
    if (!isShot) {
        isShot = true;
        posX = startPosX;
        posY = startPosY;
    }
}

void Bullet::Draw() {
    if (isShot) {
        Novice::DrawTriangle(
            posX - size, posY,
            posX, posY - size * 2,
            posX + size, posY,
            WHITE, kFillModeSolid);
    }
}
