#include "Player.h"
#include<Novice.h>

/// <summary>
/// コンストラクタ
/// </summary>
Player::Player() {
  pos_ = {200.0f, 360.0f};
  speed_ = 8.0f;
  radius_ = 32.0f;
  isAlive_ = true;
  respawnTimer_ = 60;

  bullet_ = new Bullet();
}

/// <summary>
/// デストラクタ
/// </summary>
Player::~Player() { delete bullet_; }

/// <summary>
/// 更新処理
/// </summary>
/// <param name="keys"></param>
void Player::Update(const char *keys, const char *preKeys) {
  if (keys == nullptr) {
    return;
  }

  if (isAlive_) {
      //移動処理
    if (keys[DIK_D]) {
      pos_.x += speed_;
    }
    if (keys[DIK_A]) {
      pos_.x -= speed_;
    }
    if (keys[DIK_S]) {
      pos_.y += speed_;
    }
    if (keys[DIK_W]) {
      pos_.y -= speed_;
    }

    //画面端で座標を固定
    if (pos_.x + radius_ >= 1280.0f) {
      pos_.x = 1280.0f - radius_;
    }
    if (pos_.x - radius_ <= 0.0f) {
      pos_.x = radius_;
    }
    if (pos_.y + radius_ >= 720.0f) {
      pos_.y = 720.0f - radius_;
    }
    if (pos_.y - radius_ <= 0.0f) {
      pos_.y = radius_;
    }

    if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
      if (!bullet_->GetShoot()) {
        bullet_->SetShoot(true);
        bullet_->SetPos(GetPos());
      }
    }

    bullet_->Update();
  } else {
    respawnTimer_--;

    if (respawnTimer_ <= 0) {
      isAlive_ = true;
      respawnTimer_ = 60;
      SetPos({200.0f, 360.0f});
    }
  }

}

/// <summary>
/// 描画処理
/// </summary>
void Player::Draw() {

  bullet_->Draw();

  if (isAlive_) {
    Novice::DrawEllipse(static_cast<int>(pos_.x), static_cast<int>(pos_.y),
                        static_cast<int>(radius_), static_cast<int>(radius_),
                        0.0f, WHITE, kFillModeSolid);
  }
}