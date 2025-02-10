#include "Enemy.h"
#include<Novice.h>

/// <summary>
/// コンストラクタ
/// </summary>
Enemy::Enemy() {
  pos_ = {700.0f, 360.0f};
  speed_ = 6.0f;
  radius_ = 32.0f;
  isAlive_ = true;
  respawnTimer_ = 60;
}

/// <summary>
/// デストラクタ
/// </summary>
Enemy::~Enemy() {}

/// <summary>
/// 更新処理
/// </summary>
void Enemy::Update() {
  if (isAlive_) {
    pos_.y += speed_;

    if (pos_.y + radius_ >= 720.0f || pos_.y - radius_ <= 0.0f) {
      speed_ = -speed_;
    }
  } else {
    respawnTimer_--;

    if (respawnTimer_ <= 0) {
      isAlive_ = true;
      SetPos({700.0f, 360.0f});
      respawnTimer_ = 60;
    }
  }
}

/// <summary>
/// 描画処理
/// </summary>
void Enemy::Draw() {
  if (isAlive_) {
    Novice::DrawEllipse(static_cast<int>(pos_.x), static_cast<int>(pos_.y),
                        static_cast<int>(radius_), static_cast<int>(radius_),
                        0.0f, RED, kFillModeSolid);
  }
}
