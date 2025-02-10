#pragma once
#include "Object.h"
#include"Bullet.h"

class Player : public Object {
public:
  /// <summary>
  /// コンストラクタ
  /// </summary>
  Player();

  /// <summary>
  /// デストラクタ
  /// </summary>
  ~Player();

  /// <summary>
  /// ゲッター
  /// </summary>
  /// <returns></returns>
  Vector2 GetPos() { return pos_; }
  float GetRadius() { return radius_; }
  int GetAlive() { return isAlive_; }

  /// <summary>
  /// ゲッター
  /// </summary>
  /// <returns></returns>
  Vector2 GetBulletPos() { return bullet_->GetPos(); }
  float GetBulletRadius() { return bullet_->GetRadius(); }
  int GetBulletShoot() { return bullet_->GetShoot(); }

  /// <summary>
  /// セッター
  /// </summary>
  /// <param name="isAlive"></param>
  void SetAlive(int isAlive) { isAlive_ = isAlive; }
  void SetPos(Vector2 pos) { pos_ = pos; }

  void SetBulletShoot(int isShoot) { bullet_->SetShoot(isShoot); }

  /// <summary>
  /// 更新処理
  /// </summary>
  /// <param name="keys"></param>
  void Update(const char *keys, const char *preKeys);

  /// <summary>
  /// 描画処理
  /// </summary>
  void Draw();

public:
  int isAlive_;
  int respawnTimer_;

  Bullet *bullet_;
};
