#include <stdio.h>
#include <time.h>

void main(){
		clock_t start,end;
	double cpu_time_used;
	
	int n,i,j,temp;
	printf("Enter number of elements : ");
	scanf("%d",&n);
	int arr[n];
	for ( i=0;i<n;i++){
		printf("Enter element : ");
		scanf("%d",&arr[i]);
	}
	
	start = clock();
	for(i=0;i<n;i++){
		for( j=0;j<n-i-1;j++){
			if (arr[j] > arr[j+1]){
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
	
	for ( i=0;i<n;i++){
		printf("Element : %d\n",arr[i]);
	}
	
	end = clock();
	cpu_time_used = ((double)(end - start)/CLOCKS_PER_SEC);
	printf("%f",cpu_time_used);
}
