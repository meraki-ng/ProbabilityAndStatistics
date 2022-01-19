#include <stdio.h>

int main()
{
	double A, B, C, D;
	int input;
	printf("1에서 17까지의 수를입력하세요 : ");
	scanf_s("%d", &input);

	A = input / 2;
	B = (A - input) / 5;
	C = (B - input) / 3;
	D = (C - input) / 7;

	printf("\n그릇 - 1 개수(2) : %.lf ", A);
	printf("\n그릇 - 2 개수(3) : %.lf ", B);
	printf("\n그릇 - 3 개수(5) : %.lf ", C);
	printf("\n그릇 - 4 개수(7) : %.lf ", D);


	return 0;
}