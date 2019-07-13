#include<stdio.h>
#include<string.h>

int main(){
	char a[50];
	int i,len;
	scanf("%s",a);
	len=strlen(a);
	for(i=0 ; i<(len/2) ; i++){
		if(a[i]!=a[len-i-1]){
			printf("\nno");
			return 0;
		}
	}
	printf("\nyes");
	return 0;
}
