#include <stdio.h>
/*
	출처 : 2022 수능특강 확률과통계 원순열 예제
	남학생 3명, 여학생 2명 교사 2명이 일정한 간격을 두고 원형의 탁자에 둘러앉을 때,
	여학생 2명은 서로 이웃하고 교사 2명은 서로 이웃하지 않게 앉는 경우의 수
	(단, 회전하여 일치하는 것은 같은 것으로 본다.)
*/
int case1(int value);
int case2(int value1, int teacher);
int case3(int girl);
int result(int value, int value1, int value2);

int main()
{
	int  girl = 2, boy = 3, teacher = 2, value = 0 ,value1, value2, res;
	value = girl + boy;
	value1 = value - 1;
	value = case1(value - 2);
	value1 = case2(value1, teacher);
	value2 = case3(girl);
	res = result(value, value1, value2);
	printf("경우의 수 : %d", res);
	return 0;
}
int case1(int value)
{
		if (value <= 1)	return 1;
		else return value * case1(value - 1);
}
int case2(int value1, int teacher)
{
	if (value1 <=  teacher) return 1;
	else return (value1 * case2(value1 - 1, teacher));
}
int case3(int girl)
{
	if (girl <= 1) return 1;
	else return (girl * case3(girl - 1));
}
int result(int value, int value1, int value2)
{
	return value * value1 * value2;
}