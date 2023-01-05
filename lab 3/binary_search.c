#include <stdio.h>
#include <time.h>

void main(){
	clock_t start, end;
	double cpu_time_used;
	
	FILE *fp;
	int arr[100],i=0,n=100,number;
	
	fp = fopen("best.txt","r");
	for(i=0;i<=100;i++){
		fscanf(fp,"%d",&arr[i]);
	}
	
	printf("Enter number to be searched : ");
	scanf("%d",&number);
	int start1 = 0,end1= 100,mid;
	start = clock();
	while(start1 <= end1){
		mid = (start1 + end1)/2;
		
		if(number == arr[mid]){
			printf("Number is found at index : %d",mid);
			break;
		}
		else if(number < arr[mid]){
			end1 = mid -1;
		}
		else{
			start1 = mid + 1;
		}
	}
	if(!(start1<100)){
		printf("Number not found !!");
	}
	
	
	end = clock();
	cpu_time_used = ((double)(end - start)/CLOCKS_PER_SEC);
	printf("\n%f",cpu_time_used);
}
