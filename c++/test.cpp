#include <iostream>

using namespace std;

// 基类1
class A
{
private:
	int i = 0;

public:
	int geti() { return i; }
	virtual inline void prt()
	{
		cout << "A" << endl;
	}
};

// 基类2
class B : public A
{
public:
	inline void prt()
	{
		cout << geti() << endl;
	}
};

int main(void)
{
	B b;
	b.prt();
	return 0;
}