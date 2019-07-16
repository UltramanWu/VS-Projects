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
//	cin >> str;  /* 读入字符串 */
//	Pos_Point = str.find('.');  /* 获取小数点的位置 */
//	Pos_E = str.find('E');  /* 获取表示指数的E的位置 */
//	Pos_Flag_Exp = Pos_E + 1;  /* 获取指数符号位的位置 */
//	Exp = str.substr(Pos_Flag_Exp+1, str.size()-Pos_Flag_Exp);
//	e = atoi(Exp.c_str());  /* 获得指数数值 */
//
//	if (str[Pos_Flag_Exp] == '-'){  /* 小数点向前移动 */
//		if (Pos_Point - 1 >= e) { /* 如果小数点需要向前移动的位数没有超过位置1 */
//			
//			str.erase(Pos_Point, 1);/* 删除当前位置的小数点 */
//			str.insert(Pos_Point-e, ".");  /* 在指定位置插入小数点 */
//		}
//		else{ /* 如果小数点需要向前移动的位数超过位置1 */
//			count = e - (Pos_Point-1);
//			str.erase(Pos_Point, 1);/* 删除当前位置的小数点 */
//			str.insert(1, ".");  /* 在指定位置插入小数点 */
//			str.insert(1, "0");  /* 在指定位置插入小数点 */
//			for (i = 0; i < count;i++)
//				str.insert(3,"0");  /* 补充零 */
//		}
//	}
//	if (str[Pos_Flag_Exp] == '+'){ /* 小数点向后移动 */
//		if ((Pos_E - 1) - Pos_Point >= e){
//			str.erase(Pos_Point, 1);/* 删除当前位置的小数点 */
//			str.insert(Pos_Point + e, ".");  /* 在指定位置插入小数点 */
//		}
//		else{
//			count = e - ((Pos_E - 1) - Pos_Point);
//			str.erase(Pos_Point, 1);/* 删除当前位置的小数点 */
//
//			for (i = 0; i < count; i++)
//				str.insert(Pos_E-1, "0");  /* 补充零 */
//		}
//	}
//	Pos_E = str.find('E');  /* 再次定位E的位置 */
//
//	Sub_str = str.substr(1,Pos_E-1);
//	if (str[0] == '-')  /* 如果第一位为负号 */
//		cout << "-";
//	cout << Sub_str << endl;
//
//	system("pause");
//	return 0;
//}