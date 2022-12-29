#include <stdio.h>
#include <time.h>

void main(){
	clock_t start, end;
	double cpu_time_used;
	
	FILE *fp;
	int arr[100],i=0,j,temp;
	
	fp = fopen("average.txt","r");
	for(i=0;i<=100;i++){
		fscanf(fp,"%d",&arr[i]);
	}
	start = clock();
	
	for(i=0;i<100;i++){
		for( j=1;j<100-i;j++){
			if (arr[j] > arr[j+1]){
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
	
	for(i=0;i<=100;i++){
		printf("%d ",arr[i]);
	}
	
	end = clock();
	cpu_time_used = ((double)(end - start)/CLOCKS_PER_SEC);
	printf("\n%f",cpu_time_used);
}
