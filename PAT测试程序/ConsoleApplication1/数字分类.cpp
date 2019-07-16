//#include <iostream>
//#include <iomanip>
//using namespace std;
//
//int main()
//{
//	int N,item;
//	int Cross_Count = 0;
//	int Count = 0;
//	int Average_Count = 0;
//	int Sum, Cross_Sum, Average_Sum, Max;
//	float Average;
//	Sum = Cross_Sum = Average_Sum = Max = 0;
//
//	cin >> N;
//	while (N--)
//	{
//		cin >> item;
//		if (item % 5 == 0 && item % 2 == 0){  /* 余0 */
//			Sum += item;
//		}
//
//		if (item % 5 == 1){  /* 余1 */
//			if (Cross_Count % 2 == 0)  /* 当为偶数时 */
//				Cross_Sum += item;
//			else  /* 当为奇数时 */
//				Cross_Sum -= item;
//			Cross_Count++;
//		}
//		if (item % 5 == 2){   /* 获取个数 */
//			Count++;
//		}
//		if (item % 5 == 3){  /* 获取平均数 */
//			Average_Sum += item;
//			Average_Count++;
//		}
//		if (item % 5 == 4){  /* 获取最大值 */
//			if (item > Max)
//				Max = item;
//		}
//	}
//	Average = (float)Average_Sum / (float)Average_Count;
//
//	if (Sum == 0)
//		cout << "N" << " ";
//	else
//		cout << Sum << " ";
//	if (Cross_Count == 0)
//		cout << "N" << " ";
//	else
//		cout << Cross_Sum << " ";
//	if (Count == 0)
//		cout << "N" << " ";
//	else
//		cout << Count << " ";
//	if (Average_Count == 0)
//		cout << "N" << " ";
//	else
//		cout << fixed << setprecision(1) << Average << " ";
//	if (Max == 0)
//		cout << "N" << endl;
//	else
//		cout << Max << endl;
//
//
//	/*cout << Sum << " "
//		<< Cross_Sum << " "
//		<< Count << " "
//		<< fixed << setprecision(1) << Average << " "
//		<< Max << endl;*/
//
//	system("pause");
//	return 0;
//}