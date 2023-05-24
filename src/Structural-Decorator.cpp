#include <iostream>
#include <string>
using namespace std;

/* 声明 */
class Component;
class ConcreteComponent;
class Decorator;
class ConcreteDecoratorA;
class ConcreteDecoratorB;

/* 定义 */

// 构件类，具有operation方法
class Component
{
public:
    virtual ~Component() {}
    virtual void operation() = 0;
};

class ConcreteComponent : public Component
{
public:
    void operation() override;
};

// 装饰器类，继承自Component，具有Component的operation方法
// 通过组合的方式，将Component的operation方法包装成新的方法
class Decorator : public Component
{
private:
    Component *component;

public:
    virtual ~Decorator() {}
    Decorator(Component *component) : component(component) {}
    void operation() override;
};

class ConcreteDecoratorA : public Decorator
{
public:
    ConcreteDecoratorA(Component *component) : Decorator(component) {}
    void operation() override;
};

class ConcreteDecoratorB : public Decorator
{
public:
    ConcreteDecoratorB(Component *component) : Decorator(component) {}
    void operation() override;
};

/* 实现 */

void ConcreteComponent::operation()
{
    cout << "ConcreteComponent::operation()" << endl;
}

void Decorator::operation()
{
    component->operation();
}

void ConcreteDecoratorA::operation()
{
    Decorator::operation();                            // 构件的方法
    cout << "ConcreteDecoratorA::operation()" << endl; // 自身的方法
}

void ConcreteDecoratorB::operation()
{
    Decorator::operation();
    cout << "ConcreteDecoratorB::operation()" << endl;
}

int main()
{
    Component *component = new ConcreteComponent();
    Decorator *decoratorA = new ConcreteDecoratorA(component);
    Decorator *decoratorB = new ConcreteDecoratorB(decoratorA);
    decoratorB->operation();

    delete decoratorB;
    delete decoratorA;
    delete component;

    return 0;
}