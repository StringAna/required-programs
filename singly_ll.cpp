#include<stdio.h>
#include<stdlib.h>
void create(int);
void display();

struct node{
	int data;
	struct node *next;
}*head;

int main(){
	int count;
	printf("\nEnter the number of values you want to enter : ");
	scanf("%d",&count);
	create(count);
	display();
	return 0;
}

void create(int count){
	int i,value;
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	head=(struct node *)malloc(sizeof(struct node));
	if(head==NULL || temp==NULL){
		printf("\n/memory not allocated");
		return;
	}
	
	printf("\nenter 1 no. value = ");
	scanf("%d",&value);
	head->data=value;
	head->next=NULL;
	temp=head;
	for(i=2 ; i<=count ; i++){
		struct node *newnode = (struct node *)malloc(sizeof(struct node));
		if(newnode==NULL){
			printf("\n/memory not allocated");
			return;	
		}
		printf("\nenter %d no. value = ",i);
		scanf("%d",&value);
		newnode->data=value;
		newnode->next=NULL;
		temp->next=newnode;
		temp=temp->next;
	}
}

void display(){
	struct node *temp;
	temp=head;
	if(head==NULL){
		printf("\nlist is empty");
		return;
	}
	while(temp!=NULL){
		printf("\n%d",temp->data);
		temp=temp->next;
	}
}
