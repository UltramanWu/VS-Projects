//#include <iostream>
//#include <vector>
//#include <string>
//#include <algorithm>
//using namespace std;
//
//int lengthOfLastWord(string s);
//int main()
//{
//	string s = "Hello ";
//	int count = lengthOfLastWord(s);
//	system("pause");
//	return 0;
//}
//
//int lengthOfLastWord(string s) {
//	int len = s.size();
//	if (len == 0)
//		return 0;
//	int count = 0;
//	/* 去除尾部多余的空格*/
//	int n = s.find_last_not_of(" ");
//	s.erase(n + 1);  
//	for (int i = len - 1; i >= 0; i--)
//	{
//		if (s[i] == ' ')
//			break;
//		count++;
//	}
//	return count;
//}