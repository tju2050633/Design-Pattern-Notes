#include <iostream>
#include <string>
using namespace std;

// 梦回cocos2dx的单例导演

/* ********************************* */
// 声明
/* ********************************* */

class Director;

/* ********************************* */
// 定义
/* ********************************* */

class Director
{
private:
    static Director *instance;
    Director() {}

    // 单例模型可以保存一些全局状态
    string currentScene;

public:
    static Director *getInstance()
    {
        if (instance == nullptr)
        {
            instance = new Director();
        }
        return instance;
    }

    void setCurrentScene(string scene)
    {
        currentScene = scene;
    }

    string getCurrentScene()
    {
        return currentScene;
    }
};

// 静态成员变量要在类外初始化
Director *Director::instance = nullptr;

/* ********************************* */
// 客户端
/* ********************************* */

int main()
{
    Director *director1 = Director::getInstance();
    director1->setCurrentScene("scene1");

    Director *director2 = Director::getInstance();
    cout << director2->getCurrentScene() << endl;
    director2->setCurrentScene("scene2");
    cout << director2->getCurrentScene() << endl;

    cout << "director1 : " << director1 << endl;
    cout << "director2 : " << director2 << endl;

    return 0;
}