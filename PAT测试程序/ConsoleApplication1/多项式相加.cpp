//#include<iostream>
//using namespace std;
//
//typedef struct PolyNode* Polynomial;
//struct PolyNode
//{
//	int Data; /* 参数项 */
//	int Expo; /* 指数项 */
//	Polynomial next; /* 指向下一节点的指针 */
//};
//
//Polynomial CreatePoly()
//{
//	/* 创建一个空结点便于插入和删除 */
//	Polynomial Poly = new struct PolyNode;
//	Poly->next = NULL;
//
//	return Poly;
//}
//
///* 插入结点 */
//void InsertPolyNode(Polynomial Poly, int Data, int Expo)
//{
//	Polynomial NewPolyNode = new struct PolyNode;
//	NewPolyNode->Data = Data;
//	NewPolyNode->Expo = Expo;
//
//	/* 结点插入后后移 */
//	NewPolyNode->next = NULL;
//	Poly->next = NewPolyNode;
//}
//
///* 两多项式相加 */
//Polynomial AddPoly(Polynomial P1, Polynomial P2)
//{
//	Polynomial Temp, Zero;
//	Polynomial NewPolyNode = new struct PolyNode;
//	NewPolyNode->next = NULL;
//	Zero = NewPolyNode;
//	
//
//	if ((P1 || P2) == 0)  /* 如果两个多项式都不存在，直接退出 */
//		return false;
//	while (P1 && P2)
//	{
//		Polynomial AddPolyNode = new struct PolyNode;
//
//		if (P1->Expo > P2->Expo){
//			AddPolyNode->Data = P1->Data;
//			AddPolyNode->Expo = P1->Expo;
//			AddPolyNode->next = NULL;
//			/* 插入结点并后移 */
//			Zero->next = AddPolyNode;
//			Zero = AddPolyNode;
//			P1 = P1->next;
//		}
//		else if (P1->Expo < P2->Expo)
//		{
//			AddPolyNode->Data = P2->Data;
//			AddPolyNode->Expo = P2->Expo;
//			AddPolyNode->next = NULL;
//			/* 插入结点并后移 */
//			Zero->next = AddPolyNode;
//			Zero = AddPolyNode;
//			P2 = P2->next;
//		}
//		else
//		{
//			AddPolyNode->Data = P1->Data + P2->Data;
//			AddPolyNode->Expo = P1->Expo;
//			AddPolyNode->next = NULL;
//			/* 插入结点并后移 */
//			Zero->next = AddPolyNode;
//			Zero = AddPolyNode;
//			/* 结点后移 */
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
//		/* 插入结点并后移 */
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
//		/* 插入结点并后移 */
//		Zero->next = AddPolyNode;
//		Zero = AddPolyNode;
//		P2 = P2->next;
//	}
//	/* 释放掉头结点 */
//	Temp = NewPolyNode; NewPolyNode = NewPolyNode->next; delete(Temp);
//
//	return NewPolyNode;
//}
//
///* 两多项式相乘 */
//Polynomial MultiPoly(Polynomial P1, Polynomial P2)
//{
//	Polynomial Temp, Zero, Head;
//	Polynomial MultiPoly = new struct PolyNode;
//	int flag = 0;
//	Head = MultiPoly;
//	Zero = P2;  /* 记录P2的头结点 */
//	if (!P1 && !P2) /* 如果两个多项式中至少有一个多项式为空则无法进行下一步计算 */
//		return false;
//	if (P1){
//		while (P2){
//			Polynomial MultiPolyNode = new struct PolyNode;
//			MultiPolyNode->Data = P1->Data * P2->Data; /* 参数相乘 */
//			MultiPolyNode->Expo = P1->Expo + P2->Expo; /* 指数相加 */
//			MultiPolyNode->next = NULL;
//			/* 插入结点并后移 */
//			Head->next = MultiPolyNode;
//			Head = MultiPolyNode;
//			P2 = P2->next;
//		}
//
//		P1 = P1->next;  /*将P1移动至下一结点 */
//		while (P1){
//			P2 = Zero;  /* 将P2移动至头结点 */
//			Head = MultiPoly;  /* 将Head移动至头结点 */
//			while (P2){
//				flag = 0;  /* 对标志位进行初始化 */
//				Polynomial MultiPolyNode = new struct PolyNode;
//				MultiPolyNode->Data = P1->Data * P2->Data; /* 参数相乘 */
//				MultiPolyNode->Expo = P1->Expo + P2->Expo; /* 指数相加 */
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
//							delete(DelPolyNode);/* 将该值进行删除 */
//						}
//
//						else{
//							/* 删除该处结点值 */
//							MultiPolyNode->next = DelPolyNode->next;
//							Head->next = MultiPolyNode;
//							delete(DelPolyNode);/* 将该值进行删除 */
//						}
//						flag = 1;
//					}
//					else if ((Head->next != NULL) && (MultiPolyNode->Expo < Head->next->Expo))
//					{
//						Head = Head->next;
//					}
//					else
//					{
//						/* 如果比较到最后发现没有比较的对象时，直接在链表后面插入即可 */
//						MultiPolyNode->next = NULL;
//						Head->next = MultiPolyNode;
//						flag = 1;
//					}
//				}
//				P2 = P2->next;  /* P2结点后移 */
//			}
//			P1 = P1->next;/* P1结点后移 */
//		}
//		/* 删除头结点 */
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
////		int Data, Expo;  /* 参数与指数数据 */
////		Polynomial P1, P2, temp,Head;
////		Polynomial AddP,MultiP;
////		P1 = CreatePoly();
////		P2 = CreatePoly();
////		
////		
////		/* 创建P1 */
////		Head = P1;
////		cin >> N;
////		while (N--){
////			cin >> Data >> Expo;
////			InsertPolyNode(Head, Data, Expo);
////			Head = Head->next;
////		}
////		temp = P1; P1 = P1->next; delete(temp);
////		
////		/* 创建P2 */
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