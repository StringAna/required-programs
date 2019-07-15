#include<stdio.h>

int main(){
	int a,b;
	printf("\nEnter a and b to swap :\n");
	scanf("%d %d",&a,&b);
	printf("\nbefore swapping---\na= %d\tb= %d",a,b);
	a=a+b;
	b=a-b;
	a=a-b;
	printf("\nafter swapping---\na= %d\tb= %d",a,b);
	return 0;
}
