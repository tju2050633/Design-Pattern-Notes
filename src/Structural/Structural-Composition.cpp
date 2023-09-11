#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 书上用的图形对象操作
// 这里实现文件树状目录

/* ********************************* */
// 声明
/* ********************************* */

class Item;
class File;
class Directory;
class FileTree;

/* ********************************* */
// 定义
/* ********************************* */

class Item
{
public:
    virtual int getSize() = 0;
    virtual string getContent() = 0;
    virtual void deleteAll() = 0;
};

class File : public Item
{
private:
    string name;
    string content;

public:
    File(string name, string content) : name(name), content(content) {}
    int getSize()
    {
        return content.size();
    }

    string getContent()
    {
        return content;
    }

    void deleteAll() {}
};

class Directory : public Item
{
private:
    string name;
    vector<Item *> children;

public:
    Directory(string name) : name(name) {}

    /* 实现Item接口 */

    int getSize()
    {
        int size = 0;
        for (auto child : children)
        {
            size += child->getSize();
        }
        return size;
    }

    string getContent()
    {
        string content = "[Dir Content] : ";
        for (auto child : children)
        {
            content += child->getContent();
            content += " // ";
        }
        return content;
    }

    /* Directory特有函数 */

    void deleteAll()
    {
        children.clear();
    }

    void add(Item *child)
    {
        children.push_back(child);
    }

    void remove(Item *child)
    {
        for (auto it = children.begin(); it != children.end(); it++)
        {
            if (*it == child)
            {
                children.erase(it);
                break;
            }
        }
    }
};

class FileTree
{
private:
    Directory *root;

public:
    FileTree(Directory *root) : root(root) {}
    int getSize()
    {
        return root->getSize();
    }

    string getContent()
    {
        return root->getContent();
    }

    void deleteAll()
    {
        root->deleteAll();
    }
};

/* ********************************* */
// 客户端
/* ********************************* */

int main()
{
    Directory *root = new Directory("root");
    Directory *dir1 = new Directory("dir1");
    Directory *dir2 = new Directory("dir2");
    File *file1 = new File("file1", "file1 content");
    File *file2 = new File("file2", "file2 content");
    File *file3 = new File("file3", "file3 content");
    File *file4 = new File("file4", "file4 content");
    File *file5 = new File("file5", "file5 content");
    File *file6 = new File("file6", "file6 content");
    dir1->add(file1);
    dir1->add(file2);
    dir2->add(file3);
    dir2->add(file4);
    root->add(dir1);
    root->add(dir2);
    root->add(file5);
    root->add(file6);

    FileTree *fileTree = new FileTree(root);
    cout << "FileTree Size: " << fileTree->getSize() << endl;
    cout << "FileTree Content: " << fileTree->getContent() << endl;
    fileTree->deleteAll();
    cout << "FileTree Size: " << fileTree->getSize() << endl;
    cout << "FileTree Content: " << fileTree->getContent() << endl;

    return 0;
}