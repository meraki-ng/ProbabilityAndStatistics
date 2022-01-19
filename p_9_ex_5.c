#include <stdio.h>
#include <stdlib.h>

/*
	********************************************************************* CHALLENGE 4 ********************************************************************
							 출처 : 2022 수능특강 확률과통계 p_9_ex_3
		파란 공 4개, 노란 공 2개, 흰 공 1개를 모두 일렬로 나열할 때 양 끝에는 같은 색의 공이 놓이는 경우의 수(단, 같은 색의 공은 서로 구별하지 않는다)
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

	res = func1(blue, yellow, white); //blue가 양쪽에 있는 경우
	if (res == -1) error(blue, "blue");
	else printf("\nblue가 양쪽에 있는 경우 : %d", res);

	res = func1(white, yellow, blue);//white가 양쪽에 있는 경우
	if (res == -1) error(white,"white");
	else printf("\nwhite가 양쪽에 있는 경우 : %d", res);

	res = func1(yellow, blue, white);//yellow가 양쪽에 있는 경우
	if (res == -1) error(yellow, "yellow");
	else printf("\nyellow가 양쪽에 있는 경우 : %d", res);
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
		fprintf(stderr, "수는 음수가 될 수 없습니다.");
		exit(1);
	}
	else	fprintf(stderr, "\n%s는 1이므로 양쪽에 나열하지 못합니다.", name); //a==1
}