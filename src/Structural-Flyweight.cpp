#include <iostream>
#include <string>
#include <map>
using namespace std;

/* 声明 */
class Flyweight;
class ConcreteFlyweight;
class FlyweightFactory;

/* 定义 */
class Flyweight
{
public:
    virtual void Operation() = 0;
};

class ConcreteFlyweight : public Flyweight
{
private:
    string intrinsicState;

public:
    ConcreteFlyweight(string intrinsicState);
    ~ConcreteFlyweight();
    void Operation();
};

class FlyweightFactory
{
private:
    map<string, Flyweight *> flyweights;

public:
    FlyweightFactory();
    ~FlyweightFactory();
    Flyweight *GetFlyweight(string key);
};

/* 实现 */
ConcreteFlyweight::ConcreteFlyweight(string intrinsicState)
{
    this->intrinsicState = intrinsicState;
}

ConcreteFlyweight::~ConcreteFlyweight()
{
}

void ConcreteFlyweight::Operation()
{
    cout << "ConcreteFlyweight::Operation(): " << intrinsicState << endl;
}

FlyweightFactory::FlyweightFactory()
{
}

FlyweightFactory::~FlyweightFactory()
{
}

Flyweight *FlyweightFactory::GetFlyweight(string key)
{
    if (flyweights.find(key) != flyweights.end())
    {
        cout << "FlyweightFactory::GetFlyweight(): " << key << " already exists" << endl;
        return flyweights[key];
    }
    else
    {
        Flyweight *fw = new ConcreteFlyweight(key);
        flyweights[key] = fw;
        return fw;
    }
}

// 客户端
int main()
{
    FlyweightFactory *fwf = new FlyweightFactory();
    Flyweight *fw1 = fwf->GetFlyweight("A");
    Flyweight *fw2 = fwf->GetFlyweight("B");
    Flyweight *fw3 = fwf->GetFlyweight("A");
    fw1->Operation();
    fw2->Operation();
    fw3->Operation();

    delete fwf;

    return 0;
}