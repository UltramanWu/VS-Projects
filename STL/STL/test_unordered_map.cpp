//---------------------------------------------------
#include <unordered_map>
#include <stdexcept>
#include <string>
#include <cstdlib> //abort()
#include <cstdio>  //snprintf()
#include <iostream>
#include <ctime> 
using namespace std;
//-----------------
long get_a_target_long()
{
	long target = 0;

	cout << "target (0~" << RAND_MAX << "): ";
	cin >> target;
	return target;
}

string get_a_target_string()
{
	long target = 0;
	char buf[10];

	cout << "target (0~" << RAND_MAX << "): ";
	cin >> target;
	sprintf_s(buf, 10, "%d", target);
	return string(buf);
}

int compareLongs(const void* a, const void* b)
{
	return (*(long*)a - *(long*)b);
}

int compareStrings(const void* a, const void* b)
{
	if (*(string*)a > *(string*)b)
		return 1;
	else if (*(string*)a < *(string*)b)
		return -1;
	else
		return 0;
}


namespace jj16
{
	void test_unordered_map(long& value)
	{
		cout << "\ntest_unordered_map().......... \n";

		unordered_map<long, string> c;
		char buf[10];

		clock_t timeStart = clock();
		for (long i = 0; i < value; ++i)
		{
			try {
				sprintf_s(buf, 10, "%d", rand());
				c[i] = string(buf);
			}
			catch (exception& p) {
				cout << "i=" << i << " " << p.what() << endl;
				abort();
			}
		}
		cout << "milli-seconds : " << (clock() - timeStart) << endl;
		cout << "unordered_map.size()= " << c.size() << endl;	//357913941
		cout << "unordered_map.max_size()= " << c.max_size() << endl;

		long target = get_a_target_long();
		timeStart = clock();
		//! auto pItem = find(c.begin(), c.end(), target);	//map ²»ßmÓÃ std::find() 			
		auto pItem = c.find(target);

		cout << "c.find(), milli-seconds : " << (clock() - timeStart) << endl;
		if (pItem != c.end())
			cout << "found, value=" << (*pItem).second << endl;
		else
			cout << "not found! " << endl;
	}
}

int main()
{
	long Value = 100000;
	jj16::test_unordered_map(Value);

	system("pause");
	return 0;
}