#include <iostream>
#include <string>
using namespace std;

/* 声明 */

class Command;
class CommandA;
class CommandB;
class Receiver;
class Invoker;

/* 定义 */

class Command
{
public:
    virtual ~Command() {}
    virtual void execute() = 0;
};

// 每个命令对应一个接收者
class CommandA : public Command
{
private:
    Receiver *receiver;

public:
    CommandA(Receiver *receiver);
    void execute();
};

class CommandB : public Command
{
private:
    Receiver *receiver;

public:
    CommandB(Receiver *receiver);
    void execute();
};

class Receiver
{
public:
    void actionA();
    void actionB();
};

class Invoker
{
public:
    void call(Command *command);
};

/* 实现 */

CommandA::CommandA(Receiver *receiver)
{
    this->receiver = receiver;
}

void CommandA::execute()
{
    this->receiver->actionA();
}

CommandB::CommandB(Receiver *receiver)
{
    this->receiver = receiver;
}

void CommandB::execute()
{
    this->receiver->actionB();
}

void Receiver::actionA()
{
    cout << "Receiver::actionA()" << endl;
}

void Receiver::actionB()
{
    cout << "Receiver::actionB()" << endl;
}

void Invoker::call(Command *command)
{
    command->execute();
}

int main()
{
    Receiver *receiver1 = new Receiver();
    Receiver *receiver2 = new Receiver();
    Command *commandA = new CommandA(receiver1);
    Command *commandB = new CommandB(receiver2);
    Invoker *invoker = new Invoker();
    invoker->call(commandA);
    invoker->call(commandB);

    delete receiver1;
    delete receiver2;
    delete commandA;
    delete commandB;

    return 0;
}