#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int findFreq(char *s,char *find){
	int slen,i,j,flag,findlen;
	slen=strlen(s);
	findlen=strlen(find);
	int count=0;
	for(i=0 ; i<slen-findlen ; i++){
		flag=1;
		for(j=0 ; j<findlen ; j++){
			if(s[i+j]!=find[j]){
				flag=0;
				break;
			}
		}
		if(flag==1){
			count++;
		}
	}
	
	/*if(count==0){
		return -1;
	}
	else{
		return count;
	}*/
	
	return count;
}

int main(){
	char s[100],find[100];
	int i,res=0;
	gets(s);
	gets(find);
	res=findFreq(s,find);
	printf("\nFrequency of res = %d",&res);
	return 0;
}
