//#include <iostream>
//#include <vector>
//#include <string>
//#include <algorithm>
//#include <functional>
//#include <tuple>
//using namespace std;
//
//
//double my_divide(double x, double y){
//	return x / y;
//}
//
//
//int main()
//{
//	
//	using namespace placeholders;
//
//	auto fn_five = bind(my_divide, 11, 2);
//	cout << fn_five() << endl;
//	auto fn_half = bind(my_divide, _1 , 2);
//	cout << fn_half(13) << endl;
//	auto fn_rounding = bind<int>(my_divide, _1, 3);
//	cout << fn_rounding(10) << "\n";
//
//	vector<int> v{ 15, 37, 94, 50, 76, 58, 28, 98 };
//	int n = count_if(v.cbegin(), v.cend(), not1(bind2nd(less<int>(), 50)));
//	cout << "n=" << n << endl;
//	auto fn_ = bind(less<int>(), _1, 50);
//	cout << count_if(v.cbegin(), v.cend(), fn_) << endl;
//	cout << count_if(v.begin(), v.end(), bind(less<int>(), _1, 50)) << endl;
//	ostream_iterator<int> iter(cout, ",");
//	copy(v.begin(), v.end(), iter);  /*使用copy来讲元素赋给cout*/
//	cout << "\n";
//	istream_iterator<int> c_in(cin);  /* 创建一个初始化值为cin的输入流迭代器 */
//	system("pause");
//	return 0;
//}