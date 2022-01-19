/*
	********************************************************************* CHALLENGE 2 ********************************************************************
							 출처 : 2022 수능특강 확률과통계 p_19_ex_2 중복조합의 활용
							 단순 연결 리스트 참고 자료 : C로 배우는 쉬운 자료구조 개정 3판 한빛아카데미
							   방정식 x+y+z+4w = 10을 만족시키는 음이 아닌 정수 x,y
	**********************************************************************************************************************************************************
								개선 할 점 : L 에 넣어진 값들을 case별로 나누기.
*/

#include <stdio.h>
#include <stdlib.h>

#define D 10 //우변 항

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
	//음이 아닌 정수(0,1,2...)
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