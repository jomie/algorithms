#include <iostream>
#include <string.h>

using namespace std;
// class A
// {
// public:
// 	 A();
// 	~ A();

// 	/* data */
// };

// class B: public A
// {
// public:
// 	B();
// 	~B();

// 	/* data */
// };

// A::A()
// {
// 	cout << "constructor A!"  << endl;
// }

// A::~A()
// {
// 	cout << "disconstructor A !" << endl;
// }

// B::B()
// {
// 	cout << "constructor B!"  << endl;
// }

// B::~B()
// {
// 	cout << "disconstructor B !" << endl;

// }

#pragma pack(2)
class aaa
{
	int i;
	union U
	{
		char buff[13];
		int i;
	}u;
	// void foo() {    }
	// typedef char* (*f)(void*);
	enum{red, green, blue} color;
}a;



class A
{
public:
	A()  {    cout<<"A"<<endl;    }
	~A() {    cout<<"~A"<<endl;   }
};

class B:public A
{
public:
	B(A &a):_a(a)
	{
		cout<<"B"<<endl;
	}
	~B()
	{
		cout<<"~B"<<endl;
	}
private:
	A _a;
};

struct Foo
{
	Foo() {  }
	Foo(int) {  }
	void fun()   {  }
};
int main(void)
{
	Foo a(10);    //语句1
	a.fun();      //语句2
	Foo b;      //语句3
	b.fun();      //语句4
	return 0;
}