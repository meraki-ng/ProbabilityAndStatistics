#include <stdio.h>
#include <stdlib.h>

/*
	********************************************************************* CHALLENGE 4 ********************************************************************
							 ��ó : 2022 ����Ư�� Ȯ������� p_9_ex_3
		�Ķ� �� 4��, ��� �� 2��, �� �� 1���� ��� �Ϸķ� ������ �� �� ������ ���� ���� ���� ���̴� ����� ��(��, ���� ���� ���� ���� �������� �ʴ´�)
	**********************************************************************************************************************************************************
*/

int func(int);
int func1(int, int, int);
void error(int, char*);

void main(void)
{
	int blue = 4;
	int yellow = 2;
	int white = 1;
	int res;

	res = func1(blue, yellow, white); //blue�� ���ʿ� �ִ� ���
	if (res == -1) error(blue, "blue");
	else printf("\nblue�� ���ʿ� �ִ� ��� : %d", res);

	res = func1(white, yellow, blue);//white�� ���ʿ� �ִ� ���
	if (res == -1) error(white,"white");
	else printf("\nwhite�� ���ʿ� �ִ� ��� : %d", res);

	res = func1(yellow, blue, white);//yellow�� ���ʿ� �ִ� ���
	if (res == -1) error(yellow, "yellow");
	else printf("\nyellow�� ���ʿ� �ִ� ��� : %d", res);
}
int func1(int a, int b, int c)
{
	int res = 1, res2 = 1, res3 = 1, res4 = 1;
	if (a > 1)
	{
		if (a == 2)	res = func(b+c);
		else res = func((a-2)+b+c);
		res2 = func(a-2);
		res3 = func(b);
		res4 = func(c);
	}
	else return -1;
	return res / (res2*res3*res4);
}
int func(int a)
{
	if (a == 1 || a == 0) return 1;
	else return a * func(a - 1);
}
void error(int a, char *name)
{
	if (a < 0)
	{
		fprintf(stderr, "���� ������ �� �� �����ϴ�.");
		exit(1);
	}
	else	fprintf(stderr, "\n%s�� 1�̹Ƿ� ���ʿ� �������� ���մϴ�.", name); //a==1
}