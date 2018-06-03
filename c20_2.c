#include "stdio.h"

void in(int dt, int *val)
{
	int i;
	val[0]++;

	for (i = val[0]; i > 1&& dt < val[i/2]; i = i/2)
		val[i] = val[i/2];
	val[i] = dt;

}

int dl(int *val)
{
	int i=1, j , ret = val[1];
	while( i <= val[0] / 2){
		j = 2*i;
		if( j + 1 < val[0] && val[j+1] < val[j])
			j++;
		if(val[val[0]]<val[j])
			break;
		val[i] = val[j];
		i = j;
	}
	val[i] = val[val[0]];
	val[0]--;
	return ret;
}

int main(int argc, char const *argv[])
{
	int sz = 5;
	int d[]={10,2,5,1,0};
	int val[]={0,0,0,0,0,111};
	for (int i = 0; i < sz; i++)
		in(d[i],val);
	/*
	for (int i = 0; i < sz+1; ++i)
	{
		printf("%d\n",val[i] );
	}
	*/
	for(int i = 0; i<sz; i++)
		d[i] = dl(val);
	for (int i = 0; i < sz; ++i)
	{
		printf("%d\n",d[i] );
	}
	
	return 0;
}