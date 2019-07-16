//#include<iostream>
//#include <string>
//#include <sstream>
//using namespace std;
//
//long long  g(int x, int y)/* 求最大公约数 */
//{
//	int r;
//	while (y > 0)
//	{
//		r = x%y;
//		x = y;
//		y = r;
//	}
//	return x;
//}
//
//string getProperFraction(long long num, long long den)   /* 约分并生成字符串 */
//{
//	/* 基本边界，基本变量 */
//	if (den == 0)  /* 如果分母为零 */
//		return "Inf";
//	if (num == 0)  /* 如果分子此时为零，直接返回零 */
//		return "0";
//	bool isMinus = false;
//	string str = "";
//	if (num * den < 0){  /* 表示该分数为负数 */
//		isMinus = true;
//		num = abs(num);
//		den = abs(den);
//	}
//
//	/* 约分 */
//	long long gcd = g(num, den);
//	num /= gcd; den /= gcd;
//
//	string inPart, numPart,denPart;
//	stringstream s; s << (num / den);  /* 求得假分数系数 */
//	s >> inPart;
//	stringstream s1; s1 << (num%den);  /* 求得真分数分子 */
//	s1 >> numPart;
//	stringstream s2; s2 << den;
//	s2 >> denPart;
//	
//
//
//	if (num / den > 0){  /* 如果假分数分数存在 */
//		str += inPart;
//		if (num%den > 0)
//			str += " ";
//	}
//
//	if (num%den > 0)
//	{
//		
//		str += numPart;
//		str += "/";
//		str += denPart;
//	}
//
//	if (isMinus)  /* 如果为负数 */
//	{
//		str.insert(0,"-");
//		str.insert(0,"(");
//		str.append(")");
//	}
//	return str;
//}
//
//int main()
//{
//	int Pos_Slash;
//	string Fri_Sub,Sec_Sub;
//	string Fri, Sec;
//	string Sum, Cut, Multi, Del;
//
//	int Fri_num, Fri_den, Sec_num, Sec_den;  /* 分子分母 */
//	int Sum_num, Sum_den, Cut_num, Cut_den, Multi_num, Multi_den, Del_num, Del_den;
//	cin >> Fri_Sub >> Sec_Sub;
//
//	/* 对第一个字符串进行处理 */
//	Pos_Slash = Fri_Sub.find('/');  /* 获取斜杠的位置 */
//	Fri_num = atoi(Fri_Sub.substr(0, Pos_Slash).c_str());
//	Fri_den = atoi(Fri_Sub.substr(Pos_Slash + 1).c_str());
//
//
//	/* 对第二个字符串进行处理 */
//	Pos_Slash = Sec_Sub.find('/');  /* 获取斜杠和空格的位置 */
//	Sec_num = atoi(Sec_Sub.substr(0, Pos_Slash).c_str());
//	Sec_den = atoi(Sec_Sub.substr(Pos_Slash + 1).c_str());
//
//
//
//
//	/* 加法运算 */
//	Sum_num = Fri_num*Sec_den +Sec_num*Fri_den;
//	Sum_den = Fri_den * Sec_den;
//
//	/* 减法运算 */
//	Cut_num =Fri_num*Sec_den - Sec_num*Fri_den;
//	Cut_den = Sum_den;
//
//	/* 乘法运算 */
//	Multi_num = Fri_num *  Sec_num;
//	Multi_den = Sum_den;
//
//	/* 除法运算 */
//	Del_num =Fri_num * Sec_den;
//	Del_den = Fri_den * Sec_num;
//
//
//	/* 获取各个分数的假分数 */
//	Fri = getProperFraction(Fri_num, Fri_den);
//	Sec = getProperFraction(Sec_num, Sec_den);
//	Sum = getProperFraction(Sum_num, Sum_den);
//	Cut = getProperFraction(Cut_num, Cut_den);
//	Multi = getProperFraction(Multi_num, Multi_den);
//	Del = getProperFraction(Del_num, Del_den);
//
//	cout << Fri << " " << "+" << " " << Sec << " " << "=" << " " << Sum << endl;
//	cout << Fri << " " << "-" << " " << Sec << " " << "=" << " " << Cut << endl;
//	cout << Fri << " " << "*" << " " << Sec << " " << "=" << " " << Multi << endl;
//	cout << Fri << " " << "/" << " " << Sec << " " << "=" << " " << Del << endl;
//	
//	system("pause");
//	return 0;
//}