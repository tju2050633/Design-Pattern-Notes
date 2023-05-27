#include <iostream>
#include <string>
#include <map>
using namespace std;

/*
对象间通信
*/

/* 声明 */
class Mediator;
class ConcreteMediator;
class Colleague;
class ConcreteColleagueA;
class ConcreteColleagueB;

/* 定义 */

// 中介
class Mediator
{
public:
    virtual ~Mediator() {}
    virtual void send(int receiverID, string message) = 0;
    virtual void registered(int ID, Colleague *colleague) = 0;
};

class ConcreteMediator : public Mediator
{
private:
    map<int, Colleague *> colleagues;

public:
    void send(int receiverID, string message);
    void registered(int ID, Colleague *colleague);
};

// 同事
class Colleague
{
protected:
    Mediator *mediator;

public:
    virtual ~Colleague() {}
    void setMediator(Mediator *mediator) { this->mediator = mediator; }
    virtual void send(int receiverID, string message) = 0;
    virtual void receive(string message) = 0;
};

class ConcreteColleagueA : public Colleague
{
public:
    void send(int receiverID, string message);
    void receive(string message);
};

class ConcreteColleagueB : public Colleague
{
public:
    void send(int receiverID, string message);
    void receive(string message);
};

/* 实现 */

// 中介
void ConcreteMediator::send(int receiverID, string message)
{
    if (colleagues.find(receiverID) != colleagues.end())
    {
        colleagues[receiverID]->receive(message);
    }
    else
    {
        cout << "Receiver not found." << endl;
    }
}

void ConcreteMediator::registered(int ID, Colleague *colleague)
{
    if (colleagues.find(ID) == colleagues.end())
    {
        colleagues[ID] = colleague;
        colleague->setMediator(this);   // 注册时顺便给同事设置中介
    }
    else
    {
        cout << "ID already registered." << endl;
    }
}

// 同事
void ConcreteColleagueA::send(int receiverID, string message)
{
    mediator->send(receiverID, message);
}

void ConcreteColleagueA::receive(string message)
{
    cout << "ConcreteColleagueA received: " << message << endl;
}

void ConcreteColleagueB::send(int receiverID, string message)
{
    mediator->send(receiverID, message);
}

void ConcreteColleagueB::receive(string message)
{
    cout << "ConcreteColleagueB received: " << message << endl;
}

int main()
{
    ConcreteMediator *mediator = new ConcreteMediator();
    ConcreteColleagueA *colleagueA = new ConcreteColleagueA();
    ConcreteColleagueB *colleagueB = new ConcreteColleagueB();

    mediator->registered(1, colleagueA);
    mediator->registered(2, colleagueB);

    colleagueA->send(2, "Hello, I'm A.");
    colleagueB->send(1, "Hello, I'm B.");

    delete mediator;
    delete colleagueA;
    delete colleagueB;

    return 0;
}