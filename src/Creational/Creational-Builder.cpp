#include <iostream>
#include <string>
using namespace std;

/*

*/

/* 声明 */

class Product;
class Builder;
class ConcreteBuilder;
class Director;

/* 定义 */

class Product
{
private:
    string partA;
    string partB;
    string partC;

public:
    void setPartA(string partA);
    void setPartB(string partB);
    void setPartC(string partC);
    void use();
};

class Builder
{
public:
    virtual ~Builder() {}
    virtual void buildPartA() = 0;
    virtual void buildPartB() = 0;
    virtual void buildPartC() = 0;
    virtual Product *getProduct() = 0;
};

class ConcreteBuilder : public Builder
{
private:
    Product *product;

public:
    ConcreteBuilder();
    void buildPartA();
    void buildPartB();
    void buildPartC();
    Product *getProduct();
};

class Director
{
private:
    Builder *builder;

public:
    Director(Builder *builder);
    Product *construct();
};

/* 实现 */

void Product::setPartA(string partA)
{
    this->partA = partA;
}

void Product::setPartB(string partB)
{
    this->partB = partB;
}

void Product::setPartC(string partC)
{
    this->partC = partC;
}

void Product::use()
{
    cout << "Product::use()" << endl;
    cout << "partA: " << partA << endl;
    cout << "partB: " << partB << endl;
    cout << "partC: " << partC << endl;
}

ConcreteBuilder::ConcreteBuilder()
{
    product = new Product();
}

void ConcreteBuilder::buildPartA()
{
    cout << "ConcreteBuilder::buildPartA()" << endl;
    product->setPartA("partA");
}

void ConcreteBuilder::buildPartB()
{
    cout << "ConcreteBuilder::buildPartB()" << endl;
    product->setPartB("partB");
}

void ConcreteBuilder::buildPartC()
{
    cout << "ConcreteBuilder::buildPartC()" << endl;
    product->setPartC("partC");
}

Product *ConcreteBuilder::getProduct()
{
    return product;
}

Director::Director(Builder *builder)
{
    this->builder = builder;
}

Product *Director::construct()
{
    builder->buildPartA();
    builder->buildPartB();
    builder->buildPartC();
    return builder->getProduct();
}

// 客户端

int main()
{
    Builder *builder = new ConcreteBuilder();
    Director director(builder);

    Product *product = director.construct();

    product->use();

    delete builder;
    delete product;

    return 0;
}