#include <iostream>
using namespace std;

/* 声明 */

class Prototype;
class ConcretePrototype;
class ConcretePrototypeSub;

/* 定义 */

class Prototype
{
public:
    virtual ~Prototype() {}
    virtual Prototype *clone() = 0;
    virtual void use() = 0;
};

class ConcretePrototype : public Prototype
{
protected:
    string name;

public:
    ConcretePrototype(string name);
    ConcretePrototype(const ConcretePrototype &prototype);
    Prototype *clone();
    void use();
};

class ConcretePrototypeSub : public ConcretePrototype
{
protected:
    int age;

public:
    ConcretePrototypeSub(string name, int age);
    ConcretePrototypeSub(const ConcretePrototypeSub &prototype);
    Prototype *clone();
    void use();
};

/* 实现 */

ConcretePrototype::ConcretePrototype(string name)
{
    this->name = name;
}

ConcretePrototype::ConcretePrototype(const ConcretePrototype &prototype)
{
    // 同类型的对象可以访问对方的私有成员
    // 因此实现深拷贝
    this->name = prototype.name;
}

Prototype *ConcretePrototype::clone()
{
    return new ConcretePrototype(*this);
}

void ConcretePrototype::use()
{
    cout << "ConcretePrototype::use()" << endl;
    cout << "name: " << name << endl;
}

ConcretePrototypeSub::ConcretePrototypeSub(string name, int age) : ConcretePrototype(name)
{
    this->age = age;
}

// : 后面相当于super(prototype), 深拷贝了父类的私有成员
ConcretePrototypeSub::ConcretePrototypeSub(const ConcretePrototypeSub &prototype) : ConcretePrototype(prototype)
{
    this->age = prototype.age;
}

Prototype *ConcretePrototypeSub::clone()
{
    return new ConcretePrototypeSub(*this);
}

void ConcretePrototypeSub::use()
{
    cout << "ConcretePrototypeSub::use()" << endl;
    cout << "name: " << name << endl;
    cout << "age: " << age << endl;
}


int main()
{
    Prototype *prototype = new ConcretePrototype("prototype");
    prototype->use();

    Prototype *prototypeClone = prototype->clone();
    prototypeClone->use();

    Prototype *prototypeSub = new ConcretePrototypeSub("prototypeSub", 18);
    prototypeSub->use();

    Prototype *prototypeSubClone = prototypeSub->clone();
    prototypeSubClone->use();

    delete prototype;
    delete prototypeClone;
    delete prototypeSub;
    delete prototypeSubClone;

    return 0;
}