#include <iostream>
using namespace std;

/*
举例：要开发GUI库，需要支持多种操作系统，每种操作系统都有自己的窗口、按钮等控件，如何设计？
这里假设开发一个窗口和一个按钮，都需要支持Windows、Linux、MacOS和Browser四种情况。
*/

/* ********************************* */
// 声明
/* ********************************* */

class Dialog;
class Button;
class WindowsDialog;
class WindowsButton;
class LinuxDialog;
class LinuxButton;
class MacOSDialog;
class MacOSButton;
class BrowserDialog;
class BrowserButton;

/* ********************************* */
// 定义基类
/* ********************************* */

class Button
{
private:
    // 按钮持有它所在的对话框的引用，用于调用对话框的方法
    Dialog *dialog;
    void (Dialog::*callback)();

public:
    Button(Dialog *dialog) : dialog(dialog) {}
    virtual ~Button() {}

    // 按钮的渲染方法留给子类实现，适配4种情况
    virtual void render() = 0;

    void addListener(void (Dialog::*callback)())
    {
        this->callback = callback;
    }

    // 按钮的点击事件是通用的，即调用Dialog的某个方法
    void onClick()
    {
        (dialog->*callback)();
    }
};

class Dialog
{
public:
    virtual ~Dialog() {}

    // Dialog算是工厂类，但并不只负责创建Button，还负责Button的渲染和事件绑定等其他业务逻辑
    // 就像软件公司由程序员培训部门，但主要工作还是开发软件而不是生产程序员
    // 这里返回Button是为了方便客户端调用，实际上Dialog并不需要返回Button
    Button *render()
    {
        Button *okButton = createButton(this);
        // 注意这个函数指针的写法，&表示传进去的是函数的地址，::解析函数的作用域
        okButton->addListener(&Dialog::closeDialog);
        okButton->render();

        return okButton;
    }

    void closeDialog()
    {
        cout << "close dialog" << endl;
    }

    // 工厂方法，由子类实现，适配4种情况
    virtual Button *createButton(Dialog *dialog) = 0;
};

/* ********************************* */
// 定义按钮子类，为4种情况分别定义渲染方法
/* ********************************* */

class WindowsButton : public Button
{
public:
    // 要调用父类的构造函数，否则编译报错
    WindowsButton(Dialog *dialog) : Button(dialog) {}

    void render()
    {
        cout << "render windows button" << endl;
    }
};

class LinuxButton : public Button
{
public:
    LinuxButton(Dialog *dialog) : Button(dialog) {}

    void render()
    {
        cout << "render Linux button" << endl;
    }
};

class MacOSButton : public Button
{
public:
    MacOSButton(Dialog *dialog) : Button(dialog) {}

    void render()
    {
        cout << "render MacOS button" << endl;
    }
};

class BrowserButton : public Button
{
public:
    BrowserButton(Dialog *dialog) : Button(dialog) {}

    void render()
    {
        cout << "render Browser button" << endl;
    }
};

/* ********************************* */
// 定义对话框子类，为4种情况分别定义创建按钮方法
/* ********************************* */

class WindowsDialog : public Dialog
{
public:
    Button *createButton(Dialog *dialog)
    {
        return new WindowsButton(dialog);
    }
};

class LinuxDialog : public Dialog
{
public:
    Button *createButton(Dialog *dialog)
    {
        return new LinuxButton(dialog);
    }
};

class MacOSDialog : public Dialog
{
public:
    Button *createButton(Dialog *dialog)
    {
        return new MacOSButton(dialog);
    }
};

class BrowserDialog : public Dialog
{
public:
    Button *createButton(Dialog *dialog)
    {
        return new BrowserButton(dialog);
    }
};

/* ********************************* */
// 客户端
/* ********************************* */

int main()
{
    // 客户端只需要关心Dialog和Button的接口
    // 具体要创建哪种类型，通过子类实现
    // 如果需要添加新的情况，只需要编写新的Dialog和Button的子类，不需要修改其他地方的代码

    // Windows
    Dialog *windowsDialog = new WindowsDialog();
    Button *windowsButton = windowsDialog->render();
    windowsButton->onClick();

    delete windowsDialog;
    delete windowsButton;

    // Linux
    Dialog *linuxDialog = new LinuxDialog();
    Button *linuxButton = linuxDialog->render();
    linuxButton->onClick();

    delete linuxDialog;
    delete linuxButton;

    // MacOS
    Dialog *macOSDialog = new MacOSDialog();
    Button *macOSButton = macOSDialog->render();
    macOSButton->onClick();

    delete macOSDialog;
    delete macOSButton;

    // Browser
    Dialog *browserDialog = new BrowserDialog();
    Button *browserButton = browserDialog->render();
    browserButton->onClick();

    delete browserDialog;
    delete browserButton;

    return 0;
}