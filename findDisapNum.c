#include<stdio.h>
#include<stdlib.h>

void findDis(int range,int a[]){
	int i,temp=0;
	
	for(i=0 ; i<range ; i++){
		temp=abs(a[i])-1;
		if(a[temp]>0){
			a[temp]*=(-1);
		}
	}
	for(i=0 ; i<range ; i++){
		if(a[i]>0){
			printf("The disappered number is :- %d\n",(i+1));
		}
	}
}

int main(){
	int n,i;
	printf("\nEnter the range : ");
	scanf("%d",&n);
	
	int arr[n];
	printf("\nEnter %d number of elements in the array :- ",n);
	for(i=0 ; i<n ; i++){
		scanf("%d",&arr[i]);
	}
	
	findDis(n,arr);
	
	return 0;
}
