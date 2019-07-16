//#include<iostream>
//using namespace std;
//
//void Compare(char L, char R,int Compare[],int Result[])
//{
//	if (L == R){
//		Result[1]++;
//	}
//		
//	if (L == 'C' && R == 'J'){
//		Result[0]++;
//		Compare[1]++;
//	}
//	
//	if (L == 'C' && R == 'B'){
//		Result[2]++;
//		Compare[3]++;
//	}
//
//	if (L == 'J' && R == 'C'){
//		Result[2]++;
//		Compare[4]++;
//	}
//
//	if (L == 'J' && R == 'B'){
//		Result[0]++;
//		Compare[2]++;
//	}
//
//	if (L == 'B' && R == 'C'){
//		Result[0]++;
//		Compare[0]++;
//	}
//
//	if (L == 'B' && R == 'J'){
//		Result[2]++;
//		Compare[5]++;
//	}
//}
//
//void Out(int i,  char* Out){
//	if (i == 0)
//		*Out = 'B';
//	if (i == 1)
//		*Out = 'C';
//	if (i == 2)
//		*Out = 'J';
//}
//
//int main()
//{
//	int Compared[6] = {0,0,0,0,0,0};  /* 存储两者的结果 */
//	int Result[3] = {0,0,0};  /* 0:win  1: equal  2:lost */
//	char Outed[2] = { '\0', '\0' };
//	char L, R;
//	int N;
//	cin >> N;
//	while (N--)
//	{
//		cin >> L >> R;
//		Compare(L, R,Compared,Result);
//	}
//	int MaxV1 = -1;
//	int MaxV2 = -1;
//	int Max1 = -1;
//	int Max2 = -1;
//	for (int j = 0; j < 3; j++)
//	{
//		if (Max1 < Compared[j])
//		{
//			Max1 = Compared[j];
//			MaxV1 = j;
//		}
//	}
//	for (int j = 3; j < 6; j++)
//	{
//		if (Max2 < Compared[j])
//		{
//			Max2 = Compared[j];
//			MaxV2 = j;
//		}
//	}
//	Out(MaxV1, &Outed[0]);
//	Out(MaxV2-3, &Outed[1]);
//
//	for (int i = 0; i < 3; i++){
//		if (i > 0)
//			cout << " ";
//		cout << Result[i];
//	}
//	cout <<endl;
//	
//	for (int i = 2; i >= 0; i--){
//		if (i <2)
//			cout << " ";
//		cout << Result[i];
//	}
//	cout << endl;
//
//	cout << Outed[0] << " " << Outed[1] << endl;
//
//	system("pause");
//	return 0;
//}