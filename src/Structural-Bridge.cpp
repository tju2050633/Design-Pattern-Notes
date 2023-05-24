#include <iostream>
#include <string>
using namespace std;

/*
将抽象部分与实现部分分离，使它们都可以独立地变化。
*/

/* 声明 */
class Abstraction;
class RefinedAbstraction;
class Implementor;
class ConcreteImplementorA;
class ConcreteImplementorB;

/* 定义 */

class Implementor
{
public:
    virtual ~Implementor() {}
    virtual void operation() = 0;
};

class ConcreteImplementorA : public Implementor
{
public:
    void operation() override;
};

class ConcreteImplementorB : public Implementor
{
public:
    void operation() override;
};

class Abstraction
{
protected:
    Implementor *implementor;

public:
    virtual ~Abstraction() {}
    Abstraction(Implementor *implementor) : implementor(implementor) {}
    virtual void operation() = 0;
};

class RefinedAbstraction : public Abstraction
{
public:
    RefinedAbstraction(Implementor *implementor) : Abstraction(implementor) {}
    void operation() override;
};

/* 实现 */

void ConcreteImplementorA::operation()
{
    cout << "ConcreteImplementorA::operation()" << endl;
}

void ConcreteImplementorB::operation()
{
    cout << "ConcreteImplementorB::operation()" << endl;
}

void RefinedAbstraction::operation()
{
    implementor->operation();
}

// 客户端
int main()
{
    Implementor *implementorA = new ConcreteImplementorA();
    Implementor *implementorB = new ConcreteImplementorB();

    Abstraction *abstractionA = new RefinedAbstraction(implementorA);
    Abstraction *abstractionB = new RefinedAbstraction(implementorB);

    abstractionA->operation();
    abstractionB->operation();

    delete implementorA;
    delete implementorB;
    delete abstractionA;
    delete abstractionB;

    return 0;
}