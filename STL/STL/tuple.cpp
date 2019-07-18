//#include <iostream>
//#include <vector>
//#include <string>
//#include <algorithm>
//#include <tuple>
//using namespace std;
//
//template <typename... T>
//ostream& operator<<(tuple<T...> t,ostream& os){
//	int i = 0;
//	while (get<i>(t)){
//		os << get<1>(t)<<" ";
//		i++;
//	}
//	return os;
//}
//
//
//int main()
//{
//	/* C++2.0中定义的一种集合，可以容纳不同的类型 */
//	tuple<string, vector<int>, int, float> t1;
//	auto t2 = make_tuple(22, 44, "in", 42.02);
//	//cout << t2 << endl;
//	cout << t2._Mysize << endl;
//	system("pause");
//	return 0;
//}