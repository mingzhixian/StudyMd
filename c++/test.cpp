#include <iostream>

using namespace std;

// 基类1
class People
{
public:
	People()
	{
		cout << "创建了一个people" << endl;
	}
	void setName(char n)
	{
		name = n;
	}
	void setAge(int a)
	{
		age = a;
	}
	void setGrade(int g)
	{
		grade = g;
	}

public:
	char name;
	int age;
	int grade;
};

// 基类2
class Student : virtual public People
{
};

// 基类3
class Boy : virtual public People
{
};

// 派生类
class CollegeStudents : public Boy, public Student
{
};

int main(void)
{
	CollegeStudents rui;
	rui.setGrade(2);
	cout << "grade:" << rui.grade << endl;
	return 0;
}