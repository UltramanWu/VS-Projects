//#include <iostream>
//#include <string>
//using namespace std;
//
//int main()
//{
//	string Theory, Reality;
//	char *Record;
//	char Diff;
//	int i, j,k,Tmp;  /* �ֱ��Ӧ�����ַ�����λ�� */
//	i = j = 0;
//	Tmp = k = 0;
//	cin >> Theory;
//	cin >> Reality;
//	Record = new char[Theory.size()];
//	for (k = 0; k < Theory.size(); k++)  /* �Ա������н��г�ʼ�� */
//		Record[k] = '\0';
//
//	while (i<Theory.size() && j<Reality.size())  /* �����߾�����Ч��Χ��ʱ */
//	{
//		if (Theory[i] == Reality[j]){  /* ���������ͬ */
//			i++; j++;
//		}
//		else{  /* ������߲�ͬʱ������ͬ�ߴ��� */
//			Diff = Theory[i];
//			for (k = 0; k < Tmp; k++)
//			{
//				if (Diff == Record[k] || Diff == (Record[k] - 'A' + 'a') || Diff == (Record[k] - 'a' + 'A'))  /* ��Сд����Ŷ�Ӧ */
//					break;
//			}
//			if (k >= Tmp)  /* ��ǰ������û�ж�ӦԪ��ʱ */
//			{
//				if (Theory[i] >= 'a' && Theory[i] <= 'z')  /* ��Ӣ����ĸΪСдʱ */
//					Record[Tmp++] = Theory[i++]-'a'+'A';
//				else
//					Record[Tmp++] = Theory[i++];
//			}
//			else 
//				i++;
//		}
//	}
//	while (i < Theory.size()){  /* ���ڶ����ַ��������� */
//		Diff = Theory[i];
//		for (k = 0; k < Tmp; k++)
//		{
//			if (Diff == Record[k] || Diff == (Record[k] - 'A' + 'a') || Diff == (Record[k] - 'a' + 'A'))  /* ��Сд����Ŷ�Ӧ */
//				break;
//		}
//		if (k >= Tmp)  /* ��ǰ������û�ж�ӦԪ��ʱ */
//		{
//			if (Theory[i] >= 'a' && Theory[i] <= 'z')  /* ��Ӣ����ĸΪСдʱ */
//				Record[Tmp++] = Theory[i++] - 'a' + 'A';
//			else
//				Record[Tmp++] = Theory[i++];
//		}
//		else
//			i++;
//	}
//
//	for (k = 0; Record[k] != '\0'; k++)
//		cout << Record[k];
//	cout << endl;
//
//	system("pause");
//	return 0;
//}