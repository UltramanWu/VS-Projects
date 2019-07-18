//#include <vector>
//#include <algorithm>
//#include <functional>
//#include <iostream>
//#include <deque>  
//#include <stack>
//#include <map>
//#include <string>
//#include <ctime>
//using namespace std;
//const long Count_Max= 1000000L;
//
//long get_a_target_long(){
//	long target;
//	cout << "target (0~" << RAND_MAX << "):";
//	cin >> target;
//	return target;
//}
//
//
//namespace jj14
//{
//	void test_map(long &value){
//		cout << "\ntest_map()................ \n";
//
//map<long,string> c;
//char buf[10];
//clock_t timeStart = clock();
//for (long i = 0; i < value;i++)
//	{
//		try
//		{
//			sprintf_s(buf, 10, "%d", rand());
//			c[i] = string(buf);
//		}
//		catch (exception& p)
//		{
//			cout << "i=" << i << " " << p.what() << endl;
//			abort();
//		}
//	}
//	cout << "milli_seconds : " << (clock() - timeStart) << endl;
//	cout << "map.size() = " << c.size() << endl;
//	cout << "map.max_size() = " << c.max_size() << endl;
//
//	long target = get_a_target_long();
//	/*timeStart = clock();
//	auto pItem = ::find(c.begin(), c.end(), target);
//	cout << "::find(),milli_second : " << (clock() - timeStart) << endl;
//	if (pItem != c.end())
//	cout << "found,value = " << (*pItem).second << endl;
//	else
//	cout << "not found!" << endl;*/
//
//	timeStart = clock();
//	auto fItem = c.find(target);
//	cout << "c.find(),milli_second : " << (clock() - timeStart) << endl;
//	if (fItem != c.end())
//		cout << "found,value = " << (*fItem).second << endl;
//	else
//		cout << "not found!" << endl;
//	}
//}
//
//
//int main()
//{
//	long MaxItems = 1000000;
//	jj14::test_map(MaxItems);
//	size_t a = 100;
//	int b = a;
//	system("pause");
//	return 0;
//}