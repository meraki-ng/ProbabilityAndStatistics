#include <stdio.h>
#include <stdlib.h>

#define MOD 5
#define ARRAY_SIZE 5

/*
	**********************************************************************CHALLENGE 3*********************************************************************
							 ��ó : 2022 ����Ư�� Ȯ������� �ߺ����� ����
		���� 0,2,4,6,8�߿��� �ߺ��� ����Ͽ� 4���� ���� �Ϸķ� �����ϰ� ���� �� �ִ� �� �ڸ��� �ڿ� �� �� 5�� �������� ���� �������� 2 ������ �ڿ����� ������
					   [�ҽ��ڵ�] �ܼ� ���� ����Ʈ ���� �ڷ� : C�� ���� ���� �ڷᱸ�� ���� 3�� �Ѻ���ī����
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
	printf("\n���� ���ϴ� �ڿ����� ���� %d*%d*%d=%d\n", units_count, thousands_count, repetition_res, res);
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