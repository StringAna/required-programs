#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	char a[50],temp;
	int i,len;
	scanf("%s",a);
	len=strlen(a);
	
	for(i=0 ; i<len/2 ; i++){
		temp=a[i];
		a[i]=a[len-i-1];
		a[len-i-1]=temp;
	}
	printf("\n%s",a);
	return 0;
}
