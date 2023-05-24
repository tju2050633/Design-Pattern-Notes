#include <iostream>
using namespace std;

/*
有两种产品：ProductA 和 ProductB
产品实现相同的接口 Product
有两种工厂：FactoryA 和 FactoryB
工厂实现相同的接口 Factory
工厂A生产产品A，工厂B生产产品B

客户端只需要知道工厂的接口，不需要知道具体的工厂和产品
*/

/* 声明 */
class Product;
class ProductA;
class ProductB;
class Factory;
class FactoryA;
class FactoryB;

/* 定义 */

// 产品

class Product
{
public:
    virtual ~Product() {}
    virtual void use() = 0; // 抽象类
};

class ProductA : public Product
{
    void use();
};

class ProductB : public Product
{
    void use();
};

// 工厂

class Factory
{
public:
    virtual ~Factory() {}
    virtual Product *createProduct() = 0; // 抽象类
};

class FactoryA : public Factory
{
    ProductA *createProduct();
};

class FactoryB : public Factory
{
    ProductB *createProduct();
};

/* 实现 */

// 产品

void ProductA::use()
{
    cout << "ProductA::use()" << endl;
}

void ProductB::use()
{
    cout << "ProductB::use()" << endl;
}

// 工厂

ProductA *FactoryA::createProduct()
{
    cout << "FactoryA::createProduct()" << endl;
    return new ProductA();
}

ProductB *FactoryB::createProduct()
{
    cout << "FactoryB::createProduct()" << endl;
    return new ProductB();
}

// 客户端

int main()
{
    // 生产A
    Factory *factoryA = new FactoryA();
    Product *productA = factoryA->createProduct();
    productA->use();

    // 生产B
    Factory *factoryB = new FactoryB();
    Product *productB = factoryB->createProduct();
    productB->use();

    delete factoryA;
    delete productA;
    delete factoryB;
    delete productB;

    return 0;
}