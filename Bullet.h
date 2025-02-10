#pragma once
#include "Object.h"

class Bullet : public Object {
public:
  /// <summary>
  /// コンストラクタ
  /// </summary>
  Bullet();

  /// <summary>
  /// デストラクタ
  /// </summary>
  ~Bullet();

  /// <summary>
  /// ゲッター
  /// </summary>
  /// <returns></returns>
  Vector2 GetPos() { return pos_; }
  float GetRadius() { return radius_; }
  int GetShoot() { return isShoot_; }

  /// <summary>
  /// セッター
  /// </summary>
  /// <param name="pos"></param>
  void SetPos(Vector2 pos) { pos_ = pos; }
  void SetShoot(int isShoot) { isShoot_ = isShoot; }

  /// <summary>
  /// 更新処理
  /// </summary>
  void Update();

  /// <summary>
  /// 描画処理
  /// </summary>
  void Draw();

public:
  int isShoot_;
};
