#include <iostream>
#include <string>
#include <vector>
using namespace std;

/* ********************************* */
// 声明
/* ********************************* */

class Command;
class CopyCommand;
class CutCommand;
class PasteCommand;
class UndoCommand;
class Application;
class Editor; // Reciever

class CommandHistory;

/* ********************************* */
// 定义
/* ********************************* */

// 历史记录

class CommandHistory {
  private:
    vector<Command *> history;

  public:
    void push(Command *command) { history.push_back(command); }
    Command *pop() {
        Command *command = history.back();
        history.pop_back();
        return command;
    }
};

// 编辑器

class Editor {
    string text;

  public:
    void setText(string text) { this->text = text; }
    string getText() { return text; }

    string getSelection() {
        cout << "Editor : getSelection" << endl;
        return " selected text ";
    }

    void deleteSelection() { cout << "Editor : deleteSelection" << endl; }

    void replaceSelection(string text) { cout << "Editor : replaceSelection. text : " << text << endl; }
};

// 命令接口
class Command {
  protected:
    Application application;
    Editor editor;
    string backup; // 备份编辑器的文本

  public:
    Command(Application application, Editor editor) {
        this->application = application;
        this->editor = editor;
    }
    virtual bool execute() = 0;

    void saveBackup() {
        cout << "Command : saveBackup" << endl;
        backup = editor.getText();
    }

    void undo() {
        cout << "Command : undo" << endl;
        editor.setText(backup);
    }
};

// 具体命令

class CopyCommand : public Command {
  public:
    CopyCommand(Application application, Editor editor) : Command(application, editor) {}
    bool execute() override {
        cout << "CopyCommand : execute" << endl;
        application.setClipboard(editor.getSelection());

        return false; // 不记录
    }
};

class CutCommand : public Command {
  public:
    CutCommand(Application application, Editor editor) : Command(application, editor) {}
    bool execute() override {
        cout << "CutCommand : execute" << endl;
        application.setClipboard(editor.getSelection());
        editor.deleteSelection();

        return true; // 记录
    }
};

class PasteCommand : public Command {
  public:
    PasteCommand(Application application, Editor editor) : Command(application, editor) {}
    bool execute() override {
        cout << "PasteCommand : execute" << endl;
        editor.replaceSelection(application.getClipboard());

        return true; // 记录
    }
};

class UndoCommand : public Command {
  private:
    CommandHistory *history;

  public:
    UndoCommand(Application application, Editor editor, CommandHistory *history) : Command(application, editor) {
        this->history = history;
    }
    bool execute() override {
        cout << "UndoCommand : execute" << endl;
        application.undo();

        return false; // 不记录
    }
};

// 应用程序

class Application {
  private:
    string clipboard;
    Editor *editor;
    CommandHistory *history;

  public:
    void setClipboard(string text) { this->clipboard = text; }
    string getClipboard() { return clipboard; }

    void executeCommand(Command *command) {
        if (command->execute()) {
            history->push(command);
        }
    }

    void undo() {
        Command *command = history->pop();
        if (command != nullptr) {
            command->undo();
        }
    }

    void createUI() {
        editor = new Editor();
        history = new CommandHistory();

        editor->setText("1234567890");

        // 创建按钮组件，并指定点击事件为执行命令
    }
};

int main() { return 0; }