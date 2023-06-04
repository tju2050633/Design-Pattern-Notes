#include <iostream>
#include <string>
#include <map>
using namespace std;

// 书上的伪代码实现的是一个Shape类，然后有Circle和Square两个子类
// 这里按第二张类图实现，即按钮的注册表

/* ********************************* */
// 声明
/* ********************************* */

class Prototype;
class PrototypeRegistry;
class Button;

/* ********************************* */
// 定义
/* ********************************* */

class Prototype
{
public:
    virtual ~Prototype() {}
    virtual Prototype *clone() = 0;
    virtual string getColor() = 0;
};

class Button : public Prototype
{
private:
    int x;
    int y;
    string color;

public:
    Button(int x, int y, string color) : x(x), y(y), color(color) {}
    virtual ~Button() {}

    string getColor() { return color; }

    Prototype *clone()
    {
        // clone方法里负责复制每个属性
        Button *button = new Button(x, y, color);
        return button;
    }
};

class PrototypeRegistry
{
private:
    static map<string, Prototype *> registry;

public:
    static void addPrototype(string id, Prototype *prototype)
    {
        registry[id] = prototype;
    }

    static Prototype *getById(string id)
    {
        return registry[id]->clone();
    }

    static Prototype *getByColor(string color)
    {
        for (auto &item : registry)
        {
            if (item.second->getColor() == color)
            {
                return item.second->clone();
            }
        }
        return nullptr;
    }
};

// 静态成员变量需要在类外初始化
// 否则报链接错误
map<string, Prototype *> PrototypeRegistry::registry;

/* ********************************* */
// 客户端
/* ********************************* */

int main()
{
    // 原型
    Button *button_prototype_red = new Button(0, 0, "red");
    Button *button_prototype_blue = new Button(0, 0, "blue");
    Button *button_prototype_yellow = new Button(0, 0, "yellow");

    // 加入注册表
    PrototypeRegistry::addPrototype("error", button_prototype_red);
    PrototypeRegistry::addPrototype("ok", button_prototype_blue);
    PrototypeRegistry::addPrototype("warning", button_prototype_yellow);

    // 克隆
    // 这里的clone是深拷贝，即复制了每个属性
    // 需要强转为Button类型
    Button *error_button = (Button *)PrototypeRegistry::getById("error");
    Button *ok_button = (Button *)PrototypeRegistry::getById("ok");
    Button *warning_button = (Button *)PrototypeRegistry::getById("warning");

    cout << error_button->getColor() << endl;
    cout << ok_button->getColor() << endl;
    cout << warning_button->getColor() << endl;

    return 0;
}