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
	A *a = (A *)c;
	B *b = (B *)c;
	A *d = dynamic_cast<A *>(b);
	B *e = dynamic_cast<B *>(a);
	// a->prtB();找不到
	e->prtB();
	// b->prtA();找不到
	d->prtA();
	cout << a << endl;
	cout << e << endl;
	cout << b << endl;
	cout << d << endl;
	return 0;
}