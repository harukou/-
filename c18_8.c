#include "stdio.h"
#define N 1000

void divisor(int n)  // 第一题
{
	for (int i = 1; i <= n/2; ++i)
	{
		//这里还有一种写法就是上面为n/2
		if (n%i == 0)
		{
			/* code */
				printf("the positive divisor of %d: %d\n",n,i );
		}
	}
}

int is_perfect(int n) //第二题
{
	int sum;
	if (n<=0)
	{
		return 0 ;
	}
	sum = 0;
	for (int i = 1; i < n; ++i)
	{
		if (n % i == 0)
		{
			sum += i;
		}
	}
	if (sum == n)
	{
		return 1;
	}
	else
		return 0;
}

void perfect_num(void)
{

	int sum[N+1];
	for (int i = 1; i <= N; ++i)
		sum[i] = 0;
	for (int j = 1; j <= N/2; ++j)   // 这里是除数
	{
		for (int i = 1; i <= N ; ++i)  // 被除数
		{
			if (i % j == 0 && i != j)
				sum[i] += j;
		}
	}
	for (int i = 1; i <= N; ++i)
	{
		/* code */
		if (sum[i] == i)
		{
			/* code */
			printf("%d\n", sum[i]);
		}

	}
}

int main(int argc, char const *argv[])
{
	/* code */
	divisor(30);
	//printf("%d\n", is_perfect(8122));
	//perfect_num();
	return 0;
}