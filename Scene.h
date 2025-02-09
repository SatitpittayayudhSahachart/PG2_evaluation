#ifndef SCENE
#define SCENE

#include "Player.h"
#include "Enemy.h"

class SceneManager {
public:
    enum Scene {
        TITLE,
        GAMEPLAY,
        WIN,
        GAMEOVER
    };

    Scene currentScene;

    SceneManager();
    void ChangeScene(Scene newScene);
    void Reset(Player &player, Enemy &enemy1, Enemy &enemy2);
};

#endif // SCENE
