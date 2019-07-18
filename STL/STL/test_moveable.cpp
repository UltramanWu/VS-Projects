#include <iostream>
#include <vector>
#include <ctime>  //clock_t, clock()  /*C计时函数头文件 */
using namespace std;


template<typename M, typename NM>
void test_moveable(M c1, NM c2, long& value)
{
	char buf[10];

	//測試 move 
	cout << "\n\ntest, with moveable elements" << endl;
	typedef typename iterator_traits<typename M::iterator>::value_type  V1type; /* 使用萃取机获取当前模板下的成员函数的类型 */
	clock_t timeStart = clock();
	for (long i = 0; i < value; ++i)
	{
		sprintf(buf, 10, "%d", rand());
		auto ite = c1.end();
		c1.insert(ite, V1type(buf));
	}
	cout << "construction, milli-seconds : " << (clock() - timeStart) << endl;
	cout << "size()= " << c1.size() << endl;
	output_static_data(*(c1.begin()));

	timeStart = clock();
	M c11(c1);
	cout << "copy, milli-seconds : " << (clock() - timeStart) << endl;

	timeStart = clock();
	M c12(std::move(c1));
	cout << "move copy, milli-seconds : " << (clock() - timeStart) << endl;

	timeStart = clock();
	c11.swap(c12);
	cout << "swap, milli-seconds : " << (clock() - timeStart) << endl;



	//測試 non-moveable 	
	cout << "\n\ntest, with non-moveable elements" << endl;
	typedef typename iterator_traits<typename NM::iterator>::value_type  V2type;
	timeStart = clock();
	for (long i = 0; i < value; ++i)
	{
		snprintf(buf, 10, "%d", rand());
		auto ite = c2.end();
		c2.insert(ite, V2type(buf));
	}

	cout << "construction, milli-seconds : " << (clock() - timeStart) << endl;
	cout << "size()= " << c2.size() << endl;
	output_static_data(*(c2.begin()));

	timeStart = clock();
	NM c21(c2);
	cout << "copy, milli-seconds : " << (clock() - timeStart) << endl;

	timeStart = clock();
	NM c22(std::move(c2));
	cout << "move copy, milli-seconds : " << (clock() - timeStart) << endl;

	timeStart = clock();
	c21.swap(c22);
	cout << "swap, milli-seconds : " << (clock() - timeStart) << endl;
}

//int main()
//{
//	vector<int> a;
//	vector<string> b;
//	//test_moveable(a,b,3000000L);
//	system("pause");
//	return 0;
//}