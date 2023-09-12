/*
 * @Author: Jialin Lu
 * @GitHub: https://github.com/tju2050633
 * @Date: 2023-05-27 10:22:49
 * @FilePath: /DesignPattern/src/Structural/Structural-Proxy.cpp
 * @Description:
 *
 * Copyright (c) 2023 by 1640889387@qq.com, All Rights Reserved.
 */
#include <iostream>
#include <string>
using namespace std;

/* 声明 */
class Subject;
class RealSubject;
class Proxy;

/* 定义 */
class Subject {
   public:
    virtual void Request() = 0;
};

class RealSubject : public Subject {
   public:
    void Request() override { cout << "RealSubject::Request()" << endl; }
};

class Proxy : public Subject {
   private:
    RealSubject *realSubject;
    void PreRequest() { cout << "Proxy::PreRequest()" << endl; }
    void PostRequest() { cout << "Proxy::PostRequest()" << endl; }

   public:
    Proxy(RealSubject *realSubject) { this->realSubject = realSubject; }
    void Request() override {
        PreRequest();
        realSubject->Request();
        PostRequest();
    }
};

// 客户端
int main() {
    // 这里客户端创建了subject然后指定给proxy
    // 相比于在proxy的ctor中new一个subject，这样可以更灵活地指定subject对象
    RealSubject *realSubject = new RealSubject();
    Proxy *proxy = new Proxy(realSubject);
    proxy->Request();

    delete realSubject;
    delete proxy;

    return 0;
}