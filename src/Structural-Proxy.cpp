#include <iostream>
#include <string>
using namespace std;

/* 声明 */
class Subject;
class RealSubject;
class Proxy;

/* 定义 */
class Subject
{
public:
    virtual void Request() = 0;
};

class RealSubject : public Subject
{
public:
    void Request() override;
};

class Proxy : public Subject
{
private:
    RealSubject *realSubject;
    void PreRequest();
    void PostRequest();

public:
    Proxy(RealSubject *realSubject);
    void Request() override;
};

/* 实现 */
void RealSubject::Request()
{
    cout << "RealSubject::Request()" << endl;
}

Proxy::Proxy(RealSubject *realSubject)
{
    PreRequest();
    this->realSubject = realSubject;
    PostRequest();
}

void Proxy::PreRequest()
{
    cout << "Proxy::PreRequest()" << endl;
}

void Proxy::PostRequest()
{
    cout << "Proxy::PostRequest()" << endl;
}

// 客户端
int main()
{
    // 这里客户端创建了subject然后指定给proxy
    // 相比于在proxy的ctor中new一个subject，这样可以更灵活地指定subject对象
    RealSubject *realSubject = new RealSubject();
    Proxy *proxy = new Proxy(realSubject);
    proxy->Request();

    delete realSubject;
    delete proxy;

    return 0;
}