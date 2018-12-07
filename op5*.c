
#include<stdio.h>
#include<omp.h>
#include<stdlib.h>

omp_lock_t lock;

int main(){

	int a[]={1,2,3,4,5},b[]={1,2,3,4,5},c[5],d[5],i,j;
	
	#pragma omp parallel shared(a,b,c,d) private(i)
	
		#pragma omp sections nowait

			#pragma section
			{
				for(i=0;i<5;i++){
					c[i] = a[i] + b[i];
				printf("\n Section 1 : Thread %d el %d",omp_get_thread_num(),i);
				}
			
			}

			#pragma section
			{
				for(i=0;i<5;i++){
					d[i] = a[i] * b[i];
				printf("\n Section 2 : Thread %d el %d",omp_get_thread_num(),i);
				}
			
			}			
		
	return 0;
}
