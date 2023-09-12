/*
 * @Author: Jialin Lu
 * @GitHub: https://github.com/tju2050633
 * @Date: 2023-05-27 10:14:51
 * @FilePath: /DesignPattern/src/Structural/Structural-Flyweight.cpp
 * @Description:
 *
 * Copyright (c) 2023 by 1640889387@qq.com, All Rights Reserved.
 */
#include <iostream>
#include <string>
#include <map>
using namespace std;

// 实现游戏子弹的案例
// cocos2d-x中的精灵类Sprite就是使用了享元模式

/* ********************************* */
// 声明
/* ********************************* */
class BulletSprite;
class Bullet;
class BulletFactory;

/* ********************************* */
// 定义
/* ********************************* */

// 子弹精灵类
class BulletSprite {
  private:
    string name;
    string texture;
    int width;
    int height;

  public:
    BulletSprite(string name, string texture, int width, int height) {
        this->name = name;
        this->texture = texture;
        this->width = width;
        this->height = height;
    }
    BulletSprite(BulletSprite *bulletSprite) {
        this->name = bulletSprite->name;
        this->texture = bulletSprite->texture;
        this->width = bulletSprite->width;
        this->height = bulletSprite->height;
    }
    void Draw() { cout << "Draw BulletSprite" << endl; }
};

// 子弹类
class Bullet {
  private:
    BulletSprite *bulletSprite; // 采用组合而非继承
    int x;
    int y;

  public:
    Bullet(BulletSprite *bulletSprite) { this->bulletSprite = bulletSprite; }
    void SetPosition(int x, int y) {
        this->x = x;
        this->y = y;
    }
    void Draw() {
        bulletSprite->Draw();
        cout << "Draw Bullet" << endl;
    }
};

// 子弹工厂类
class BulletFactory {
  private:
    BulletSprite *bulletSprite;
    map<string, BulletSprite *> bulletSpriteMap;

  public:
    ~BulletFactory() {
        for (auto it = bulletSpriteMap.begin(); it != bulletSpriteMap.end(); it++) {
            delete it->second;
        }
    }

    void setBulletSprite(BulletSprite *bulletSprite) { this->bulletSprite = bulletSprite; }

    Bullet *GetBullet(string name) {
        BulletSprite *bulletSprite = bulletSpriteMap[name];
        if (bulletSprite == nullptr) {
            bulletSprite = new BulletSprite(this->bulletSprite);
            bulletSpriteMap[name] = bulletSprite;
        }
        Bullet *bullet = new Bullet(bulletSprite);
        return bullet;
    }

    void Draw() {
        for (auto it = bulletSpriteMap.begin(); it != bulletSpriteMap.end(); it++) {
            cout << it->first << endl;
            it->second->Draw();
        }
    }
};

// 客户端
int main() {
    BulletFactory *bulletFactory = new BulletFactory();
    BulletSprite *bulletSprite = new BulletSprite("bullet sprite", "bullet.png", 10, 10);
    bulletFactory->setBulletSprite(bulletSprite);
    Bullet *bullet1 = bulletFactory->GetBullet("bullet1");
    Bullet *bullet2 = bulletFactory->GetBullet("bullet2");
    Bullet *bullet3 = bulletFactory->GetBullet("bullet3");

    bulletFactory->Draw();

    delete bulletFactory;
    delete bulletSprite;
    return 0;
}