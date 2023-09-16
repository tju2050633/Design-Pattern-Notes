#include <iostream>
#include <string>
using namespace std;

// 书上的GUI元素显示上下文信息案例

/* ********************************* */
// 声明
/* ********************************* */

class ComponentWithContextualHelp;
class Component;
class Button;
class Panel;
class Dialog;

/* ********************************* */
// 定义
/* ********************************* */

// 接口
class ComponentWithContextualHelp {
  public:
    virtual ComponentWithContextualHelp *setNext(ComponentWithContextualHelp *next) = 0;
    virtual void showHelp() = 0;
};

// 抽象组件
class Component : public ComponentWithContextualHelp {
  private:
    ComponentWithContextualHelp *next;

  public:
    ComponentWithContextualHelp *setNext(ComponentWithContextualHelp *next) {
        this->next = next;
        return next;
    }

    virtual void showHelp() {
        if (next != nullptr) {
            next->showHelp();
        } else {
            cout << "Component : No help available" << endl;
        }
    }
};

// 简单组件对默认实现不重写

class Button : public Component {
  private:
    string helpText;

  public:
    void setHelpText(string text) { helpText = text; }

    virtual void showHelp() {
        if (helpText != "") {
            cout << "Button : " << helpText << endl;
        } else {
            Component::showHelp();
        }
    }
};

// 复杂组件对默认实现重写

class Panel : public Component {
  private:
    string modalHelpText;

  public:
    void setModalHelpText(string text) { modalHelpText = text; }

    virtual void showHelp() {
        if (modalHelpText != "") {
            cout << "Panel : " << modalHelpText << endl;
        } else {
            Component::showHelp();
        }
    }
};

class Dialog : public Component {
  private:
    string wikiPageURL;

  public:
    void setWikiPageURL(string url) { wikiPageURL = url; }

    virtual void showHelp() {
        if (wikiPageURL != "") {
            cout << "Dialog : " << wikiPageURL << endl;
        } else {
            Component::showHelp();
        }
    }
};

int main() {

    Panel *panel = new Panel();
    // panel->setModalHelpText("Panel Modal Help Text");
    panel->setModalHelpText("");

    Dialog *dialog = new Dialog();
    // dialog->setWikiPageURL("Dialog Wiki Page URL");
    dialog->setWikiPageURL("");

    Button *button = new Button();
    // button->setHelpText("Button Help Text");
    button->setHelpText("");

    button->setNext(dialog)->setNext(panel);
    button->showHelp();

    delete panel;
    delete dialog;
    delete button;

    return 0;
}