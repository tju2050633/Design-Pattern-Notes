#include <iostream>
#include <string>
using namespace std;

// 通过对结点类（Shape子类）做最小的改动（添加accept函数），通过Visitor实现对结点类的扩展
// visit不能用重载，因为visit是虚函数，而重载是静态绑定，虚函数是动态绑定

/* ********************************* */
// 声明
/* ********************************* */

class Shape;
class Circle;
class Rectangle;
class Dot;
class Visitor;
class XMLExportVisitor;

class Shape {
    public:
        virtual ~Shape() {}
        virtual void accept(class Visitor &v) = 0;

};

class Circle : public Shape {
    public:
        void accept(Visitor &v);
};

class Rectangle : public Shape {
    public:
        void accept(Visitor &v);
};

class Dot : public Shape {
    public:
        void accept(Visitor &v);
};

class Visitor {
    public:
        virtual void visitCircle(Circle *c) = 0;
        virtual void visitRectangle(Rectangle *r) = 0;
        virtual void visitDot(Dot *d) = 0;
};

class XMLExportVisitor : public Visitor {
    public:
        void visitCircle(Circle *c);
        void visitRectangle(Rectangle *r);
        void visitDot(Dot *d);
};


/* ********************************* */
// 定义
/* ********************************* */

void Circle::accept(Visitor &v) {
    v.visitCircle(this);
}

void Rectangle::accept(Visitor &v) {
    v.visitRectangle(this);
}

void Dot::accept(Visitor &v) {
    v.visitDot(this);
}

void XMLExportVisitor::visitCircle(Circle *c) {
    cout << "Exported Circle to XML" << endl;
}

void XMLExportVisitor::visitRectangle(Rectangle *r) {
    cout << "Exported Rectangle to XML" << endl;
}

void XMLExportVisitor::visitDot(Dot *d) {
    cout << "Exported Dot to XML" << endl;
}

int main()
{
    Shape *shapes[3];
    shapes[0] = new Circle();
    shapes[1] = new Rectangle();
    shapes[2] = new Dot();

    XMLExportVisitor xmlExportVisitor = XMLExportVisitor();
    for (int i = 0; i < 3; i++) {
        shapes[i]->accept(xmlExportVisitor);
    }

    delete shapes[0];
    delete shapes[1];
    delete shapes[2];

    return 0;
}