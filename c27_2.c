#include "stdio.h"
#define N 5
int a[N][N] = {0};
int sorted[N] = {0}, indegree[N] = {0}, nodestack[N] = {0}, stackp = 0;

void count_indegree(){
	//计算指向每个节点的个数
	int tail, head;
	for (head = 0; head < N; head++)
	{
		indegree[head] = 0;
		for (tail = 0; tail < N; tail++)
		{
			if (a[tail][head] == 1)
				indegree[head]++;
		}
	}
}

void remove_node(int node){
	int head;
	for (head = 0; head < N; head++)
	{
		if (a[node][head] == 1){
			indegree[head]--;
			if(indegree[head] == 0){
				nodestack[stackp] = head;
				stackp++;
			}
		}
	}
	
}

int sort(int sorted[]){
	int count = 0, node;
	count_indegree();
	for (node = 0; node < N; node++)
	{
		/* code */
		if (indegree[node] == 0)
		{
			nodestack[stackp] = node;
			stackp++;
		}
	}
	while(stackp > 0){
		stackp--;
		node = nodestack[stackp];
		sorted[count] = node;
		count++;
		remove_node(node);
	}
	return count;
}
int main(int argc, char const *argv[])
{
	int head, tail;
	
	a[1][0] =1;
	a[4][0] =1;
	a[4][2] =1;
	a[0][3] =1;
	printf("a[][]:\n");
	for (head = 0; head < N; head++)
	{
		//indegree[head] = 0;
		for (tail = 0; tail < N; tail++)
		{
			printf("%d ", a[head][tail]);
			if(tail == 4)
				printf("\n");
		}
	}
    printf("*************************************\n");
	count_indegree();
	printf("indegree[]:\n");
	for (tail = 0; tail < N; tail++)
		{
			printf("%d ", indegree[tail]);
			if(tail == 4)
				printf("\n");
		}
	printf("*************************************\n");
	int counts;
	counts = sort(sorted);
	printf("counts = %d\n", counts);
	printf("sorted[]:\n");
	for (tail = 0; tail < N; tail++)
		{
			printf("%d ", sorted[tail]);
			if(tail == 4)
				printf("\n");
		}
	printf("nodestack[]:\n");
	for (tail = 0; tail < N; tail++)
		{
			printf("%d ", nodestack[tail]);
			if(tail == 4)
				printf("\n");
		}
	
	return 0;
}