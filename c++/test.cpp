#include <iostream>

using namespace std;

// 基类1
class A
{
public:
	virtual void prtA1()
	{
		cout << "A1" << endl;
	}
	virtual void prtA2()
	{
		cout << "A2" << endl;
	}
};

// 基类2
class B
{
public:
	virtual void prtB()
	{
		cout << "B" << endl;
	}
};

class C : public A, public B
{
};

int main(void)
{
	C *c = new C();
	A *a = (A *)c;
	B *e = (B *)a;
	// a->prtB();找不到
	// e->prtA();找不到
	e->prtB();
	cout << a << endl;
	cout << e << endl;
	return 0;
}