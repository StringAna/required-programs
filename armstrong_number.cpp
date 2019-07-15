//armstrong or narcissict number
#include<stdio.h>
#include<math.h>
int len(int);
void check(int,int);

int main(){
	int num,length;
	printf("\nenter the number ");
	scanf("%d",&num);
	length=len(num);
	check(length,num);
	return 0;
}

int len(int num){
	int count=0;
	while(num!=0){
		num=num /10;
		count++;
	}
	return count;
}

void check(int length,int num){
	int res=0;
	int temp=num;
	while(temp!=0){
		res+=pow((temp%10),length);
		temp=temp/10;
	}
	if(res==num){
		printf("\nArmstrong number");
	}
	else{
		printf("\nNot an Armstrong number");
	}
}
