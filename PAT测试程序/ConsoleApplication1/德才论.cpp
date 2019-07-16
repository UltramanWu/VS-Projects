//#include<iostream>
//using namespace std;
//
///* 使用链表进行保存比较方便*/
//struct ScopeNode{
//	char UID[9];  /* 8位考生编号 */
//	int MScope;  /* 德分 */
//	int AScope;  /* 才分 */
//	int TotalScope;  /*总分 */
//	ScopeNode* next;  /* 指针 */
//};
//typedef ScopeNode *Scope;  
//
//struct RankNode{
//	Scope First;  /* 才德全尽 */
//	Scope Second;  /* 德胜才 */
//	Scope Third;  /* 才德兼亡但尚有德胜才者 */
//	Scope Fourth;  /* 普通考生 */
//};
//typedef struct RankNode *Rank;
//
//void Sort(Scope S, Scope NewNode)
//{
//	Scope Start = S;  /* 需要找一个备份 */
//	while (Start->next){  /* 当起始结点的下一结点不为空时 */
//		if (Start->next->TotalScope > NewNode->TotalScope)
//			Start = Start->next;
//		else  if (Start->next->TotalScope == NewNode->TotalScope)  /* 总分相同 */
//		{
//			if (Start->next->MScope > NewNode->MScope)  /* 德分大于 */
//				Start = Start->next;
//			else if (Start->next->MScope == NewNode->MScope){  /* 德分相同 */
//				if (strcmp(Start->next->UID , NewNode->UID) < 0)  /* 准考证号小于 */
//					Start = Start->next;
//				else
//				{
//					NewNode->next = Start->next;
//					Start->next = NewNode;
//					break;
//				}
//			}
//			else
//			{
//				NewNode->next = Start->next;
//				Start->next = NewNode;
//				break;
//			}
//		}
//		else{  /* 当对比较大时 */
//			NewNode->next = Start->next;
//			Start->next = NewNode; 
//			break;
//		}
//	}
//	if (Start->next == NULL)
//		Start->next = NewNode;
//	
//}
//
//
//void Insert_S(Rank R, Scope S,int L,int H)
//{
//	if (S->MScope >= H && S->AScope >= H)
//		Sort(R->First, S);  /* 纳入第一类 */
//	else if (S->MScope >=H)
//		Sort(R->Second, S);  /* 纳入第二类 */
//	else if (S->MScope >= S->AScope)
//		Sort(R->Third, S);  /* 纳入第三类 */	
//	else
//		Sort(R->Fourth, S);  /* 纳入第四类 */
//}
//
//int main()
//{
//	int N, L, H;
//	int UsersCount = 0;
//
//	cin >> N >> L >> H;  /* 获取学生数量，分数标准 */
//	
//	/* 对排行进行初始化 */
//	Rank R = new struct RankNode;
//	R->First = new struct ScopeNode;
//	R->Second = new struct ScopeNode;
//	R->Third = new struct ScopeNode;
//	R->Fourth= new struct ScopeNode;
//
//	R->First->next = NULL;
//	R->Second->next = NULL;
//	R->Third->next = NULL;
//	R->Fourth->next = NULL;
//
//	/* 开始采集数据 */
//	while (N--){
//		Scope NewNode = new struct ScopeNode;
//		NewNode->next = NULL;
//		cin >> NewNode->UID >> NewNode->MScope >> NewNode->AScope;  /* 获取学生成绩 */
//		NewNode->TotalScope = NewNode->AScope + NewNode->MScope;
//		if (NewNode->MScope >= L && NewNode->AScope >= L)
//		{
//			Insert_S(R, NewNode,L,H);
//			UsersCount++;
//		}
//	}
//
//	/* 打印数据 */
//	cout << UsersCount << endl;
//	Scope Temp = R->First->next;
//	while (Temp)
//	{
//		cout << Temp->UID << " " << Temp->MScope << " " << Temp->AScope << endl;
//		Temp = Temp->next;
//	}
//	Temp = R->Second->next;
//	while (Temp)
//	{
//		cout << Temp->UID << " " << Temp->MScope << " " << Temp->AScope << endl;
//		Temp = Temp->next;
//	}
//	Temp = R->Third->next;
//	while (Temp)
//	{
//		cout << Temp->UID << " " << Temp->MScope << " " << Temp->AScope << endl;
//		Temp = Temp->next;
//	}
//
//	Temp = R->Fourth->next;
//	while (Temp)
//	{
//		cout << Temp->UID << " " << Temp->MScope << " " << Temp->AScope << endl;
//		Temp = Temp->next;
//	}
//
//	system("pause");
//	return 0;
//}
//
//#if 0
//链接：https://www.nowcoder.com/questionTerminal/97b6a49a85944650b2e3d0660b91c324
//来源：牛客网
//
//#include <iostream>
//#include <set>
//
//using namespace std;
//
//class Student
//{
//public:
//	int id, morality, ability, sum, level;
//	Student(int id, int morality, int ability) {
//		this->id = id;
//		this->morality = morality;
//		this->ability = ability;
//		this->sum = morality + ability;
//		level = 4;//默认为第4等级，可改
//	}
//	bool operator <(const Student& another)const {
//		if (level != another.level) {
//			return level>another.level;
//		}
//		else if (sum != another.sum) {
//			return another.sum>sum;
//		}
//		else if (morality != another.morality) {
//			return another.morality>morality;
//		}
//		else {
//			return id>another.id;
//		}
//	}
//};
//
//int main()
//{
//	// 基本变量
//	int N, L, H;
//	cin >> N >> L >> H;
//	set<Student> student;
//
//	// 分类划级
//	for (int i = 0; i<N; i++) {
//		int id, morality, ability;
//		cin >> id >> morality >> ability;
//		Student stu(id, morality, ability);
//		if (stu.morality<L || stu.ability<L) {
//			continue;
//		}
//		else if (stu.morality >= H && stu.ability >= H) {
//			stu.level = 1;
//		}
//		else if (stu.morality >= H) {
//			stu.level = 2;
//		}
//		else if (morality >= ability) {
//			stu.level = 3;
//		}
//		else {
//			stu.level = 4;
//		}
//		student.insert(stu);
//	}
//
//	// 输出结果
//	set<Student>::reverse_iterator iter;
//	cout << student.size() << endl;
//	for (iter = student.rbegin(); iter != student.rend(); iter++) {
//		cout << (*iter).id << " " << (*iter).morality << " " << (*iter).ability << endl;
//	}
//	return 0;
//}
//
//#endif