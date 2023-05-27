#include <iostream>
#include <string>
using namespace std;

/*
子系统有不同接口，用一个外观类包装
*/

/* 声明 */
class SystemA;
class SystemB;
class SystemC;
class Facade;

/* 定义 */
class SystemA
{
public:
    void OperationA();
};

class SystemB
{
public:
    void OperationB();
};

class SystemC
{
public:
    void OperationC();
};

class Facade
{
private:
    SystemA *sysA;
    SystemB *sysB;
    SystemC *sysC;

public:
    Facade();
    ~Facade();
    void OperationWrapper();
};

/* 实现 */

void SystemA::OperationA()
{
    cout << "SystemA::OperationA()" << endl;
}

void SystemB::OperationB()
{
    cout << "SystemB::OperationB()" << endl;
}

void SystemC::OperationC()
{
    cout << "SystemC::OperationC()" << endl;
}

Facade::Facade()
{
    sysA = new SystemA();
    sysB = new SystemB();
    sysC = new SystemC();
}

Facade::~Facade()
{
    delete sysA;
    delete sysB;
    delete sysC;
}

void Facade::OperationWrapper()
{
    sysA->OperationA();
    sysB->OperationB();
    sysC->OperationC();
}

// 客户端
int main()
{
    Facade *facade = new Facade();
    facade->OperationWrapper();

    delete facade;

    return 0;
}