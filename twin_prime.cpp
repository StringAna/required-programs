#include<stdio.h>

bool check(int);

int main(){
	int i,low,high;
	printf("\nEnter the lower range and upper range ");
	scanf("%d  %d",&low,&high);
	
	for(i=low ; i<=high ; i++){
		if(check(i) && check(i+2)){
			printf("\n( %d , %d )",i,i+2);
			i=i+2;
		}
	}
	return 0;
}

bool check(int n){
	int i;
	if(n<2){
		return false;
	}
	else{
		for(i=2 ; i<(n/2) ; i++){
			if((n%i)==0){
				return false;
			}
		}
		return true;
	}
}
