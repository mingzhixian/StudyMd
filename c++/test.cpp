#include <iostream>
#include <malloc.h>

using namespace std;

class Line
{
public:
    void setLength(double len);
    double getLength(void);
    Line();                         // 构造函数声明
    Line(const Line &obj);          //拷贝函数声明
    ~Line();                        // 析构函数声明
    void operator=(const Line &obj) //复写赋值函数
    {
        if (&obj == this)
        {
            return;
        }
        else
        {
            delete length;
            length = (double *)malloc(sizeof(double));
            *length = *(obj.length);
        }
    };

private:
    double *length;
};

// 成员函数定义，包括构造函数
Line::Line(void)
{
    length = (double *)malloc(sizeof(double));
    cout << "创建！" << endl;
}
Line::Line(const Line &length)
{
    this->length = (double *)malloc(sizeof(double));
    *(this->length) = *(length.length);
    cout << "拷贝！" << endl;
}
Line::~Line(void)
{
    cout << "销毁！" << endl;
}

void Line::setLength(double len)
{
    *length = len;
}

double Line::getLength(void)
{
    return *length;
}
// 程序的主函数
int main()
{
    Line line1;
    // 设置长度
    line1.setLength(6.0);
    cout << "line1长度为：" << line1.getLength() << endl;
    Line line2;
    line2 = line1;
    cout << "line2长度为：" << line2.getLength() << endl;
    //修改line2
    line2.setLength(7.0);
    cout << "line1长度为：" << line1.getLength() << endl;
    cout << "line2长度为：" << line2.getLength() << endl;
    return 0;
}