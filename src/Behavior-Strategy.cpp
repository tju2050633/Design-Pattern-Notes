#include <iostream>
#include <string>
using namespace std;

/* 声明 */
class Context;
class Strategy;
class StrategyA;
class StrategyB;

/* 定义 */

// 策略
class Strategy
{
public:
    virtual ~Strategy() {}
    virtual void algorithm() = 0;
};

class StrategyA : public Strategy
{
public:
    void algorithm() { cout << "StrategyA" << endl; }
};

class StrategyB : public Strategy
{
public:
    void algorithm() { cout << "StrategyB" << endl; }
};

// 环境
class Context
{
private:
    Strategy *strategy;

public:
    void setStrategy(Strategy *strategy) { this->strategy = strategy; }
    void algorithm() { strategy->algorithm(); }
};

/* 实现 */

int main()
{
    Context *context = new Context();
    Strategy *strategyA = new StrategyA();
    Strategy *strategyB = new StrategyB();

    context->setStrategy(strategyA);
    context->algorithm();

    context->setStrategy(strategyB);
    context->algorithm();

    delete context;
    delete strategyA;
    delete strategyB;

    return 0;
}