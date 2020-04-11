#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
void show(struct node *);
void showRev(struct node *);
struct node * insert(struct node *,int);

int main(){
	struct node *head=NULL;
	head=insert(head,4);
	head=insert(head,6);
	head=insert(head,2);
	head=insert(head,12);
	head=insert(head,34);
	head=insert(head,3);
	head=insert(head,40);
	printf("\nnormal order::\n");
	show(head);
	printf("\nreverse order::\n");
	showRev(head);
	
	return 0;
}

struct node * insert(struct node *head,int data){
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->data=data;
	temp->next=NULL;
	
	if(head==NULL){
		head=temp;
	}
	else{
		struct node *temp1=head;
		
		while(temp1->next!=NULL){
			temp1=temp1->next;
		}
		temp1->next=temp;
	}
	return head;
}
void show(struct node *p){
	if(p==NULL)return;
	
	printf("\n%d",p->data);
	
	show(p->next);
}

void showRev(struct node *p){
	if(p==NULL)return;
	
	showRev(p->next);
	
	printf("\n%d",p->data);
}
