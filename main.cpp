#include <Novice.h>
#include "Object.h"
#include "Bullet.h"
#include "Player.h"
#include "Enemy.h"
#include "Scene.h"

const char kWindowTitle[] = "GC1B_06_サティッピッタヤユット_サハチャート_PG2_評価課題_2_STGクラス化";
const int kWindowWidth = 1280; //screen width
const int kWindowHeight = 720; //screen height

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, kWindowWidth, kWindowHeight);

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	SceneManager sceneManager;

	Player player(kWindowWidth / 2, 600, 30, 6, 6, GREEN);
	Enemy enemy1(kWindowWidth / 2, 200, 15, 8, 8, RED);
	Enemy enemy2(kWindowWidth / 2, 400, 15, 4, 4, RED);

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		switch (sceneManager.currentScene) {
		case SceneManager::TITLE:
			if (keys[DIK_SPACE]) {
				sceneManager.Reset(player, enemy1, enemy2);
				sceneManager.ChangeScene(SceneManager::GAMEPLAY);
			}
			break;

		case SceneManager::GAMEPLAY:
			player.Move(keys);
			player.Update();
			enemy1.Update();
			enemy2.Update();

			for (int i = 0; i < BULLET_NUM; i++) {
				Bullet *bullet = &player.GetBullets()[i];
				if (bullet->GetIsShot()) {
					if (enemy1.CheckCollision(*bullet) && enemy1.GetIsAlive()) {
						enemy1.SetIsAlive(false);
						bullet->SetIsShot(false);
					} else if (enemy2.CheckCollision(*bullet) && enemy2.GetIsAlive()) {
						enemy2.SetIsAlive(false);
						bullet->SetIsShot(false);
					}
				}
			}

			if (player.CheckCollision(enemy1) && enemy1.GetIsAlive()) {
				player.SetIsAlive(false);
			}
			if (player.CheckCollision(enemy2) && enemy2.GetIsAlive()) {
				player.SetIsAlive(false);
			}

			if (!enemy1.GetIsAlive() && !enemy2.GetIsAlive()) {
				sceneManager.ChangeScene(SceneManager::WIN);
			}
			if (!player.GetIsAlive()) {
				sceneManager.ChangeScene(SceneManager::GAMEOVER);
			}
			break;

		case SceneManager::WIN:
		case SceneManager::GAMEOVER:
			if (keys[DIK_R]) {
				sceneManager.ChangeScene(SceneManager::TITLE);
			}
			break;
		}

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		
		Novice::DrawBox(0, 0, kWindowWidth, kWindowHeight, 0.0F, BLACK, kFillModeSolid);
		switch (sceneManager.currentScene) {
		case SceneManager::TITLE:
			Novice::ScreenPrintf(550, 360, "Press SPACE to Start", WHITE);
			break;
		case SceneManager::GAMEPLAY:
			player.Draw();
			enemy1.Draw();
			enemy2.Draw();
			Novice::ScreenPrintf(10, 10, "EnemyA isAlive = %d", enemy1.GetIsAlive());
			Novice::ScreenPrintf(10, 30, "EnemyB isAlive = %d", enemy2.GetIsAlive());
			Novice::ScreenPrintf(10, 50, "WASD : player Move");
			Novice::ScreenPrintf(10, 70, "shoot : SPACE");
			break;
		case SceneManager::WIN:
			Novice::ScreenPrintf(600, 360, "You Win!", WHITE);
			Novice::ScreenPrintf(600, 380, "press R to return to title", WHITE);
			break;
		case SceneManager::GAMEOVER:
			Novice::ScreenPrintf(600, 360, "Game Over", WHITE);
			Novice::ScreenPrintf(600, 380, "press R to return to title", WHITE);
			break;
		}

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
