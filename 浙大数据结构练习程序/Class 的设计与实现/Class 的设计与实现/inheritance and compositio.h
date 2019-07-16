#ifndef _INHERITANCE_AND_COMPOSITION_  /* 防守型声明 */
#define _INHERITANCE_AND_COMPOSITION_
#include<iostream>
#include<vector>
using namespace std;

class F;
class C;
class A
{
	
public:
	A(){
		cout << "A ctor" << endl;
	}
	virtual ~A(){
		cout << "A dctor" << endl;
	}

	void func()
	{
		cout << "A::func" << endl;
	}
	
private:
	void confunc(){
		cout << "A::confunc()" << endl;
	}
	virtual void defunc(){
		cout << "A:: defunc" << endl;
	}
	friend class F;
	friend class C;
};

class C{
public:
	C(){
		cout << "C ctor" << endl;
		a.confunc();
	}
	~C(){
		cout << "C dctor" << endl;
	}
	void Print(){
		a.confunc();
		a.defunc();
		a.func();
	}
private:
	A a;
};

class D{
public:
	D(){
		cout << "D ctor" << endl;
	}
	~D(){
		cout << "D dctor" << endl;
	}
	operator bool() {  /* 转换函数，将某一直转换为对应的返回值  */

	}
};

class B:public A
{
public:
	B(){
		cout << "B ctor" << endl;
	}
	~B(){
		cout << "B dctor" << endl;
	}

	void defunc(){
		cout << "B::defunc" << endl;
	}
	void confunc(){
		cout << "B::confunc" << endl;
	}

private:
	vector<D*> _data;

};




#endif // !_INHERITANCE_AND_COMPOSITION_
