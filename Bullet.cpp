#include "Bullet.h"
#include <Novice.h>

/// <summary>
/// コンストラクタ
/// </summary>
Bullet::Bullet() {
  pos_ = {0.0f, 0.0f};
  speed_ = 10.0f;
  radius_ = 8.0f;
  isShoot_ = false;
}

/// <summary>
/// デストラクタ
/// </summary>
Bullet::~Bullet() {}

/// <summary>
/// 更新処理
/// </summary>
void Bullet::Update() {
  if (isShoot_) {
    pos_.x += speed_;

    if (pos_.x - radius_ >= 1280.0f) {
      isShoot_ = false;
    }
  } else {
    // 位置の初期化
    SetPos({0.0f, 0.0f});
  }
}

/// <summary>
/// 描画処理
/// </summary>
void Bullet::Draw() {
  if (isShoot_) {
    Novice::DrawEllipse(static_cast<int>(pos_.x), static_cast<int>(pos_.y),
                        static_cast<int>(radius_), static_cast<int>(radius_),
                        0.0f, RED, kFillModeSolid);
  }
}