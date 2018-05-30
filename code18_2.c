#include "stdio.h"

double factorial(int n)
	{
		if (n==0 || n==1)
			return 1;
		else
			return n * factorial(n-1);
	}

double factorial2(int n)
	{
 		int product=1;
 		while (n>0)
 		{
 			product*=n;
 			n--;
 		}
 		return product;
	}

double power(double x , int n)
	{
		double y , z;
		y = 1.0;
		z = x;
		while (n>0){
			if (n%2 == 1)
			{
				/* code */
				y *= z;
			}
		z *=z;
		n /=2;
		}
		return y;
	}
double my_sin(double x, int n)
	{	
		double sinx = 0;
		for (int i = 0; i <= n; i++)
		{
			/* code */
			sinx += power(-1 , i) * power(x , 2 * i + 1)/factorial(2 * i + 1);
		}
		return sinx;
	}

int main(int argc, char const *argv[])
{
	
	double x = 1.0;
	int n = 3;
	double sinx = 0;
	sinx = my_sin(x,n);
	printf("sineX is: %f\n", sinx);
	
	
	//printf("%f\n",factorial2(5) ); 	
	return 0;
}