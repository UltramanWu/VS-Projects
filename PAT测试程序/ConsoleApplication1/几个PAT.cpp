//#include <iostream>
//#include<string>
//using namespace std;
//
//int main()
//{
//	long long int p,pa,pat;  /*  ������� 0:P,1:A,2:T */
//	string str;
//	int i, j, k;
//	p = pa = pat = 0;
//	cin >> str;
//	for (i = 0; i <str.length() ; i++)  /* ������õ�������ĸ������ */
//	{
//		if (str[i] == 'P')
//			p++;
//		if (str[i] == 'A'){
//			pa += p;
//			pa %= 1000000007;
//		}
//			
//		if (str[i] == 'T'){
//			pat += pa;
//			pat %= 1000000007;
//		}
//			
//	}
//	cout << pat << endl;
//	system("pause");
//	return 0;
//}