//#include<iostream>
//#include <string>
//#include <sstream>
//using namespace std;
//
//long long  g(int x, int y)/* �����Լ�� */
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
//string getProperFraction(long long num, long long den)   /* Լ�ֲ������ַ��� */
//{
//	/* �����߽磬�������� */
//	if (den == 0)  /* �����ĸΪ�� */
//		return "Inf";
//	if (num == 0)  /* ������Ӵ�ʱΪ�㣬ֱ�ӷ����� */
//		return "0";
//	bool isMinus = false;
//	string str = "";
//	if (num * den < 0){  /* ��ʾ�÷���Ϊ���� */
//		isMinus = true;
//		num = abs(num);
//		den = abs(den);
//	}
//
//	/* Լ�� */
//	long long gcd = g(num, den);
//	num /= gcd; den /= gcd;
//
//	string inPart, numPart,denPart;
//	stringstream s; s << (num / den);  /* ��üٷ���ϵ�� */
//	s >> inPart;
//	stringstream s1; s1 << (num%den);  /* ������������ */
//	s1 >> numPart;
//	stringstream s2; s2 << den;
//	s2 >> denPart;
//	
//
//
//	if (num / den > 0){  /* ����ٷ����������� */
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
//	if (isMinus)  /* ���Ϊ���� */
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
//	int Fri_num, Fri_den, Sec_num, Sec_den;  /* ���ӷ�ĸ */
//	int Sum_num, Sum_den, Cut_num, Cut_den, Multi_num, Multi_den, Del_num, Del_den;
//	cin >> Fri_Sub >> Sec_Sub;
//
//	/* �Ե�һ���ַ������д��� */
//	Pos_Slash = Fri_Sub.find('/');  /* ��ȡб�ܵ�λ�� */
//	Fri_num = atoi(Fri_Sub.substr(0, Pos_Slash).c_str());
//	Fri_den = atoi(Fri_Sub.substr(Pos_Slash + 1).c_str());
//
//
//	/* �Եڶ����ַ������д��� */
//	Pos_Slash = Sec_Sub.find('/');  /* ��ȡб�ܺͿո��λ�� */
//	Sec_num = atoi(Sec_Sub.substr(0, Pos_Slash).c_str());
//	Sec_den = atoi(Sec_Sub.substr(Pos_Slash + 1).c_str());
//
//
//
//
//	/* �ӷ����� */
//	Sum_num = Fri_num*Sec_den +Sec_num*Fri_den;
//	Sum_den = Fri_den * Sec_den;
//
//	/* �������� */
//	Cut_num =Fri_num*Sec_den - Sec_num*Fri_den;
//	Cut_den = Sum_den;
//
//	/* �˷����� */
//	Multi_num = Fri_num *  Sec_num;
//	Multi_den = Sum_den;
//
//	/* �������� */
//	Del_num =Fri_num * Sec_den;
//	Del_den = Fri_den * Sec_num;
//
//
//	/* ��ȡ���������ļٷ��� */
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