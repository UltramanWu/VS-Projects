#include <iostream>
#include <string>
#include<sstream>
using namespace  std;

int  main()
{
	bool Minus = false;
	string P, A;   /* Ӧ���۸��ʵ���۸���������ַ��� */
	int  P1, P2, P3, A1, A2, A3;
	long long p, a,r;  /* �ָ�õ����Ӵ� */
	int R1, R2, R3;
	int p1, p2, a1, a2;  /* ��ȡ�ַ���λ�� */
	cin >> P >> A;
	/* �����Ӵ��ָ����������� */
	a1 = A.find_first_of(".");
	a2 = A.find_last_of(".");
	A1 = atoi(A.substr(0, a1).c_str());
	A2 = atoi(A.substr(a1 + 1, a2).c_str());
	A3 = atoi(A.substr(a2 + 1).c_str());

	p1 = P.find_first_of(".");
	p2 = P.find_last_of(".");
	P1 = atoi(P.substr(0, p1).c_str());
	P2 = atoi(P.substr(p1 + 1, p2).c_str());
	P3 = atoi(P.substr(p2 + 1).c_str());

	

	
	r = (A1-P1)*29*17 +(A2-P2)*29+(A3-P3);  /* ���ʣ���Ǯ */

	if (r < 0){
		Minus = true;
		r = abs(r);
	}

	R1 = r / (29*17);
	r %= (29*17);
	R2 = r / 29;
	r %= 29;
	R3 = r;

	if (Minus)
		cout << "-";
	cout << R1 << "." << R2 << "." << R3 << endl;

	system("pause");
	return 0;
}