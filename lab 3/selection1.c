#include <stdio.h>
#include <time.h>

void main(){
	clock_t start, end;
	double cpu_time_used;
	
	FILE *fp,*fp1;
	int arr[100],i=0,j,minj,minx,n=100,x=5;
	
	fp = fopen("worst.txt","r");
	for(i=0;i<=100;i++){
		fscanf(fp,"%d",&arr[i]);
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
	fp1 = fopen("sorted.txt","w");
	for(i=0;i<n;i++){
	fprintf(fp1,"%d \n",arr[i]);
	}
	
	end = clock();
	cpu_time_used = ((double)(end - start)/CLOCKS_PER_SEC);
	printf("\n%f",cpu_time_used);
}
