//#include <iostream>
//#include<string>
//#include <iomanip>
//using namespace std;
//
//int main()
//{
//	string  frist, second, third, fourth;
//	const string str[7] = { "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN" };
//	int i, j, flag, flag1, flag2, count;
//	char F[2];
//	int Same_third;  /* ��������ͬ�ַ���λ�� */
//	flag = flag1 = flag2 = count = 0;
//	cin >> frist >> second >> third >> fourth;  /* �����ĸ��ַ��� */
//
//	for (j = 0; j < second.size(); j++){
//		if ((second[j] >= 'A'&&second[j] <= 'Z') || (second[j] >= '0'&&second[j] <= '9')){
//			for (i = 0; i < frist.size(); i++){
//				if (frist[i] >= 'A'&&frist[i] <= 'Z'&&!flag) /* ���ڷ�Χ�� */
//				{
//					if (second[j] == frist[i]){  /* ���ַ�������¼ */
//						F[0] = second[j];
//						flag = 1;
//						break;
//					}
//				}
//
//				if (flag == 1 && flag1 == 0 && count == 0)  /* ������ǰ���� */
//				{
//					flag1 = 1;
//					count++;
//					continue;
//				}
//
//				if (((frist[i] >= 'A'&&frist[i] <= 'N') || (frist[i] >= '0'&&frist[i] <= '9')) && flag && flag1)
//				{
//					if (second[j] == frist[i]){  /* ���ַ�������¼ */
//						F[1] = second[j];
//						flag1 = 0;
//						break;
//					}
//				}
//
//			}
//		}
//			
//	}
//
//	for (i = 0; i < third.size()&&!flag2; i++){
//		if (third[i] >= 'a'&&third[i] <= 'z'){
//			for (j = 0; j < fourth.size(); j++)
//				if (fourth[j] == third[i]){
//					Same_third = j;
//					flag2 = 1;
//				}
//						
//		}
//	}
//
//	cout << str[F[0] - 'A'] << " ";
//	if (F[1]>='A'&&F[1]<='Z')
//		cout << setw(2)<< setfill('0')<< F[1]-'A'+10<< ":";
//	else
//		cout << setw(2) << setfill('0') << F[1] - '0' << ":";
//	cout << setw(2) << setfill('0') << Same_third << endl;
//	system("pause");
//	return 0;
//}