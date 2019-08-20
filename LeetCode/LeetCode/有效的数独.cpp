//#include <iostream>
//#include <vector>
//#include <string>
//#include <stack>
//#include <queue>
//#include <cmath>
//#include <unordered_map>
//#include <unordered_set>
//#include <algorithm>
//using namespace std;
//
//
//int main()
//{
//
//	system("pause");
//	return 0;
//}
//
//bool isValidSudoku(vector<vector<char>>& board) {
//	vector<unordered_set<int>> row(9), col(9), block(9);
//	for (int i = 0; i < 9; i++)
//		for (int j = 0; j < 9; j++){
//			int bindex = (i / 3) * 3 + j / 3;
//			char cur = board[i][j];
//			if (cur == '.') continue;
//			if (row[i].count(cur) || col[j].count[cur] || block[bindex].count(cur)) return false;
//			row[i].insert(cur);
//			col[j].insert(cur);
//			block[bindex].insert(cur);
//		}
//	return true;
//}
//
//bool isValidSudoku(vector<vector<char>>& board) {
//	vector<unordered_map<int, char>> row(9), col(9), block(9);
//	for (int i = 0; i < 9; i++)
//		for (int j = 0; j < 9; j++){
//			int bindex = (i / 3) * 3 + j / 3;
//			char cur = board[i][j];
//			if (cur == '.') continue;
//			if (row[i].count(cur) || col[j].count(cur) || block[bindex].count(cur)) return false;
//			row[i][cur] = 1;
//			col[j][cur] = 1;
//			block[bindex][cur] = 1;
//		}
//	return true;
//}