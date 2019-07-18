#include<stdio.h>

int hcf(int,int);
int lcm(int,int);

int main(){
	int a,b;
	scanf("%d %d",&a,&b);
	printf("\nHCF of %d and %d is----%d",a,b,hcf(a,b));
	printf("\nLCM of %d and %d is----%d",a,b,lcm(a,b));
	return 0;
}

int hcf(int a,int b){
	if(a==0){
		return b;
	}
	return hcf(a%b,a);
}

int lcm(int a,int b){
	return (a*b)/hcf(a,b);
}
