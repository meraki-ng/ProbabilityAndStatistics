#include <stdio.h>

int main()
{
	double A, B, C, D;
	int input;
	printf("1���� 17������ �����Է��ϼ��� : ");
	scanf_s("%d", &input);

	A = input / 2;
	B = (A - input) / 5;
	C = (B - input) / 3;
	D = (C - input) / 7;

	printf("\n�׸� - 1 ����(2) : %.lf ", A);
	printf("\n�׸� - 2 ����(3) : %.lf ", B);
	printf("\n�׸� - 3 ����(5) : %.lf ", C);
	printf("\n�׸� - 4 ����(7) : %.lf ", D);


	return 0;
}