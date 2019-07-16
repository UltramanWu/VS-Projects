//#include<iostream>
//using namespace std;
//
//typedef struct PolyNode* Polynomial;
//struct PolyNode
//{
//	int Data; /* ������ */
//	int Expo; /* ָ���� */
//	Polynomial next; /* ָ����һ�ڵ��ָ�� */
//};
//
//Polynomial CreatePoly()
//{
//	/* ����һ���ս����ڲ����ɾ�� */
//	Polynomial Poly = new struct PolyNode;
//	Poly->next = NULL;
//
//	return Poly;
//}
//
///* ������ */
//void InsertPolyNode(Polynomial Poly, int Data, int Expo)
//{
//	Polynomial NewPolyNode = new struct PolyNode;
//	NewPolyNode->Data = Data;
//	NewPolyNode->Expo = Expo;
//
//	/* ���������� */
//	NewPolyNode->next = NULL;
//	Poly->next = NewPolyNode;
//}
//
///* ������ʽ��� */
//Polynomial AddPoly(Polynomial P1, Polynomial P2)
//{
//	Polynomial Temp, Zero;
//	Polynomial NewPolyNode = new struct PolyNode;
//	NewPolyNode->next = NULL;
//	Zero = NewPolyNode;
//	
//
//	if ((P1 || P2) == 0)  /* �����������ʽ�������ڣ�ֱ���˳� */
//		return false;
//	while (P1 && P2)
//	{
//		Polynomial AddPolyNode = new struct PolyNode;
//
//		if (P1->Expo > P2->Expo){
//			AddPolyNode->Data = P1->Data;
//			AddPolyNode->Expo = P1->Expo;
//			AddPolyNode->next = NULL;
//			/* �����㲢���� */
//			Zero->next = AddPolyNode;
//			Zero = AddPolyNode;
//			P1 = P1->next;
//		}
//		else if (P1->Expo < P2->Expo)
//		{
//			AddPolyNode->Data = P2->Data;
//			AddPolyNode->Expo = P2->Expo;
//			AddPolyNode->next = NULL;
//			/* �����㲢���� */
//			Zero->next = AddPolyNode;
//			Zero = AddPolyNode;
//			P2 = P2->next;
//		}
//		else
//		{
//			AddPolyNode->Data = P1->Data + P2->Data;
//			AddPolyNode->Expo = P1->Expo;
//			AddPolyNode->next = NULL;
//			/* �����㲢���� */
//			Zero->next = AddPolyNode;
//			Zero = AddPolyNode;
//			/* ������ */
//			P1 = P1->next;
//			P2 = P2->next;
//		}
//
//	}
//	while (P1)
//	{
//		Polynomial AddPolyNode = new struct PolyNode;
//		AddPolyNode->Data = P1->Data;
//		AddPolyNode->Expo = P1->Expo;
//		AddPolyNode->next = NULL;
//		/* �����㲢���� */
//		Zero->next = AddPolyNode;
//		Zero = AddPolyNode;
//		P1 = P1->next;
//	}
//	while (P2)
//	{
//		Polynomial AddPolyNode = new struct PolyNode;
//		AddPolyNode->Data = P2->Data;
//		AddPolyNode->Expo = P2->Expo;
//		AddPolyNode->next = NULL;
//		/* �����㲢���� */
//		Zero->next = AddPolyNode;
//		Zero = AddPolyNode;
//		P2 = P2->next;
//	}
//	/* �ͷŵ�ͷ��� */
//	Temp = NewPolyNode; NewPolyNode = NewPolyNode->next; delete(Temp);
//
//	return NewPolyNode;
//}
//
///* ������ʽ��� */
//Polynomial MultiPoly(Polynomial P1, Polynomial P2)
//{
//	Polynomial Temp, Zero, Head;
//	Polynomial MultiPoly = new struct PolyNode;
//	int flag = 0;
//	Head = MultiPoly;
//	Zero = P2;  /* ��¼P2��ͷ��� */
//	if (!P1 && !P2) /* �����������ʽ��������һ������ʽΪ�����޷�������һ������ */
//		return false;
//	if (P1){
//		while (P2){
//			Polynomial MultiPolyNode = new struct PolyNode;
//			MultiPolyNode->Data = P1->Data * P2->Data; /* ������� */
//			MultiPolyNode->Expo = P1->Expo + P2->Expo; /* ָ����� */
//			MultiPolyNode->next = NULL;
//			/* �����㲢���� */
//			Head->next = MultiPolyNode;
//			Head = MultiPolyNode;
//			P2 = P2->next;
//		}
//
//		P1 = P1->next;  /*��P1�ƶ�����һ��� */
//		while (P1){
//			P2 = Zero;  /* ��P2�ƶ���ͷ��� */
//			Head = MultiPoly;  /* ��Head�ƶ���ͷ��� */
//			while (P2){
//				flag = 0;  /* �Ա�־λ���г�ʼ�� */
//				Polynomial MultiPolyNode = new struct PolyNode;
//				MultiPolyNode->Data = P1->Data * P2->Data; /* ������� */
//				MultiPolyNode->Expo = P1->Expo + P2->Expo; /* ָ����� */
//				//MultiPolyNode->next = NULL;
//				while (flag == 0)
//				{
//					if ((Head->next != NULL)&&(MultiPolyNode->Expo > Head->next->Expo)){
//						MultiPolyNode->next = Head->next;
//						Head->next = MultiPolyNode;
//						flag = 1;
//					}
//					else if ((Head->next != NULL)&&(MultiPolyNode->Expo == Head->next->Expo)){
//						Polynomial DelPolyNode = Head->next;
//						MultiPolyNode->Data += DelPolyNode->Data;
//						if (MultiPolyNode->Data == 0){
//							Head->next = DelPolyNode->next;
//							delete(DelPolyNode);/* ����ֵ����ɾ�� */
//						}
//
//						else{
//							/* ɾ���ô����ֵ */
//							MultiPolyNode->next = DelPolyNode->next;
//							Head->next = MultiPolyNode;
//							delete(DelPolyNode);/* ����ֵ����ɾ�� */
//						}
//						flag = 1;
//					}
//					else if ((Head->next != NULL) && (MultiPolyNode->Expo < Head->next->Expo))
//					{
//						Head = Head->next;
//					}
//					else
//					{
//						/* ����Ƚϵ������û�бȽϵĶ���ʱ��ֱ�������������뼴�� */
//						MultiPolyNode->next = NULL;
//						Head->next = MultiPolyNode;
//						flag = 1;
//					}
//				}
//				P2 = P2->next;  /* P2������ */
//			}
//			P1 = P1->next;/* P1������ */
//		}
//		/* ɾ��ͷ��� */
//		Temp = MultiPoly; MultiPoly = MultiPoly->next; delete(Temp);
//
//		return MultiPoly;
//	}
//}
//
//
//
//
////int main()
////{
////		int N;
////		int Data, Expo;  /* ������ָ������ */
////		Polynomial P1, P2, temp,Head;
////		Polynomial AddP,MultiP;
////		P1 = CreatePoly();
////		P2 = CreatePoly();
////		
////		
////		/* ����P1 */
////		Head = P1;
////		cin >> N;
////		while (N--){
////			cin >> Data >> Expo;
////			InsertPolyNode(Head, Data, Expo);
////			Head = Head->next;
////		}
////		temp = P1; P1 = P1->next; delete(temp);
////		
////		/* ����P2 */
////		Head = P2;
////		cin >> N;
////		while (N--){
////			cin >> Data >> Expo;
////			InsertPolyNode(Head, Data, Expo);
////			Head = Head->next;
////		}
////		temp = P2; P2 = P2->next; delete(temp);
////
////		AddP = AddPoly(P1, P2);
////		MultiP= MultiPoly(P1, P2);
////
////
////		system("pause");
////		return 0;
////}