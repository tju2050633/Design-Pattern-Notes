#include <iostream>
#include <string>
using namespace std;

// 实现遥控器-设备例子

/* ********************************* */
// 声明
/* ********************************* */

class Device;
class Radio;
class TV;
class Remote;

/* ********************************* */
// 定义设备继承体系
/* ********************************* */

class Device
{
protected:
    bool enabled;
    int volume;
    int channel;

public:
    Device() : enabled(false), volume(0), channel(0) {}

    bool isEnabled() { return enabled; }
    void enable() { enabled = true; }
    void disable() { enabled = false; }

    int getVolume() { return volume; }
    void setVolume(int volume) { this->volume = volume; }

    int getChannel() { return channel; }
    void setChannel(int channel) { this->channel = channel; }
};

class Radio : public Device
{
public:
    Radio() : Device() {}
};

class TV : public Device
{
public:
    TV() : Device() {}
};

/* ********************************* */
// 定义遥控器
/* ********************************* */

class Remote
{
protected:
    Device *device;

public:
    Remote(Device *device) : device(device) {}

    void togglePower() { device->isEnabled() ? device->disable() : device->enable(); }

    void volumeDown() { device->setVolume(device->getVolume() - 1); }
    void volumeUp() { device->setVolume(device->getVolume() + 1); }

    void channelDown() { device->setChannel(device->getChannel() - 1); }
    void channelUp() { device->setChannel(device->getChannel() + 1); }
};

/* ********************************* */
// 客户端
/* ********************************* */

int main()
{
    // 不同类型的device通过子类区分，便于拓展
    // remote也可以有多种类型，这里没有实现
    // device和remot之间的组合通过remote持有的device指针实现桥接
    Device *radio = new Radio();
    Device *tv = new TV();
    Remote *radioRemote = new Remote(radio);
    Remote *tvRemote = new Remote(tv);

    // 客户端通过remote控制device，不需要知道device的具体类型、接口和实现
    radioRemote->togglePower();
    radioRemote->volumeUp();
    radioRemote->volumeUp();
    radioRemote->channelUp();
    radioRemote->channelUp();

    tvRemote->togglePower();
    tvRemote->volumeUp();
    tvRemote->volumeUp();
    tvRemote->channelUp();
    tvRemote->channelUp();

    delete radio;
    delete tv;
    delete radioRemote;
    delete tvRemote;

    return 0;
}