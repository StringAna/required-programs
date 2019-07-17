#include<stdio.h>
#include<stdlib.h>

void reverse();
void create(int);
void display();

struct node{
	int data;
	struct node *next;
}*head;

int main(){
	int count=0;
	
	printf("\nenter the number of elements ");
	scanf("%d",&count);
	if(count<0){
		printf("\ninvalid count.");
		return 0;
	}
	
	create(count);
	printf("\nlist entered is ");
	display();
	reverse();
	printf("\nReversed list is ");
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
	
	printf("\nenter 1 number value ");
	scanf("%d",&value);
	head->data=value;
	head->next=NULL;
	temp=head;
	
	for(i=2 ; i<=count ; i++){
		struct node *nn=(struct node *)malloc(sizeof(struct node));
		if(nn==NULL){
			printf("\n/memory not allocated");
			return;	
		}
		printf("\nenter %d number value ",i);
		scanf("%d",&value);
		nn->data=value;
		nn->next=NULL;
		temp->next=nn;
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

void reverse(){
	struct node *prev=(struct node *)malloc(sizeof(struct node));
	struct node *cur=(struct node *)malloc(sizeof(struct node));
	
	prev=head;
	cur=head->next;
	head=head->next;
	
	prev->next=NULL;
	
	while(head!=NULL){
		head=head->next;
		cur->next=prev;
		prev=cur;
		cur=head;
	}
	head=prev;
}
