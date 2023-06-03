#include <iostream>
#include <string>
using namespace std;

/*
举例：创建汽车和汽车手册
*/

/* ********************************* */
// 声明
/* ********************************* */

// 产品
class Car;
class Manual;

// 建造者
class Builder;
class CarBuilder;
class ManualBuilder;

// 主管
class Director;

/* ********************************* */
// 定义产品
/* ********************************* */

class Car
{
};

class Manual
{
};

/* ********************************* */
// 定义builder接口
/* ********************************* */

class Builder
{
public:
    virtual ~Builder() {}

    virtual void reset() = 0;
    virtual void setSeats(int number) = 0;
    virtual void setEngine(string engine) = 0;
    virtual void setTripComputer() = 0;
    virtual void setGPS() = 0;
};

/* ********************************* */
// 定义builder
/* ********************************* */

class CarBuilder : public Builder
{
private:
    Car *car;

public:
    void reset()
    {
        cout << "CarBuilder::reset()" << endl;
        car = new Car();
    }

    void setSeats(int number)
    {
        cout << "CarBuilder::setSeats() seat number = " << number << endl;
    }

    void setEngine(string engine)
    {
        cout << "CarBuilder::setEngine() engine type = " << engine << endl;
    }

    void setTripComputer()
    {
        cout << "CarBuilder::setTripComputer()" << endl;
    }

    void setGPS()
    {
        cout << "CarBuilder::setGPS()" << endl;
    }

    Car *getResult()
    {
        return car;
    }
};

class ManualBuilder : public Builder
{
private:
    Manual *manual;

public:
    void reset()
    {
        cout << "ManualBuilder::reset()" << endl;
        manual = new Manual();
    }

    void setSeats(int number)
    {
        cout << "ManualBuilder::setSeats() seat number = " << number << endl;
    }

    void setEngine(string engine)
    {
        cout << "ManualBuilder::setEngine() engine type = " << engine << endl;
    }

    void setTripComputer()
    {
        cout << "ManualBuilder::setTripComputer()" << endl;
    }

    void setGPS()
    {
        cout << "ManualBuilder::setGPS()" << endl;
    }

    Manual *getResult()
    {
        return manual;
    }
};

/* ********************************* */
// 定义director
/* ********************************* */

class Director
{
private:
    Builder *builder;

public:
    void setBuilder(Builder *builder)
    {
        // 这里居然必须有this->，否则会报错
        this->builder = builder;
    }

    // 对不同类型的产品，不在builder上区分，而是让director通过参数区分
    void constructSportsCar()
    {
        builder->reset();
        builder->setSeats(2);
        builder->setEngine("sport engine");
        builder->setTripComputer();
        builder->setGPS();
    }

    void constructSUV()
    {
        builder->reset();
        builder->setSeats(4);
        builder->setEngine("SUV engine");
        builder->setTripComputer();
        builder->setGPS();
    }
};

/* ********************************* */
// 客户端
/* ********************************* */

int main()
{
    Director *director = new Director();
    Car *car;
    Manual *manual;

    // 创建Car
    CarBuilder *carBuilder = new CarBuilder();
    director->setBuilder(carBuilder);

    // 创建Sports Car
    cout << "========================Create Sports Car========================" << endl;
    director->constructSportsCar();
    car = carBuilder->getResult();

    // 创建SUV Car
    cout << "========================Create SUV Car========================" << endl;
    director->constructSUV();
    car = carBuilder->getResult();

    // 创建Manual
    ManualBuilder *manualBuilder = new ManualBuilder();
    director->setBuilder(manualBuilder);

    // 创建Sports Car
    cout << "========================Create Sports Car Manual========================" << endl;
    director->constructSportsCar();
    manual = manualBuilder->getResult();

    // 创建SUV Car
    cout << "========================Create SUV Car Manual========================" << endl;
    director->constructSUV();
    manual = manualBuilder->getResult();

    delete director;
    delete car;
    delete manual;
    delete carBuilder;
    delete manualBuilder;

    return 0;
}