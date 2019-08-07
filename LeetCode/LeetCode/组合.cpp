//#include <iostream>
//#include <vector>
//#include <string>
//#include <stack>
//#include <queue>
//#include <cmath>
//#include <algorithm>
//using namespace std;
//
//vector<vector<int>> combine(int n, int k);
//int main()
//{
//	vector<vector<int>> Re = combine(6, 2);
//	system("pause");
//	return 0;
//}
//
//
//
//
///* 使用队列实现 */
//vector<vector<int>> combine(int n, int k) {
//	queue<vector<int>> Queue;
//	vector<vector<int>> Save;
//	int size = 0;
//	vector<int> Tmp;
//	vector<int> Tmp1;
//	/* 先将第一部分加入到数据中 */
//	for (int i = 1; i <= n - k+1; i++){
//		Queue.push(vector<int>(1,i));
//	}
//	size++;
//	while (!Queue.empty() && size <k){
//		int len = Queue.size();
//		for (int i = 0; i < len; i++){
//			Tmp = Queue.front();
//			Queue.pop();
//			for (int j = Tmp.back()+1; j <= n;j++){
//				Tmp1 = Tmp;
//				Tmp1.push_back(j);
//				Queue.push(Tmp1);
//			}
//		}
//		size++;
//	}
//	/* 队列向二维数组转换 */
//	while (!Queue.empty()){
//		Tmp = Queue.front();
//		Queue.pop();
//		Save.push_back(Tmp);
//	}
//	return Save;
//}
//
//
//vector<vector<int>> combine(int n, int k){
//	vector<int> Source;
//	int j = 0;
//	vector<vector<int>> Save;
//	for (int i = 1; i <= k; i++)
//		Source.push_back(i);
//	Source.push_back(n + 1);  /* 作为哨兵 */
//
//
//	while (j < k){
//		/* 截取部分vector */
//		vector<int> CutOut(Source.begin(), Source.begin() + k);
//		/* 加入到二维容器 */
//		Save.push_back(CutOut);
//		/* 对数组进行更改 */
//		j = 0;
//		while (j < k && Source[j + 1] == Source[j] + 1){
//			Source[j] = j + 1;
//			j++;
//		}
//		Source[j] += 1;
//	}
//	return Save;
//}