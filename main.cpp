#include "Enemy.h"
#include "Player.h"
#include <Novice.h>
#define _USE_MATH_DEFINES
#include <math.h>

const char kWindowTitle[] = "LC1B_27_ヤマダナオ_PG2_評価課題";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

  // ライブラリの初期化
  Novice::Initialize(kWindowTitle, 1280, 720);

  // キー入力結果を受け取る箱
  char keys[256] = {0};
  char preKeys[256] = {0};

  Player *player = new Player();
  Enemy *enemy = new Enemy();

  enum Scene { TITLE, GAME_PLAY };
  Scene scene = TITLE;

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

    switch (scene) {
    case TITLE:
      if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
        scene = GAME_PLAY;
      }

      Novice::ScreenPrintf(600, 360, "TITLE");

      break;
    case GAME_PLAY:

      /// ==========================
      /// 更新処理
      /// ==========================
      player->Update(keys,preKeys);
      enemy->Update();
      

      // プレイヤーと敵の当たり判定
      if (player->GetAlive() && enemy->GetAlive()) {
        if (sqrtf(powf(player->GetPos().x - enemy->GetPos().x, 2) +
                  powf(player->GetPos().y - enemy->GetPos().y, 2)) <=
            player->GetRadius() + enemy->GetRadius()) {
          player->SetAlive(false);
          enemy->SetAlive(false);
        }
      }

      // プレイヤーの弾と敵の当たり判定
      if (player->GetBulletShoot() && enemy->GetAlive()) {
        if (sqrtf(powf(player->GetBulletPos().x - enemy->GetPos().x, 2) +
                  powf(player->GetBulletPos().y - enemy->GetPos().y, 2)) <=
            player->GetBulletRadius() + enemy->GetRadius()) {
          player->SetBulletShoot(false);
          enemy->SetAlive(false);
        }
      }

      /// ==========================
      /// 描画処理
      /// ==========================
      player->Draw();
      enemy->Draw();
      break;
    }

    ///
    /// ↑更新処理ここまで
    ///

    ///
    /// ↓描画処理ここから
    ///

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

  delete player;
  delete enemy;

  // ライブラリの終了
  Novice::Finalize();
  return 0;
}
