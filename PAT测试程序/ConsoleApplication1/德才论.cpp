//#include<iostream>
//using namespace std;
//
///* ʹ��������б���ȽϷ���*/
//struct ScopeNode{
//	char UID[9];  /* 8λ������� */
//	int MScope;  /* �·� */
//	int AScope;  /* �ŷ� */
//	int TotalScope;  /*�ܷ� */
//	ScopeNode* next;  /* ָ�� */
//};
//typedef ScopeNode *Scope;  
//
//struct RankNode{
//	Scope First;  /* �ŵ�ȫ�� */
//	Scope Second;  /* ��ʤ�� */
//	Scope Third;  /* �ŵ¼��������е�ʤ���� */
//	Scope Fourth;  /* ��ͨ���� */
//};
//typedef struct RankNode *Rank;
//
//void Sort(Scope S, Scope NewNode)
//{
//	Scope Start = S;  /* ��Ҫ��һ������ */
//	while (Start->next){  /* ����ʼ������һ��㲻Ϊ��ʱ */
//		if (Start->next->TotalScope > NewNode->TotalScope)
//			Start = Start->next;
//		else  if (Start->next->TotalScope == NewNode->TotalScope)  /* �ܷ���ͬ */
//		{
//			if (Start->next->MScope > NewNode->MScope)  /* �·ִ��� */
//				Start = Start->next;
//			else if (Start->next->MScope == NewNode->MScope){  /* �·���ͬ */
//				if (strcmp(Start->next->UID , NewNode->UID) < 0)  /* ׼��֤��С�� */
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
//		else{  /* ���ԱȽϴ�ʱ */
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
//		Sort(R->First, S);  /* �����һ�� */
//	else if (S->MScope >=H)
//		Sort(R->Second, S);  /* ����ڶ��� */
//	else if (S->MScope >= S->AScope)
//		Sort(R->Third, S);  /* ��������� */	
//	else
//		Sort(R->Fourth, S);  /* ��������� */
//}
//
//int main()
//{
//	int N, L, H;
//	int UsersCount = 0;
//
//	cin >> N >> L >> H;  /* ��ȡѧ��������������׼ */
//	
//	/* �����н��г�ʼ�� */
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
//	/* ��ʼ�ɼ����� */
//	while (N--){
//		Scope NewNode = new struct ScopeNode;
//		NewNode->next = NULL;
//		cin >> NewNode->UID >> NewNode->MScope >> NewNode->AScope;  /* ��ȡѧ���ɼ� */
//		NewNode->TotalScope = NewNode->AScope + NewNode->MScope;
//		if (NewNode->MScope >= L && NewNode->AScope >= L)
//		{
//			Insert_S(R, NewNode,L,H);
//			UsersCount++;
//		}
//	}
//
//	/* ��ӡ���� */
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
//���ӣ�https://www.nowcoder.com/questionTerminal/97b6a49a85944650b2e3d0660b91c324
//��Դ��ţ����
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
//		level = 4;//Ĭ��Ϊ��4�ȼ����ɸ�
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
//	// ��������
//	int N, L, H;
//	cin >> N >> L >> H;
//	set<Student> student;
//
//	// ���໮��
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
//	// ������
//	set<Student>::reverse_iterator iter;
//	cout << student.size() << endl;
//	for (iter = student.rbegin(); iter != student.rend(); iter++) {
//		cout << (*iter).id << " " << (*iter).morality << " " << (*iter).ability << endl;
//	}
//	return 0;
//}
//
//#endif