#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
#include <omp.h>
#include <cassert>

int compare(const void* a, const void* b)
{
	return (*(int*)a - *(int*)b);
}

int main()
{
	int start, end;
	int num = 100000;
	int n = 4;
	int *a = (int *)malloc(sizeof(int) * num);
	assert(a != NULL);
	for (int i = 0; i < num; i++)
	{
		a[i] = rand();
	}
	
	start = GetTickCount();
	omp_set_num_threads(n);
#pragma omp parallel
	{
		//int thread_num = omp_get_thread_num();
		
#pragma omp single
		{
#pragma omp task
			{
				printf("A");
			}
#pragma omp task
			{
				printf("B");
			}
#pragma omp taskwait
			printf("C");
		}

	}
	end = GetTickCount();

	//printf("%d", end - start);

	return 0;
}