#include <iostream>
#include <string>
using namespace std;

/* 声明 */

class Singleton;

/* 定义 */

class Singleton
{
private:
    static Singleton *instance;
    string name;

    // 构造函数要私有，不允许外部创建实例
    Singleton();
    ~Singleton();

public:
    static Singleton *getInstance();
    void setName(string name);
    string getName();
};

/* 实现 */

// 静态成员变量必须在类外初始化
Singleton *Singleton::instance = NULL;

Singleton::Singleton()
{
}

Singleton::~Singleton()
{
    if (instance != NULL)
    {
        delete instance;
    }
}

Singleton *Singleton::getInstance()
{
    if (instance == NULL)
    {
        instance = new Singleton();
    }
    return instance;
}

void Singleton::setName(string name)
{
    this->name = name;
}

string Singleton::getName()
{
    return this->name;
}

int main()
{
    Singleton *singleton1 = Singleton::getInstance();
    Singleton *singleton2 = Singleton::getInstance();
    singleton1->setName("Singleton");
    cout << singleton1->getName() << endl;
    cout << singleton2->getName() << endl;

    cout << singleton1 << endl;
    cout << singleton2 << endl;

    return 0;
}