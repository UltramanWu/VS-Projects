//#include <iostream>
//#include <vector>
//#include <string>
//#include <algorithm>
//using namespace std;
//
//string addBinary(string a, string b);
//int main()
//{
//	string lhs = "11";
//	string rhs = "1";
//	string S = addBinary(lhs, rhs);
//
//	system("pause");
//	return 0;
//}
//
//
///* �ַ����Ķ�������� */
//string addBinary(string a, string b) {
//	int lena = a.size();
//	int lenb = b.size();
//	/* ͨ���Ƚϸ��ַ����ĳ��� */
//	if (lena == 0)
//		return b;
//	if (lenb == 0)
//		return a;
//	string Sum;
//	int multi_sum;
//	int i = lena - 1;
//	int j = lenb - 1;
//	int carry = 0;
//	while (i >= 0 && j >= 0){
//		multi_sum = carry + a[i] - '0' + b[j] - '0';
//		if (multi_sum / 2){  /* ������ֽ�λ��ʱ�� */
//			Sum.insert(Sum.begin(), multi_sum % 2 + '0');
//			carry = 1;
//		}	
//		else{
//			Sum.insert(Sum.begin(), multi_sum + '0');
//			carry = 0;
//		}
//			i--; j--;
//	}
//	/* ���ڵ����ַ������в��� */
//	while (i>=0){
//		multi_sum = carry + a[i] - '0';
//		if (multi_sum / 2){  /* ������ֽ�λ��ʱ�� */
//			Sum.insert(Sum.begin(), multi_sum % 2 + '0');
//			carry = 1;
//		}
//		else{
//			Sum.insert(Sum.begin(), multi_sum + '0');
//			carry = 0;
//		}
//		i--;
//	}
//	while (j>=0){
//		multi_sum = carry + b[j] - '0';
//		if (multi_sum / 2){  /* ������ֽ�λ��ʱ�� */
//			Sum.insert(Sum.begin(), multi_sum % 2 + '0');
//			carry = 1;
//		}
//		else{
//			Sum.insert(Sum.begin(), multi_sum + '0');
//			carry = 0;
//		}
//		j--;
//	}
//	if (carry){
//		Sum.insert(Sum.begin(), carry + '0');
//	}
//	return Sum;
//}