#include <iostream>
#include <string>
#include <map>
using namespace std;

// 书上的伪代码实现的是一个Shape类，然后有Circle和Square两个子类
// 这里按第二张类图实现，即按钮的注册表

/* ********************************* */
// 声明
/* ********************************* */

class Clonable;
class ButtonRegistry;
class Button;
class RectangleButton;
class RoundButton;

/* ********************************* */
// 定义可克隆接口
/* ********************************* */

class Clonable
{
public:
    virtual ~Clonable() {}
    virtual Clonable *clone() = 0;
};

/* ********************************* */
// 定义按钮继承体系
/* ********************************* */

class Button : public Clonable
{
private:
    int x;
    int y;
    string color;

public:
    Button(int x, int y, string color) : x(x), y(y), color(color) {}
    Button(const Button &button)
    {
        // 支持克隆的类要定义拷贝构造函数
        this->x = button.x;
        this->y = button.y;
        this->color = button.color;
    }
    virtual ~Button() {}

    string getColor() { return color; }

    Button *clone()
    {
        // clone方法里负责复制每个属性
        return new Button(*this);
    }
};

class RectangleButton : public Button
{
private:
    int width;
    int height;

public:
    RectangleButton(int x, int y, string color, int width, int height) : Button(x, y, color)
    {
        this->width = width;
        this->height = height;
    }

    RectangleButton(const RectangleButton &button) : Button(button)
    {
        this->width = button.width;
        this->height = button.height;
    }

    RectangleButton *clone()
    {
        return new RectangleButton(*this);
    }
};

class RoundButton : public Button
{
private:
    int radius;

public:
    RoundButton(int x, int y, string color, int radius) : Button(x, y, color)
    {
        this->radius = radius;
    }

    RoundButton(const RoundButton &button) : Button(button)
    {
        this->radius = button.radius;
    }

    RoundButton *clone()
    {
        return new RoundButton(*this);
    }
};

/* ********************************* */
// 定义按钮注册表
/* ********************************* */

class ButtonRegistry
{
private:
    static map<string, Button *> registry;

public:
    static void addPrototype(string id, Button *prototype)
    {
        registry[id] = prototype;
    }

    static Button *getById(string id)
    {
        return registry[id]->clone();
    }

    static Button *getByColor(string color)
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
map<string, Button *> ButtonRegistry::registry;

/* ********************************* */
// 客户端
/* ********************************* */

int main()
{
    // 原型
    RectangleButton *button_prototype_rec_red = new RectangleButton(0, 0, "red", 100, 50);
    RectangleButton *button_prototype_rec_green = new RectangleButton(0, 0, "green", 100, 50);
    RoundButton *button_prototype_round_blue = new RoundButton(0, 0, "blue", 50);
    RoundButton *button_prototype_round_yellow = new RoundButton(0, 0, "yellow", 50);

    // 加入注册表
    ButtonRegistry::addPrototype("error", button_prototype_rec_red);
    ButtonRegistry::addPrototype("ok", button_prototype_rec_green);
    ButtonRegistry::addPrototype("info", button_prototype_round_blue);
    ButtonRegistry::addPrototype("warning", button_prototype_round_yellow);

    // 克隆：此处不需要知道类RectangleButton和RoundButton的存在
    // 这里的clone是深拷贝，即复制了每个属性
    // 需要强转为Button类型
    Button *error_button = ButtonRegistry::getById("error");
    Button *ok_button = ButtonRegistry::getById("ok");
    Button *warning_button = ButtonRegistry::getById("warning");
    Button *info_button = ButtonRegistry::getById("info");

    cout << error_button->getColor() << endl;
    cout << ok_button->getColor() << endl;
    cout << warning_button->getColor() << endl;
    cout << info_button->getColor() << endl;

    return 0;
}