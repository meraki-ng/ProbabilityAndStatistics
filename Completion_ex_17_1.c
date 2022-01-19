/*
	출처 : 2022 수능특강 확률과통계 p_17_ex_1 
	중복조합같은 종류의 볼펜 6자루와 같은 종류의 연필 13자루를 네 사람에게 남김없이 나누어 줄 때, 각 사람이 적어도 볼펜 1자루, 연필 2자루를 받도록 나누어 주는 경우의 수는?
*/

#include <stdio.h>

#define PENCIL 13
#define PEN 6

int combination(int, int);
void print(int, int);

void main(void)
{
	//볼펜
	int res = combination(4, 2);
	//연필
	int res2 = combination(4, 5);
	//출력
	print(res, res2);
}
int combination(int m, int n)
{
	int i, mul1 = 1, mul2 = 1;
	for (i = 1; i <= n; i++)
	{
		mul1 *= i;
		mul2 *= m + n - i;
	}
	return mul2 / mul1;
}
void print(int num, int num2)
{
	printf("경우의 수 %d * %d = %d", num, num2, num*num2);
}
