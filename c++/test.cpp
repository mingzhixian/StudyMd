#include <iostream>

using namespace std;

// 基类1
class A
{
public:
	virtual void prtA()
	{
		cout << "A" << endl;
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
	A *a = (C *)c;
	B *b = (C *)c;
	a->prtA();
	// a->prtB();找不到
	// b->prtA();找不到
	b->prtB();
	c->prtA();
	c->prtB();
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
	return 0;
}