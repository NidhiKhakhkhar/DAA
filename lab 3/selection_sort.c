#include <stdio.h>
#include <time.h>

void main(){
	clock_t start,end;
	double cpu_time_used;
	
	int n,i,j,minj,minx;
	printf("Enter number of elements : ");
	scanf("%d",&n);
	int arr[n];
	for (i=0;i<n;i++){
		printf("Enter element : ");
		scanf("%d",&arr[i]);
	}
	
	start = clock();
	for (i=0;i<n;i++){
		minj = i;
		minx = arr[i];
		for(j=i+1;j<n;j++){
			if(arr[j] < minx){
				minj = j;
				minx = arr[j];
			}
		}
		arr[minj] = arr[i];
		arr[i] = minx;
	}
	
	for(i=0;i<n;i++){
		printf("Element : %d\n",arr[i]);
	}
	
	end = clock();
	cpu_time_used = ((double)(end - start)/CLOCKS_PER_SEC);
	printf("%f",cpu_time_used);
}
