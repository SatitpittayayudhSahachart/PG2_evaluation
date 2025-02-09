#include "Player.h"

Player::Player(int posX, int posY, int radius, int speedX, int speedY, unsigned int color) :
    Object(posX, posY, radius), isAlive(true), bulletCoolTime(0), speedX_(speedX), speedY_(speedY), color_(color) {
    for (int i = 0; i < BULLET_NUM; i++) {
        bullets[i] = Bullet();
    }
}

Player::~Player() {}

void Player::Update() {
    if (isAlive) {
        for (int i = 0; i < BULLET_NUM; i++) {
            bullets[i].Update();
        }
    }
}

void Player::Draw() {
    if (isAlive) {
        Novice::DrawEllipse(posX, posY, radius, radius, 0.0f, color_, kFillModeSolid);
        for (int i = 0; i < BULLET_NUM; i++) {
            bullets[i].Draw();
        }
    }
}

void Player::Move(char *keys) {
    if (isAlive) {
        if (keys[DIK_W] && posY - radius > 0) {
            posY -= speedY_;
        }
        if (keys[DIK_S] && posY + radius < HEIGHT) {
            posY += speedY_;
        }
        if (keys[DIK_A] && posX - radius > 0) {
            posX -= speedX_;
        }
        if (keys[DIK_D] && posX + radius < WIDTH) {
            posX += speedX_;
        }

        if (keys[DIK_SPACE] && bulletCoolTime <= 0) {
            bulletCoolTime = 10;
            for (int i = 0; i < BULLET_NUM; i++) {
                if (!bullets[i].GetIsShot()) {
                    bullets[i].Shoot(posX, posY);
                    break;
                }
            }
        }
        if (bulletCoolTime > 0) {
            bulletCoolTime--;
        }
    }
}


Bullet *Player::GetBullets() {
    return bullets;
}

bool Player::CheckCollision(Enemy &enemy) {
    int deltaX = posX - enemy.GetPosX();
    int deltaY = posY - enemy.GetPosY();
    int distanceSquared = deltaX * deltaX + deltaY * deltaY;
    int radiusSum = radius + enemy.GetRadius();
    return distanceSquared <= (radiusSum * radiusSum);
}

void Player::Reset() {
    isAlive = true;
    posX = 640; // Initial X position
    posY = 600; // Initial Y position

    for (int i = 0; i < BULLET_NUM; i++) {
        bullets[i].SetPosX(0);
        bullets[i].SetPosY(0);
        bullets[i].SetIsShot(false);
    }
}