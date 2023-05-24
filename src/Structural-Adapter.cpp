#include <iostream>
#include <string>
using namespace std;

/* 声明 */
class Adapter;
class AdapterA;
class AdapterB;
class AdapteeA;
class AdapteeB;

/* 定义 */

// 适配者，具有不同方法接口
class AdapteeA
{
public:
    void specificRequestA();
};

class AdapteeB
{
public:
    void specificRequestB();
};

// 适配器，继承自Adapter，实现了request方法
// 不同适配器的request调用对应适配者的不同方法接口
class Adapter
{
public:
    virtual ~Adapter() {}
    virtual void request() = 0;
};

class AdapterA : public Adapter
{
private:
    AdapteeA *adaptee;

public:
    AdapterA(AdapteeA *adaptee) : adaptee(adaptee) {}
    void request() override;
};

class AdapterB : public Adapter
{
private:
    AdapteeB *adaptee;

public:
    AdapterB(AdapteeB *adaptee) : adaptee(adaptee) {}
    void request() override;
};

/* 实现 */

void AdapteeA::specificRequestA()
{
    cout << "AdapteeA::specificRequest()" << endl;
}

void AdapteeB::specificRequestB()
{
    cout << "AdapteeB::specificRequest()" << endl;
}

void AdapterA::request()
{
    adaptee->specificRequestA();
}

void AdapterB::request()
{
    adaptee->specificRequestB();
}

int main()
{
    AdapteeA *adapteeA = new AdapteeA();
    AdapteeB *adapteeB = new AdapteeB();
    Adapter *adapterA = new AdapterA(adapteeA);
    Adapter *adapterB = new AdapterB(adapteeB);

    // 客户端无需知道适配者的具体方法接口
    adapterA->request();
    adapterB->request();

    delete adapteeA;
    delete adapteeB;
    delete adapterA;
    delete adapterB;

    return 0;
}