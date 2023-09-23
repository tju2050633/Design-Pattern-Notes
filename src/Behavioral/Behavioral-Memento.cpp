#include <iostream>
#include <string>
using namespace std;

/* ********************************* */
// 声明
/* ********************************* */

class Editor;
class Snapshot;

/* ********************************* */
// 定义
/* ********************************* */
class Editor {
  private:
    string text;
    int curX, curY;

  public:
    string getText() { return text; }
    void setText(string text) { this->text = text; }

    int getCursorX() { return curX; }
    int getCursorY() { return curY; }
    void setCursor(int x, int y) {
        this->curX = x;
        this->curY = y;
    }

    Snapshot createSnapshot();
};

class Snapshot {
  private:
    Editor *editor;
    string text;
    int curX, curY;

  public:
    Snapshot(Editor *editor, string text, int curX, int curY) {
        this->editor = editor;
        this->text = text;
        this->curX = curX;
        this->curY = curY;
    }

    void restore() {
        editor->setText(text);
        editor->setCursor(curX, curY);
    }
};

Snapshot Editor::createSnapshot(){ return Snapshot(this, text, curX, curY); }

int main() {
    Editor editor;
    editor.setText("Hello, world!\n");
    Snapshot snapshot = editor.createSnapshot();

    editor.setText("This is a test.\n");
    snapshot.restore();
    cout << editor.getText();

    return 0;
}