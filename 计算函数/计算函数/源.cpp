#define _CRT_SECURE_NO_WARNINGS 1
float max3(int a, int b, int c);
int main(void)
{
	int a, b, c;
	float m = 0;
	scanf("%d %d %d", &a, &b, &c);
	m = max3(a + b, b, c) / (max3(a, b + c, c) + max3(a, b, b + c));
	printf("%.2f\n", m);

	return 0;
}

float max3(int a, int b, int c)
{
	return (a>b) ? ((a>c) ? a : c) : ((b>c) ? b : c);
}