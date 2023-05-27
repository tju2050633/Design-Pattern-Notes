#include <iostream>
using namespace std;

/*
有两种产品：ProductA 和 ProductB，它们没有共同的接口，是两种完全不同的产品
每种产品有两种实现：ProductA1 和 ProductA2，ProductB1 和 ProductB2（就像两个品牌）
有两种工厂：Factory1 和 Factory2（就像两个品牌的工厂）
工厂实现相同的接口 Factory，Factory可以生产两种产品A和B
工厂1生产产品A1和B1，工厂2生产产品A2和B2
*/

/* 声明 */
class ProductA;
class ProductA1;
class ProductA2;
class ProductB;
class ProductB1;
class ProductB2;
class Factory;
class Factory1;
class Factory2;

/* 定义 */

// 产品A
class ProductA
{
public:
    virtual ~ProductA() {}
    virtual void use() = 0; // 抽象类
};

class ProductA1 : public ProductA
{
public:
    void use();
};

class ProductA2 : public ProductA
{
public:
    void use();
};

// 产品B
class ProductB
{
public:
    virtual ~ProductB() {}
    virtual void use() = 0; // 抽象类
};

class ProductB1 : public ProductB
{
public:
    void use();
};

class ProductB2 : public ProductB
{
public:
    void use();
};

// 工厂
class Factory
{
public:
    virtual ~Factory() {}
    virtual ProductA *createProductA() = 0; // 抽象类
    virtual ProductB *createProductB() = 0; // 抽象类
};

class Factory1 : public Factory
{
public:
    ProductA1 *createProductA();
    ProductB1 *createProductB();
};

class Factory2 : public Factory
{
public:
    ProductA2 *createProductA();
    ProductB2 *createProductB();
};

/* 实现 */

// 产品A

void ProductA1::use()
{
    cout << "ProductA1::use()" << endl;
}

void ProductA2::use()
{
    cout << "ProductA2::use()" << endl;
}

// 产品B

void ProductB1::use()
{
    cout << "ProductB1::use()" << endl;
}

void ProductB2::use()
{
    cout << "ProductB2::use()" << endl;
}

// 工厂

ProductA1 *Factory1::createProductA()
{
    return new ProductA1();
}

ProductB1 *Factory1::createProductB()
{
    return new ProductB1();
}

ProductA2 *Factory2::createProductA()
{
    return new ProductA2();
}

ProductB2 *Factory2::createProductB()
{
    return new ProductB2();
}

// 客户端

int main()
{
    Factory *factory1 = new Factory1();
    ProductA *productA1 = factory1->createProductA();
    ProductB *productB1 = factory1->createProductB();
    productA1->use();
    productB1->use();

    Factory *factory2 = new Factory2();
    ProductA *productA2 = factory2->createProductA();
    ProductB *productB2 = factory2->createProductB();
    productA2->use();
    productB2->use();

    delete factory1;
    delete productA1;
    delete productB1;

    delete factory2;
    delete productA2;
    delete productB2;

    return 0;
}