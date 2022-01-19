/*
	********************************************************************* CHALLENGE 2 ********************************************************************
							 ��ó : 2022 ����Ư�� Ȯ������� p_19_ex_2 �ߺ������� Ȱ��
							 �ܼ� ���� ����Ʈ ���� �ڷ� : C�� ���� ���� �ڷᱸ�� ���� 3�� �Ѻ���ī����
							   ������ x+y+z+4w = 10�� ������Ű�� ���� �ƴ� ���� x,y
	**********************************************************************************************************************************************************
								���� �� �� : L �� �־��� ������ case���� ������.
*/

#include <stdio.h>
#include <stdlib.h>

#define D 10 //�캯 ��

typedef struct ListNode
{
	int data[D];
	struct ListNode* link;
}listNode;

typedef struct
{
	listNode* head;
}linkedList_h;


void w_result(int, int, linkedList_h *);
int units(linkedList_h *);
int thousands(linkedList_h *);
linkedList_h* createLinkedList_h();
void insertLastNode(linkedList_h *, int);
void freeLinkedList_h(linkedList_h*);

int main(void)
{
	int w = 4;
	linkedList_h * L = createLinkedList_h();
	w_result(w, D, L);

	freeLinkedList_h(L);
	return 0;
}

void w_result(int w, int d, linkedList_h *L)
{
	//���� �ƴ� ����(0,1,2...)
	int i = 0;
	while (w *  i  <= d)
	{	
		insertLastNode(L, i);
		i++;
	}
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