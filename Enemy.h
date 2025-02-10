#pragma once
#include"Object.h"

class Enemy : public Object{
public:
  /// <summary>
  /// コンストラクタ
  /// </summary>
  Enemy();

  /// <summary>
  /// デストラクタ
  /// </summary>
  ~Enemy();

  /// <summary>
  /// ゲッター
  /// </summary>
  /// <returns></returns>
  Vector2 GetPos() { return pos_; }
  float GetRadius() { return radius_; }
  int GetAlive() { return isAlive_; }

  /// <summary>
  /// セッター
  /// </summary>
  /// <param name="isAlive"></param>
  void SetAlive(int isAlive) { isAlive_ = isAlive; }
  void SetPos(Vector2 pos) { pos_ = pos; }

  /// <summary>
  /// 更新処理
  /// </summary>
  void Update();
  
  /// <summary>
  /// 描画処理
  /// </summary>
  void Draw();

  private:
  int isAlive_;
  int respawnTimer_;
};
