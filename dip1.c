#include<stdio.h>
#include<stdlib.h>
//using namespace std;

struct node{
	int num;
	struct node *link;
};

/*create a new node and insert the data*/
struct node * createll(int n){
	struct node *newnode=(struct node *)malloc(sizeof(newnode));
	newnode->num=n;
	newnode->link=NULL;
	return newnode;
}

/*to push a node at the beginning of singly LL*/
void ins(struct node **headref,int data)
					/*https://www.quora.com/What-is-the-advantage-of-passing-double-pointer-as-an-argument-to-a-function-in-c*/
{
	/*node allocation*/
	struct node *newnode=createll(data);
	
	/*attach this new node's link to the head of already existing linked list*/
	newnode->link=(*headref);
	
	/*move head's reference and make it point to the newly created node*/
	(*headref)=newnode;
}

/*add two LL's contents.Return the head of the resultant LL*/
struct node* addnum(struct node *a,struct node *b){
	struct node *res=NULL;
	struct node *temp,*prev=NULL;
	int carry=0,sum;
	
	while(a!=NULL || b!=NULL){
		// (i)  Carry 
        // (ii) Next digit of first list (if there is a next digit) 
        // (ii) Next digit of second list (if there is a next digit) 
        sum = carry + (a? a->num: 0) + (b? b->num: 0);
        
        //update the carry
        carry=(sum>=10)?1:0;
        
        //change the sum if it is greater than 10
        sum=sum%10;
        
        //create a new node to put the sum
        temp=createll(sum);
        
        //if it is the first node,then set it as head
        if(res==NULL){
        	res=temp;
		}
		else{//if it is not the first node then connect it to the rest of the nodes
			prev->link=temp;
		}
		prev=temp;
		
		//set the first and second numbers' pointers to next element
		if(a){
			a=a->link;
		}
		if(b){
			b=b->link;
		}
	}
	if(carry>0){
		temp->link=createll(carry);
	}
	return res;
}
void display(struct node *nde) 
{ 
    while(nde != NULL) 
    { 
        printf("%d ", nde->num); 
        nde = nde->link; 
    } 
    printf("\n"); 
}

int main(){
	struct node *res=NULL;
	struct node *fir=NULL;
	struct node *sec=NULL;
	
	int x,y;
	
	scanf("%d\n%d",&x,&y);
	
	while(x){
		ins(&fir,x%10);
		x=x/10;
	}
	printf("\nFirst list  :-  ");
	display(fir);
	while(y){
		ins(&sec,y%10);
		y=y/10;
	}
	printf("\nSecond list  :-  ");
	display(sec);
	
	res=addnum(fir,sec);
	printf("\nResult  :-  ");
	display(res);
	return 0;
}
 
