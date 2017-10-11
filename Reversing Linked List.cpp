#include<iostream>
#include<stdio.h>
#include<algorithm>
#include <iomanip>
using namespace std;

/*
typedef int ElementType;
typedef struct DataType *PtrNode;

typedef struct DataType 
{
	ElementType FrontAddress;
	ElementType RearAddress;
	ElementType Data;
	PtrNode Next;
};


typedef struct Address *Link;
typedef struct Address
{
	ElementType five;
	Link Node;
};

Link CreateADD()
{
	Link P;
	P = (Link)malloc(sizeof(struct Address));
	P->Node = NULL;
	return P;
}



PtrNode CreateList(int Num, int FirstAddress)
{
	PtrNode P,Q,t, PP,temp,temp1;
	P = (PtrNode)malloc(sizeof(struct DataType));
	P->Next = NULL;
	PP = P;
	for (int i = 0; i < Num; i++)
	{
		t = (PtrNode)malloc(sizeof(struct DataType));
		cin >> t->FrontAddress >> t->Data >> t->RearAddress;
		t->Next = PP->Next;
		PP->Next = t;
		PP = t;
	}

	Q = (PtrNode)malloc(sizeof(struct DataType));
	Q->Next = NULL;
	PP = Q;
	temp = P;
	
	while (temp->Next && (temp->Next->FrontAddress != FirstAddress))
		temp = temp->Next;

	if (temp->Next)
	{
		temp1 = temp->Next;
		temp->Next = temp->Next->Next;
		temp1->Next = PP->Next;
		PP->Next = temp1;
		PP = temp1;
	}

	for (int i = 0; i < Num-1; i++)
	{
		temp = P;
		while (temp->Next && (temp->Next->FrontAddress != PP->RearAddress))
			temp = temp->Next;

		if (temp->Next)
		{
			temp1 = temp->Next;
			temp->Next = temp->Next->Next;
			temp1->Next = PP->Next;
			PP->Next = temp1;
			PP = temp1;
		}
	}

	PP = Q;
	Q = Q->Next;
	free(PP);

	return Q;
}



int main()
{
	PtrNode P,t;
	Link IP, Temp0,Temp1;

	IP = CreateADD();
	Temp0 = IP;

	int FirstAdress;
	int Num;
	int K;

	int a[100000], b[100000];
	for (int i = 0; i < 100000; i++)
	{
		a[i] = b[i] = 0;
	}

	cin >> FirstAdress >> Num >> K;

	P = CreateList(Num, FirstAdress);
	t = P;

	for (int i = 0; i < Num; i++)
	{
		a[i] = t->FrontAddress;
		b[i] = t->Data;
		t = t->Next;
	}

	int m = 0;
	int n = 0;

	m = Num / K;
	n = Num % K;

	if (K == 1)
	{
		for (int i = 0; i < Num; i++)
		{
			cout << setfill('0') << setw(5) <<t->FrontAddress<< " " << t->Data << " " << t->RearAddress << endl;
			t = t->Next;
		}
	}
	else
	{

		for (int i = 1; i <= m; i++)
		{
			for (int j = K*i - 1; j >= 0; j--)
			{
				Temp1 = (Link)malloc(sizeof(struct Address));
				Temp1->five = a[j];
				Temp1->Node = Temp0->Node;
				Temp0->Node = Temp1;
				Temp0 = Temp1;
			}
		}
		if (n)
		{
			for (int i = Num - 2; i < Num; i++)
			{
				Temp1 = (Link)malloc(sizeof(struct Address));
				Temp1->five = a[i];
				Temp1->Node = Temp0->Node;
				Temp0->Node = Temp1;
				Temp0 = Temp1;

			}
		}
		Temp1 = Temp1 = (Link)malloc(sizeof(struct Address));
		Temp1->five = -1;
		Temp1->Node = Temp0->Node;
		Temp0->Node = Temp1;
		Temp0 = Temp1;

		Temp0 = IP;
		IP = IP->Node;
		free(Temp0);
		Temp0 = IP;
		IP = IP->Node;
		free(Temp0);
		Temp0 = IP;

		for (int i = 1; i <= m; i++)
		{
			for (int j = K*i - 1; j >= 0; j--)
			{
				cout << setfill('0') << setw(5) << a[j] << " " << b[j] << " " << Temp0->five << endl;
				Temp0 = Temp0->Node;

			}
		}
		if (n)
		{
			for (int i = Num - 2; i < Num; i++)
			{
				cout << setfill('0') << setw(5) << a[i] << " " << b[i] << " " << Temp0->five << endl;
				Temp0 = Temp0->Node;

			}
		}
	}

}
*/

#define MAXSIZE 1000010 

struct Node {
	int Data;
	int Next;
}Node[MAXSIZE];

int List[MAXSIZE];

int main()
{
	int FirstAdd;
	int Num;
	int K;

	cin >> FirstAdd >> Num >> K;
	int Address;
	int data;
	int next;
	for (int i = 0; i < Num; i++)
	{
		cin >> Address >> data >> next;
		Node[Address].Data = data;
		Node[Address].Next = next;
	}

	int p = FirstAdd;

	int j = 0;
	while (p != -1)
	{
		List[j] = p;
		p = Node[p].Next;
		j = j + 1;
	}

	int t = 0;
	while (t + K <= j)
	{
		reverse(&List[t], &List[t + K]);
		t = t + K;
	}

	for (t = 0; t<j - 1; t++)
		printf("%05d %d %05d\n", List[t], Node[List[t]].Data, List[t + 1]);
	printf("%05d %d -1\n", List[t], Node[List[t]].Data);
	return 0;
}