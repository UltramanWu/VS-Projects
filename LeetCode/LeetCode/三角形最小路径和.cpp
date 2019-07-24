//#include <iostream>
//#include <vector>
//#include <string>
//#include <algorithm>
//using namespace std;
//
//int minimumTotal(vector<vector<int>>& triangle);
//int main()
//{
//	//vector<vector<int>> tri = { { 2 }, { 3, 4 }, { 6, 5, 7 }, { 4, 1, 8, 3 } };
//	vector<vector<int>> tri = { { -1 }, { 2,3 }, { 1,-1,-3 }};
//	int Sum = minimumTotal(tri);
//
//	system("pause");
//	return 0;
//}
//
//
//int minimumTotal(vector<vector<int>>& triangle) {
//	int n = triangle.size();
//	vector<int> line(triangle[n - 1]);
//	for (int i = n - 2; i >= 0; i--)
//		for (int j = 0; j <= i; j++)
//			line[j] = triangle[i][j] + min(line[j], line[j + 1]);
//	return line[0];
//}
