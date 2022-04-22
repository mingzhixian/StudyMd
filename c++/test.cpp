#include <iostream>

using namespace std;

class Box
{
public:
	static int objectCount;
	static const int i1 = 1;
	// static const float i2=1.0;报错
	static const float i2;
	// 构造函数定义
	Box(double l = 2.0, double b = 2.0, double h = 2.0)
	{
		cout << "构造函数" << endl;
		length = l;
		breadth = b;
		height = h;
		// 每次创建对象时增加 1
		objectCount++;
	}
	//计算体积
	double Volume()
	{
		return length * breadth * height;
	}

private:
	double length;	// 长度
	double breadth; // 宽度
	double height;	// 高度
};

//定义并初始化类 Box 的静态成员
int Box::objectCount = 0;
const float Box::i2 = 2.0;

int main(void)
{
	return 0;
}