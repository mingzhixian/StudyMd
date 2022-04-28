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
	cout << "A:" << sizeof(A) << endl;
	cout << "B:" << sizeof(B) << endl;
	cout << "C:" << sizeof(C) << endl;
	return 0;
}