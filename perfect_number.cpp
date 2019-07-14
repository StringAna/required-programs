#include<stdio.h>
#include<stdlib.h>
int main(){
	int n,i,res=0;
	scanf("%d",&n);
	
	for(i=1 ; i<=(n/2) ; i++){
		if((n%i)==0){
			res+=i;
		}
	}
	if(res==n){
		printf("\nit is a perfect number");
	}
	else{
		printf("\nit is not a perfect number");
	}
	return 0;
}
