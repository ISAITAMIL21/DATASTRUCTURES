#include <stdio.h>
#include <stdlib.h>
struct poly
{
int coff;
int pow;
struct poly *Next;
};

typedef struct poly Poly;

void Create(Poly *List)
{
	int choice;
	Poly *Position, *NewNode;
	Position = List;
	do
	{
	NewNode = malloc(sizeof(Poly));
	printf("Enter the coefficient : ");
	scanf("%d", &NewNode->coff);
	printf("Enter the power : ");
	scanf("%d", &NewNode->pow);
	NewNode->Next = NULL;
	Position->Next = NewNode;
	Position = NewNode;
	printf("Enter 1 to continue : ");
	scanf("%d", &choice);
	}
	while(choice == 1);
}


void Display(Poly *List)
{
	Poly *Position;
	Position = List->Next;
	while(Position != NULL && Position->pow >= 0)
	{
	printf("%dx^%d", Position->coff, Position->pow);
	Position = Position->Next;
	if(Position != NULL && Position->coff > 0)
	{
		printf("+");
	}
	}
}

void Differentiation(Poly *Poly1, Poly *Result)
{
	Poly *Position;
	Poly *NewNode;
	Poly1 = Poly1->Next;
	Result->Next = NULL;
	Position = Result;
	while(Poly1 != NULL)
	{
	NewNode = malloc(sizeof(Poly));
	NewNode->coff = Poly1->coff * Poly1->pow;
	NewNode->pow = Poly1->pow - 1;
	Poly1 = Poly1->Next;
	NewNode->Next = NULL;
	Position->Next = NewNode;
	Position = NewNode;
	}
}

int main()
{
	Poly *Poly1 = malloc(sizeof(Poly));
	Poly *Result = malloc(sizeof(Poly));
	Poly1->Next = NULL;
	printf("Enter the values for polynomial :\n");
	Create(Poly1);
	printf("The polynomial equation is : ");
	Display(Poly1);
	Differentiation(Poly1, Result);
	printf("\nThe polynomial differentiation equation is : ");
	Display(Result);
	return 0;
}