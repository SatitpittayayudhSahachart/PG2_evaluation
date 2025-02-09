#include "Enemy.h"

// Constructor for Enemy
Enemy::Enemy(int posX, int posY, int radius, int speedX, int speedY, unsigned int color) :
    Object(posX, posY, radius), isAlive(true), speedX_(speedX), speedY_(speedY), color_(color) {
}

// Destructor for Enemy
Enemy::~Enemy() {}

// Update function for Enemy
void Enemy::Update() {
    if (isAlive) {
        // Update position based on speed
        posX += speedX_;
        posY += speedY_;

        // Check for boundary collision and reverse direction if needed
        if (posX - (radius / 2) < 0 || posX + (radius / 2) > 1280) {
            speedX_ *= -1;
        }
        if (posY - (radius / 2) < 0 || posY + (radius / 2) > 720) {
            speedY_ *= -1;
        }
    }
}

// Draw function for Enemy
void Enemy::Draw() {
    if (isAlive) {
        Novice::DrawEllipse(posX, posY, radius, radius, 0.0f, color_, kFillModeSolid);
    }
}

bool Enemy::CheckCollision(Bullet &bullet) {
    int deltaX = posX - bullet.GetPosX();
    int deltaY = posY - bullet.GetPosY();
    int distanceSquared = deltaX * deltaX + deltaY * deltaY;
    int radiusSum = radius + bullet.GetSize();
    return distanceSquared <= (radiusSum * radiusSum);
}