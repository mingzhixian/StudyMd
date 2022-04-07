#include <iostream>
#include <unistd.h>

using namespace std;

class Line
{
public:
    void setLength(double len);
    double getLength(void);
    time_t getTime(void);
    Line();                // 构造函数声明
    Line(const Line &obj); //拷贝函数声明
    ~Line();               // 析构函数声明

private:
    double length;
    time_t setTime;
};

// 成员函数定义，包括构造函数
Line::Line(void)
{
    time(&setTime);
    cout << "创建！" << endl;
}
Line::Line(const Line &obj)
{
    length = obj.length;
    time(&setTime);
    cout << "拷贝！" << endl;
}
Line::~Line(void)
{
    cout << "销毁！" << endl;
}

void Line::setLength(double len)
{
    length = len;
}

double Line::getLength(void)
{
    return length;
}

time_t Line::getTime(void)
{
    return setTime;
}
// 程序的主函数
int main()
{
    Line line1;
    sleep(2);
    Line line2 = line1;
    cout << line1.getTime() << endl;
    cout << line2.getTime() << endl;
    return 0;
}