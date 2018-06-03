#include "stdio.h"

void is(int sz, int d[])
{
	int i,j,m,kk=0;
	for( i = 1;i<sz;i++){
		m = d[i];
		for(j = i - 1; j>=0&&d[j]<=m;j--)
			{d[j+1] = d[j];
			 kk++;
			 printf("***%d\n",kk );}
		d[j+1] = m;
	}
}
int main()
{
	int sz = 4;
	int d[]={12,45,78,79};
	is(sz,d);
	for (int i = 0; i < sz; ++i)
	{
		/* code */
		//printf("%s\n","**********" );
		printf("%d\n", d[i]);
	}
	return 0;
}