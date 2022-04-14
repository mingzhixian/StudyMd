#include <iostream>

using namespace std;

class Dot
{
public:
    int GetId() const { return id; };
    Dot()
    {
        id = 7;
        cout << "dot创建！\n";
    };

private:
    int id;
};
class Line
{
public:
    Line(int i, int dot1id) : ci(i), dot1(), dot2(dot1)
    {
        cout << "Line创建！" << endl;
    }

    Line(const Line &obj) : ci(obj.ci), dot1(), dot2(dot1)
    {
        
        cout << "Line拷贝！" << endl;
    }

    void ToString() const
    {
        cout << "ci:" << ci << "  dot1id:" << dot1.GetId() << "  dot2id:" << dot2.GetId() << endl;
    }

private:
    Dot dot1, dot2;
    const int ci;
};

// 程序的主函数
int main()
{
    Line line1(1, 1);
    Line line2 = line1;
    line1.ToString();
    line2.ToString();
    return 0;
}