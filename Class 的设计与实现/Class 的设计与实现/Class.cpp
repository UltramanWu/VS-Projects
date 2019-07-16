//#include <iostream>
//using namespace std;
//#ifndef _COMPLEX_
//#define _COMPLEX_
//
//class Complex
//{
//public:
//	Complex(int _first, int _second);
//	~Complex();
//	Complex& operator +=(const Complex&);
//	int Frist() const { return first; }  /* 只要不改变引用变量的函数名，在函数声明后加上const变量 */
//	int Second() const { return second; }
//	Complex(const Complex&);  /* 声明阶段可以不指定变量名 */
//	Complex operator= (const Complex&);
//private:
//	int first, second;
//	Complex* p;
//};
//
//Complex::Complex(int _first = 0, int _second = 0) :first(_first), second(_second)
//{
//	p = new Complex;
//}
//
//Complex::~Complex()  /* 除指针外，可以不对类进行析构函数  */
//{
//	delete p;
//}
//
//
//
//#endif
//
