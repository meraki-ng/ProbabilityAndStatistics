#include <stdio.h>
/*
	��ó : 2022 ����Ư�� Ȯ������� ������ ����
	���л� 3��, ���л� 2�� ���� 2���� ������ ������ �ΰ� ������ Ź�ڿ� �ѷ����� ��,
	���л� 2���� ���� �̿��ϰ� ���� 2���� ���� �̿����� �ʰ� �ɴ� ����� ��
	(��, ȸ���Ͽ� ��ġ�ϴ� ���� ���� ������ ����.)
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
	printf("����� �� : %d", res);
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