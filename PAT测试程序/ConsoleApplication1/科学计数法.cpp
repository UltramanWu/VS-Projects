//#include<iostream>
//#include <string>
//#include <cstdlib>
//using namespace std;
//
//int main()
//{
//	string str,Exp,Sub_str;
//	int Pos_Flag_Exp;
//	int i,Pos_Point,Pos_E,e;
//	int count = 0;
//
//	cin >> str;  /* �����ַ��� */
//	Pos_Point = str.find('.');  /* ��ȡС�����λ�� */
//	Pos_E = str.find('E');  /* ��ȡ��ʾָ����E��λ�� */
//	Pos_Flag_Exp = Pos_E + 1;  /* ��ȡָ������λ��λ�� */
//	Exp = str.substr(Pos_Flag_Exp+1, str.size()-Pos_Flag_Exp);
//	e = atoi(Exp.c_str());  /* ���ָ����ֵ */
//
//	if (str[Pos_Flag_Exp] == '-'){  /* С������ǰ�ƶ� */
//		if (Pos_Point - 1 >= e) { /* ���С������Ҫ��ǰ�ƶ���λ��û�г���λ��1 */
//			
//			str.erase(Pos_Point, 1);/* ɾ����ǰλ�õ�С���� */
//			str.insert(Pos_Point-e, ".");  /* ��ָ��λ�ò���С���� */
//		}
//		else{ /* ���С������Ҫ��ǰ�ƶ���λ������λ��1 */
//			count = e - (Pos_Point-1);
//			str.erase(Pos_Point, 1);/* ɾ����ǰλ�õ�С���� */
//			str.insert(1, ".");  /* ��ָ��λ�ò���С���� */
//			str.insert(1, "0");  /* ��ָ��λ�ò���С���� */
//			for (i = 0; i < count;i++)
//				str.insert(3,"0");  /* ������ */
//		}
//	}
//	if (str[Pos_Flag_Exp] == '+'){ /* С��������ƶ� */
//		if ((Pos_E - 1) - Pos_Point >= e){
//			str.erase(Pos_Point, 1);/* ɾ����ǰλ�õ�С���� */
//			str.insert(Pos_Point + e, ".");  /* ��ָ��λ�ò���С���� */
//		}
//		else{
//			count = e - ((Pos_E - 1) - Pos_Point);
//			str.erase(Pos_Point, 1);/* ɾ����ǰλ�õ�С���� */
//
//			for (i = 0; i < count; i++)
//				str.insert(Pos_E-1, "0");  /* ������ */
//		}
//	}
//	Pos_E = str.find('E');  /* �ٴζ�λE��λ�� */
//
//	Sub_str = str.substr(1,Pos_E-1);
//	if (str[0] == '-')  /* �����һλΪ���� */
//		cout << "-";
//	cout << Sub_str << endl;
//
//	system("pause");
//	return 0;
//}