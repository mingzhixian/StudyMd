#include <iostream>

using namespace std;

// 基类1
class A
{
public:
	A(int i)
	{
	}

protected:
	void prt()
	{
		cout << "A" << endl;
	}
};

int main(void)
{
	A a(3);
	return 0;
}