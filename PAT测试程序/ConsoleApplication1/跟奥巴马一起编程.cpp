//#include<iostream>
//using namespace std;
//
//int main()
//{
//	int RowNum,ColNum;
//	char C;
//	cin >> RowNum >> C;  /* ����߳�������ַ� */
//
//	if ((RowNum % 2) >= 1)  /* ������� */
//		ColNum = RowNum / 2 + 1;
//	else
//		ColNum = RowNum / 2;
//	for (int i = 0; i < ColNum; i++)
//	{
//		int j;
//		if (i == 0 || i == ColNum-1){
//			for (j = 0; j < RowNum; j++)
//				cout << C;
//			cout << endl;
//		}
//		else{
//			for (j = 0; j < RowNum; j++){
//				if (j == 0 || j == RowNum - 1)
//					cout << C;
//				else
//					cout << " ";
//			}
//			cout << endl;
//		}
//			
//
//	}
//
//	system("pause");
//	return 0;
//}