#include"Sort1.h"


int main()
{
	long long N;  /* 长整型类型 */
	ElementType Vertex;
	ElementType A[MaxVertexNum];
	
	cin >> N;  
	if (N == 1){
		cin >> Vertex;
		cout << Vertex;
	}
	else
	{
		for (long long i = 0; i < N; i++)
		{
			cin >> Vertex;
			A[i] = Vertex;
		}
		//Insert_Sort(A, N);
		//Select_Sort(A, N);

		//Heap_Sort(A, N);
		//Heap_Sort_Max(A, N);
		//MergeSort(A, N);
		//Merge_Sort(A, N);
		Q_Sort(A, N);
		for (long long i = 0; i < N; i++)
		{
			if (i > 0)
				cout << " ";
			cout << A[i];
		}
	}
 	system("pause");
	return 0;
}
