#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// 这里对书上的方钉、圆孔案例做一点拓展
// 适配器做成双向的
// 孔有圆方两种，钉也有圆方两种

/* ********************************* */
// 声明
/* ********************************* */

// 圆/方 钉/孔
class RoundPeg;
class SquarePeg;
class RoundHole;
class SquareHole;

// 适配器
class Round2Square_PegAdapter;
class Square2Round_PegAdapter;
class Round2Square_HoleAdapter;
class Square2Round_HoleAdapter;

/* ********************************* */
// 定义钉和孔
/* ********************************* */

// 钉
class RoundPeg
{
private:
    double radius;

public:
    RoundPeg(double radius) : radius(radius) {}
    double getRadius() { return radius; }
};

class SquarePeg
{
private:
    double width;

public:
    SquarePeg(double width) : width(width) {}
    double getWidth() { return width; }
};

// 孔
class RoundHole
{
private:
    double radius;

public:
    RoundHole(double radius) : radius(radius) {}
    double getRadius() { return radius; }

    // 圆孔只接受圆钉
    bool fits(RoundPeg *peg)
    {
        return radius >= peg->getRadius();
    }
};

class SquareHole
{
private:
    double width;

public:
    SquareHole(double width) : width(width) {}
    double getWidth() { return width; }

    // 方孔只接受方钉
    bool fits(SquarePeg *peg)
    {
        return width >= peg->getWidth();
    }
};

/* ********************************* */
// 定义钉子适配器
/* ********************************* */

// 圆钉适配成方钉：计算圆的外接正方形的边长
class Round2Square_PegAdapter : public SquarePeg
{
private:
    RoundPeg *peg;

public:
    Round2Square_PegAdapter(RoundPeg *peg) : SquarePeg(peg->getRadius() * 2), peg(peg) {}
};

// 方钉适配成圆钉：计算正方形的外接圆的半径
class Square2Round_PegAdapter : public RoundPeg
{
private:
    SquarePeg *peg;

public:
    Square2Round_PegAdapter(SquarePeg *peg) : RoundPeg(peg->getWidth() * sqrt(2) / 2), peg(peg) {}
};

/* ********************************* */
// 定义孔适配器
/* ********************************* */

// 圆孔适配成方孔，计算圆的内接正方形的边长
class Round2Square_HoleAdapter : public SquareHole
{
private:
    RoundHole *hole;

public:
    Round2Square_HoleAdapter(RoundHole *hole) : SquareHole(hole->getRadius() * sqrt(2)), hole(hole) {}
};

// 方孔适配成圆孔，计算正方形的内接圆的半径
class Square2Round_HoleAdapter : public RoundHole
{
private:
    SquareHole *hole;

public:
    Square2Round_HoleAdapter(SquareHole *hole) : RoundHole(hole->getWidth() / 2), hole(hole) {}
};

/* ********************************* */
// 客户端
/* ********************************* */

int main()
{
    // 测试直接使用
    cout << endl
         << "Test without adapter" << endl
         << endl;

    RoundHole *roundHole5 = new RoundHole(5);
    RoundPeg *roundPeg3 = new RoundPeg(3);
    RoundPeg *roundPeg7 = new RoundPeg(7);
    cout << "Round Hole Radius : 5   Round Peg Radius : 3   Fit : " << roundHole5->fits(roundPeg3) << endl;
    cout << "Round Hole Radius : 5   Round Peg Radius : 7   Fit : " << roundHole5->fits(roundPeg7) << endl;

    SquareHole *squareHole5 = new SquareHole(5);
    SquarePeg *squarePeg3 = new SquarePeg(3);
    SquarePeg *squarePeg7 = new SquarePeg(7);
    cout << "Square Hole Width : 5   Square Peg Width : 3   Fit : " << squareHole5->fits(squarePeg3) << endl;
    cout << "Square Hole Width : 5   Square Peg Width : 7   Fit : " << squareHole5->fits(squarePeg7) << endl;

    // 直接交错使用，编译不通过
    // roundHole5->fits(squarePeg3);
    // roundHole5->fits(squarePeg7);
    // squareHole5->fits(roundPeg3);
    // squareHole5->fits(roundPeg7);

    // 测试钉子适配器
    cout << endl
         << "Test peg adapter" << endl
         << endl;

    Round2Square_PegAdapter *round2Square_PegAdapter3 = new Round2Square_PegAdapter(roundPeg3);
    Round2Square_PegAdapter *round2Square_PegAdapter7 = new Round2Square_PegAdapter(roundPeg7);
    cout << "Square Hole Width : 5   Round Peg Radius : 3   Fit : " << squareHole5->fits(round2Square_PegAdapter3) << endl;
    cout << "Square Hole Width : 5   Round Peg Radius : 7   Fit : " << squareHole5->fits(round2Square_PegAdapter7) << endl;

    Square2Round_PegAdapter *square2Round_PegAdapter3 = new Square2Round_PegAdapter(squarePeg3);
    Square2Round_PegAdapter *square2Round_PegAdapter7 = new Square2Round_PegAdapter(squarePeg7);
    cout << "Round Hole Radius : 5   Square Peg Width : 3   Fit : " << roundHole5->fits(square2Round_PegAdapter3) << endl;
    cout << "Round Hole Radius : 5   Square Peg Width : 7   Fit : " << roundHole5->fits(square2Round_PegAdapter7) << endl;

    // 测试孔适配器
    cout << endl
         << "Test hole adapter" << endl
         << endl;

    Round2Square_HoleAdapter *round2Square_HoleAdapter5 = new Round2Square_HoleAdapter(roundHole5);
    cout << "Round Hole Width : 5   Square Peg Radius : 3   Fit : " << round2Square_HoleAdapter5->fits(squarePeg3) << endl;
    cout << "Round Hole Width : 5   Square Peg Radius : 7   Fit : " << round2Square_HoleAdapter5->fits(squarePeg7) << endl;

    Square2Round_HoleAdapter *square2Round_HoleAdapter5 = new Square2Round_HoleAdapter(squareHole5);
    cout << "Square Hole Width : 5   Round Peg Width : 3   Fit : " << square2Round_HoleAdapter5->fits(roundPeg3) << endl;
    cout << "Square Hole Width : 5   Round Peg Width : 7   Fit : " << square2Round_HoleAdapter5->fits(roundPeg7) << endl;

    // delete
    delete roundHole5;
    delete roundPeg3;
    delete roundPeg7;
    delete squareHole5;
    delete squarePeg3;
    delete squarePeg7;
    delete round2Square_PegAdapter3;
    delete round2Square_PegAdapter7;
    delete square2Round_PegAdapter3;
    delete square2Round_PegAdapter7;
    delete round2Square_HoleAdapter5;
    delete square2Round_HoleAdapter5;

    return 0;
}