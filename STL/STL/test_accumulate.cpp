//---------------------------------------------------
#include <iostream>     // std::cout
#include <functional>   // std::minus
#include <numeric>      // std::accumulate
using namespace std;

namespace jj34
{
	int myfunc(int x, int y) { return x + 2 * y; }
	int myfunc1(int x, int y) { return 2 * x + y; }
	struct myclass {
		int operator()(int x, int y) { return x + 3 * y; }
	} myobj;
	/* accumulate()������һ���ۻ�����ĺ���������ʹ��Ĭ�Ϻ�����Ҳ����ָ�����㺯�� */
	void test_accumulate()
	{
		cout << "\ntest_accumulate().......... \n";
		int init = 100;
		int nums[] = { 10, 20, 30 };

		cout << "using default accumulate: ";
		cout << accumulate(nums, nums + 3, init);  //160
		cout << '\n';

		cout << "using functional's minus: ";
		cout << accumulate(nums, nums + 3, init, minus<int>()); //40
		cout << '\n';

		cout << "using functional's minus: ";
		cout << accumulate(nums, nums + 3, init, myfunc1); //40
		cout << '\n';

		cout << "using custom function: ";
		cout << accumulate(nums, nums + 3, init, myfunc);	//220
		cout << '\n';

		cout << "using custom object: ";
		cout << accumulate(nums, nums + 3, init, myobj);	//280
		cout << '\n';
	}
}

//int main()
//{
//	jj34::test_accumulate();
//
//	system("pause");
//	return 0;
//}