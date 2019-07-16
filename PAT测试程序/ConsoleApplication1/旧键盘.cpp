//#include <iostream>
//#include <string>
//using namespace std;
//
//int main()
//{
//	string Theory, Reality;
//	char *Record;
//	char Diff;
//	int i, j,k,Tmp;  /* 分别对应两个字符串的位置 */
//	i = j = 0;
//	Tmp = k = 0;
//	cin >> Theory;
//	cin >> Reality;
//	Record = new char[Theory.size()];
//	for (k = 0; k < Theory.size(); k++)  /* 对保存序列进行初始化 */
//		Record[k] = '\0';
//
//	while (i<Theory.size() && j<Reality.size())  /* 当两者均在有效范围内时 */
//	{
//		if (Theory[i] == Reality[j]){  /* 如果两者相同 */
//			i++; j++;
//		}
//		else{  /* 如果两者不同时，将不同者存入 */
//			Diff = Theory[i];
//			for (k = 0; k < Tmp; k++)
//			{
//				if (Diff == Record[k] || Diff == (Record[k] - 'A' + 'a') || Diff == (Record[k] - 'a' + 'A'))  /* 大小写或符号对应 */
//					break;
//			}
//			if (k >= Tmp)  /* 当前数组中没有对应元素时 */
//			{
//				if (Theory[i] >= 'a' && Theory[i] <= 'z')  /* 当英文字母为小写时 */
//					Record[Tmp++] = Theory[i++]-'a'+'A';
//				else
//					Record[Tmp++] = Theory[i++];
//			}
//			else 
//				i++;
//		}
//	}
//	while (i < Theory.size()){  /* 当第二个字符串结束后 */
//		Diff = Theory[i];
//		for (k = 0; k < Tmp; k++)
//		{
//			if (Diff == Record[k] || Diff == (Record[k] - 'A' + 'a') || Diff == (Record[k] - 'a' + 'A'))  /* 大小写或符号对应 */
//				break;
//		}
//		if (k >= Tmp)  /* 当前数组中没有对应元素时 */
//		{
//			if (Theory[i] >= 'a' && Theory[i] <= 'z')  /* 当英文字母为小写时 */
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