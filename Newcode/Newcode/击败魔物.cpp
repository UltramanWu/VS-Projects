//#include <iostream>
//#include <vector>
//#include <string>
//#include <stack>
//#include <queue>
//#include <cmath>
//#include <algorithm>
//#include <functional>
//using namespace std;
//
//
//int main()
//{
//	int N, T, M;
//	int X;
//	cin >> N >> T >> M;
//	vector<int> H(N, 0);
//	for (int i = 0; i < N; i++)
//		cin >> H[i];
//
//	sort(H.begin(), H.end(), greater<int>());  /* ��С�������� */
//	int diff = T - M;  /* �������Ĵ��� */
//	while (!H.empty() && diff>0)
//	{
//		if (*(--H.end()) <= diff){
//			diff -= *(--H.end());
//			H.pop_back();
//		}
//		else{
//			for (auto itor = H.begin(); itor != H.end() && diff > 0; itor++){
//				*itor -=1;
//				diff--;
//			}
//			sort(H.begin(), H.end(), greater<int>());
//		}
//	}
//	if (H.empty()){
//		X = 0;
//	}
//	else{
//		if (H.size() < M){
//			int Sum = 0;
//			for (auto itor = H.begin(); itor != H.end(); itor++)
//				Sum += *itor;
//			X = (Sum%M) ? Sum / M + 1 : Sum / M;
//			if (M / H.size()>1){  /* ������������1�� */
//				if (H.size() > 1){
//
//				}
//			}
//			else  /* ֻ�ܹ���һ�� */
//				X = (X > *(--H.end())) ? X : *(--H.end());
//		}
//		else if (H.size() == M){
//			X = *H.begin();
//		}
//		else{
//			X = -1;
//		}
//	}
//	cout << X << endl;
//	system("pause");
//	return 0;
//}