#include <iostream>
#include <string>
using namespace std;

/*
举例：还是开发GUI库，支持Win和Mac两个OS。
有两种控件：Button和CheckBox。
*/

/* ********************************* */
// 声明
/* ********************************* */

class GUIFactory;
class WinFactory;
class MacFactory;

class Button;
class Checkbox;
class WinButton;
class MacButton;
class WinCheckbox;
class MacCheckbox;

/* ********************************* */
// 定义接口
/* ********************************* */

class Button
{
public:
    virtual ~Button() {}
    virtual void paint() = 0;
};

class Checkbox
{
public:
    virtual ~Checkbox() {}
    virtual void paint() = 0;
};

class GUIFactory
{
public:
    virtual ~GUIFactory() {}

    virtual Button *createButton() = 0;
    virtual Checkbox *createCheckbox() = 0;
};

/* ********************************* */
// 定义按钮子类
/* ********************************* */

class WinButton : public Button
{
public:
    void paint()
    {
        cout << "render Windows Button" << endl;
    }
};

class MacButton : public Button
{
public:
    void paint()
    {
        cout << "render MacOS Button" << endl;
    }
};

/* ********************************* */
// 定义多选框子类
/* ********************************* */

class WinCheckbox : public Checkbox
{
public:
    void paint()
    {
        cout << "render Windows Checkbox" << endl;
    }
};

class MacCheckbox : public Checkbox
{
public:
    void paint()
    {
        cout << "render MacOS Checkbox" << endl;
    }
};


/* ********************************* */
// 定义工厂子类
/* ********************************* */

class WinFactory : public GUIFactory
{
public:
    Button *createButton()
    {
        return new WinButton();
    }
    Checkbox *createCheckbox()
    {
        return new WinCheckbox();
    }
};

class MacFactory : public GUIFactory
{
public:
    Button *createButton()
    {
        return new MacButton();
    }
    Checkbox *createCheckbox()
    {
        return new MacCheckbox();
    }
};

/* ********************************* */
// 客户端
/* ********************************* */

// 客户端只需要知道GUIFactory接口，不需要知道具体的工厂子类
// 即Application整个类里没有出现Win、Mac等字样

class Application
{
private:
    GUIFactory *factory;
    Button *button;
    Checkbox *checkbox;

public:
    Application(GUIFactory *factory) : factory(factory) {}
    ~Application()
    {
        if(button)
            delete button;
        if(checkbox)
            delete checkbox;
    }

    void createUI()
    {
        button = factory->createButton();
        checkbox = factory->createCheckbox();
    }

    void paint()
    {
        button->paint();
        checkbox->paint();
    }
};

int main()
{
    string config = "Win"; // 这里应该是从配置文件读取，config = readConfig();

    GUIFactory *factory;
    if(config == "Win")
        factory = new WinFactory();
    else if(config == "Mac")
        factory = new MacFactory();
    else
        return -1;

    // 整个Application运行过程中，不需要知道Win、Mac等具体类型
    // Application初始化中就已经决定使用哪种系列的产品

    Application *app = new Application(factory);
    app->createUI();
    app->paint();

    delete app;

    return 0;
}