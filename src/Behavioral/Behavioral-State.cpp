#include <iostream>
#include <string>
using namespace std;

/*
一个环境Context有着多种状态，每种状态下环境的行为不同。
Context每个时刻只能有一种状态。
状态之间的转移构成了一个状态机。
*/

/* 声明 */
class State;
class ConcreteStateA;
class ConcreteStateB;
class Context;

/* 定义 */

// 状态
class State
{
public:
    virtual ~State() {}
    virtual void handle(Context *context) = 0;
};

class ConcreteStateA : public State
{
private:
    static State *instance;
    ConcreteStateA() {}

public:
    static State *getInstance();
    void handle(Context *context);
};

class ConcreteStateB : public State
{
private:
    static State *instance;
    ConcreteStateB() {}

public:
    static State *getInstance();
    void handle(Context *context);
};

// 环境
class Context
{
protected:
    State *state;

public:
    Context(State *state) { this->state = state; }
    ~Context() { delete state; }

    void setState(State *state) { this->state = state; }
    void request() { state->handle(this); }
};

/* 实现 */

// 状态
State *ConcreteStateA::instance = new ConcreteStateA();
State *ConcreteStateB::instance = new ConcreteStateB();

State *ConcreteStateA::getInstance()
{
    if (instance == nullptr)
        instance = new ConcreteStateA();

    return instance;
}

State *ConcreteStateB::getInstance()
{
    if (instance == nullptr)
        instance = new ConcreteStateB();

    return instance;
}

// 构成状态机的状态转移
void ConcreteStateA::handle(Context *context)
{
    cout << "ConcreteStateA::handle()" << endl;
    context->setState(ConcreteStateB::getInstance());
}

void ConcreteStateB::handle(Context *context)
{
    cout << "ConcreteStateB::handle()" << endl;
    context->setState(ConcreteStateA::getInstance());
}

int main()
{
    Context *context = new Context(ConcreteStateA::getInstance());
    // 状态转移
    context->request();
    context->request();
    context->request();

    delete context;

    return 0;
}