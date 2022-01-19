#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ARRAY_NUM 10000
double LawOfConsensus(int, int, int*);

int main(void)
{
	int target_num,i;
	double res;
	int *ptr;
	
	ptr = (int *)malloc(sizeof(int) * ARRAY_NUM);

	for (i = 0; i < ARRAY_NUM; i++)
	{
		ptr[i] = i;
	}

	printf("�� ���ڸ� �������ּ��� : ");
	scanf_s("%d", &target_num);
	res = LawOfConsensus(target_num, ARRAY_NUM, ptr);

	printf("%d�� ����� ���� Ȯ�� : %g�Դϴ�.", target_num, res);

	free(ptr);
}

double LawOfConsensus(int target_num, int SizeOfArray, int *ptr)
{
	//����ڰ� �Է��� ���� ����� ���� Ȯ��
	int i, count = 0;
	for (i = 0; i < SizeOfArray; i++)
	{
		if ((ptr[i] % target_num) == 0)		count++;
	}
	 return (double) count/SizeOfArray;
}