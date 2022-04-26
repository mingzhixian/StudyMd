#include <iostream>

using namespace std;

class A
{
public:
	A(int a) : age(a)
	{
		cout << "A的构造函数。" << endl;
	}
	A(const A &obj)
	{
		cout << "A的拷贝构造函数。" << endl;
	}
	void operator=(const A &obj)
	{
		age = obj.age;
		cout << "A的重写赋值运算符。" << endl;
	}

public:
	int age;
};

class B : public A
{
public:
	B(int a, char n) : A(a), name(n)
	{
		cout << "B的构造函数。" << endl;
	}
	B(const B &obj) : A(obj.age), name(obj.name)
	{
		cout << "B的拷贝构造函数。" << endl;
	}

public:
	char name;
};

int main(void)
{
	B b1(20, 'r');
	B b2(12, 'u');
	b2 = b1;
	cout << "b2 name:" << b2.name << " age:" << b2.age << endl;
	return 0;
}