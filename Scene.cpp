#include "Scene.h"

SceneManager::SceneManager() : currentScene(TITLE) {}

void SceneManager::ChangeScene(Scene newScene) {
	currentScene = newScene;
}

void SceneManager::Reset(Player &player, Enemy &enemy1, Enemy &enemy2) {
	player.SetPosX(640);
	player.SetPosY(600);
	player.SetIsAlive(true);

	enemy1.SetPosX(640);
	enemy1.SetPosY(200);
	enemy1.SetIsAlive(true);

	enemy2.SetPosX(640);
	enemy2.SetPosY(400);
	enemy2.SetIsAlive(true);

	// Reset bullets
	for (int i = 0; i < BULLET_NUM; i++) {
		 Bullet *bullet = &player.GetBullets()[i];
        bullet->SetPosX(0);
        bullet->SetPosY(0);
        bullet->SetIsShot(false);
	}
}
