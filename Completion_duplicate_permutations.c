#include <stdio.h>
#include <stdlib.h>

#define MOD 5
#define ARRAY_SIZE 5

/*
	**********************************************************************CHALLENGE 3*********************************************************************
							 출처 : 2022 수능특강 확률과통계 중복순열 예제
		숫자 0,2,4,6,8중에서 중복을 허락하여 4개를 택해 일렬로 나열하고 만들 수 있는 네 자리의 자연 수 중 5로 나누었을 때의 나머지가 2 이하인 자연수의 개수는
					   [소스코드] 단순 연결 리스트 참고 자료 : C로 배우는 쉬운 자료구조 개정 3판 한빛아카데미
	******************************************************************************************************************************************************
*/

typedef struct ListNode
{
	int data[ARRAY_SIZE];
	struct ListNode* link;
}listNode;

typedef struct
{
	listNode* head;
}linkedList_h;


void print(int, int, int);
int units(linkedList_h *L);
void insert(linkedList_h *L);
int thousands(linkedList_h *L);
linkedList_h* createLinkedList_h();
void freeLinkedList_h(linkedList_h* L);
void insertLastNode(linkedList_h *L, int x);

int main(void)
{
	linkedList_h *L;
	L = createLinkedList_h();
	insert(L);

	int units_count = units(L);
	int thousands_count = thousands(L);
	int repetition_res = repetition(L);

	print(units_count, thousands_count, repetition_res);

	freeLinkedList_h(L);
	return 0;
}

linkedList_h* createLinkedList_h()
{
	linkedList_h * L;
	L = (linkedList_h*)malloc(sizeof(linkedList_h));
	L->head = NULL;
	return L;
}

void insertLastNode(linkedList_h *L, int x)
{
	listNode* newNode;
	listNode* temp;
	newNode = (listNode*)malloc(sizeof(listNode));
	*newNode->data = x;
	newNode->link = NULL;
	if (L->head == NULL)
	{
		L->head = newNode;
		return;
	}
	temp = L->head;
	while (temp->link != NULL) temp = temp->link;
	temp->link = newNode;
}

void insert(linkedList_h *L)
{
	int i = 0;
	while (i < ARRAY_SIZE * 2)
	{
		insertLastNode(L, i);
		i = i + 2;
	}
}

int units(linkedList_h *L)
{
	int count = 0;
	listNode *p;
	p = L->head;
	while (p != NULL)
	{
		if ((*p->data % MOD) <= 2)	count++;
		p = p->link;
	}
	return count;
}

int thousands(linkedList_h *L)
{
	int count = 0;
	listNode *p;
	p = L->head;
	while (p != NULL)
	{
		if (*p->data != 0)	count++;
		p = p->link;
	}
	return count;
}

int repetition(linkedList_h *L)
{
	int count = 0;
	listNode *i;
	listNode *j;
		for(i = L->head; i != NULL;  i= i->link)
		{
			for (j = L->head;  j != NULL; j = j->link)
			{
				++count;
				/*
				printf("\n(%d", *i);
				printf(",%d)", *j);
				printf("count : %d\n", count);
				*/
			}
		}
	return count;
}

void print(int units_count, int thousands_count, int repetition_res)
{
	int res = units_count * thousands_count*repetition_res;
	printf("\n따라서 구하는 자연수의 개수 %d*%d*%d=%d\n", units_count, thousands_count, repetition_res, res);
}

void freeLinkedList_h(linkedList_h* L)
{
	listNode* p;
	while (L->head != NULL)
	{
		p = L->head;
		L->head = L->head->link;
		free(p);
		p = NULL;
	}
}