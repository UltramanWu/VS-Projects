//---------------------------------------------------
#include <iostream>     // std::cout
#include <algorithm>    // std::for_each
#include <vector>       // std::vector
using namespace std;
//using namespace jj35;

namespace jj35
{
	void myfunc(int i) {
		cout << ' ' << i;
	}
	void myfunc1(int& i){
		i += 3;
		cout << " " << i;
	}

	struct myclass {
		void operator() (int i) { cout << ' ' << i; }
	} myobj;

	void test_for_each()
	{
		cout << "\ntest_for_each().......... \n";

		vector<int> myvec;
		myvec.push_back(10);
		myvec.push_back(20);
		myvec.push_back(30);
		/*for_each()��C++11��׼��һ���µı�����ʽ��ֱ��ʹ�ú���ĺ������ö������ڵ�ÿһ��Ԫ�ؽ�����ͬ��������*/
		/* ����ֱ��ʹ��defined function�����������е�Ԫ�ؽ��и��� */
		for_each(myvec.cbegin(), myvec.cend(), myfunc);
		cout << endl;		//output: 10 20 30

		/* myfunc1��������Ԫ�ؽ����˸��ģ�ʹ�ú����ֵ���ᷢ���仯 */
		for_each(myvec.begin(), myvec.end(), myfunc1);
		cout << endl;		//output: 13 23 33

		for_each(myvec.begin(), myvec.end(), myobj);
		cout << endl;		//output: 13 23 33

		//since C++11, range-based for- statement
		for (auto& elem : myvec)
			elem += 5;

		for_each(myvec.begin(), myvec.end(), myobj);
		cout << endl;		//output: 18 28 38

		for (auto elem : myvec)
			cout << ' ' << elem; 	//output: 18 28 38
	}
}

//int main()
//{
//	jj35::test_for_each();
//
//	system("pause");
//	return 0;
//}