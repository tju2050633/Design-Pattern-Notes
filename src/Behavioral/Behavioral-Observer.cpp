#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
类似订阅机制
*/

/* 声明 */
class Subject;
class ConcreteSubject;
class Observer;
class ConcreteObserverA;
class ConcreteObserverB;

/* 定义 */

// 目标
class Subject
{
protected:
    vector<Observer *> observers;
    string state;

public:
    virtual ~Subject() {}
    virtual void attach(Observer *observer) = 0;
    virtual void detach(Observer *observer) = 0;
    virtual void notify() = 0;

    virtual void setState(string state) = 0;
    virtual string getState() = 0;
};

class ConcreteSubject : public Subject
{
public:
    void attach(Observer *observer);
    void detach(Observer *observer);
    void notify();

    void setState(string state) { this->state = state; }
    string getState() { return state; }
};

// 观察者
class Observer
{
protected:
    Subject *subject;

public:
    virtual ~Observer() {}
    virtual void update(Subject *subject) = 0;
};

class ConcreteObserverA : public Observer
{
public:
    void update(Subject *subject);
};

class ConcreteObserverB : public Observer
{
public:
    void update(Subject *subject);
};

/* 实现 */

void ConcreteSubject::attach(Observer *observer)
{
    observers.push_back(observer);
}

void ConcreteSubject::detach(Observer *observer)
{
    for (vector<Observer *>::iterator it = observers.begin(); it != observers.end(); it++)
    {
        if (*it == observer)
        {
            observers.erase(it);
            break;
        }
    }
}

void ConcreteSubject::notify()
{
    for (vector<Observer *>::iterator it = observers.begin(); it != observers.end(); it++)
    {
        (*it)->update(this);
    }
}

void ConcreteObserverA::update(Subject *subject)
{
    cout << "ConcreteObserverA::update: " << subject->getState() << endl;
}

void ConcreteObserverB::update(Subject *subject)
{
    cout << "ConcreteObserverB::update: " << subject->getState() << endl;
}

// 客户端
int main()
{
    Subject *subject = new ConcreteSubject();
    Observer *observerA = new ConcreteObserverA();
    Observer *observerB = new ConcreteObserverB();

    subject->attach(observerA);
    subject->attach(observerB);

    subject->setState("new state");
    subject->notify();

    subject->detach(observerA);

    subject->setState("new state again");
    subject->notify();

    delete subject;
    delete observerA;
    delete observerB;

    return 0;
}