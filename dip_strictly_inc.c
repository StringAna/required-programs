/*
You are given an array of integers in an arbitrary order. Return whether or not it is possible to make the array
 non-decreasing by modifying at most 1 element to any value
 
 Input: arr[] = {2, 4, 8, 6, 9, 12}
Output: Yes
By modifying 8 to 5, array will become strictly increasing.
i.e. {2, 4, 5, 6, 9, 12}

Input: arr[] = {10, 5, 2}
Output: No

Okay,so the second example had me there,but then I read the question AGAIN, and it says ATMOST one modification.

Here goes nothing.

Edit 1: The logic that I used was to check if each element is greater/less than both its previous and next element in the
array.If both are either greater/less than the current element,then replace the current element with the avg of its
successor and predecessor.

EDIT 2:Also,if the modified element is equal to its successor/predecessor,then return false/0.
I put 0th index outside of the loop,since it didn't have any predecessor, but forgot to do the same for the last 
element of the array.Then I corrected myself, which resulted in some errors,so I looked up the code and fixed them.
Don't judge.
*/

#include<stdio.h>

int strictlyInc(int a[],int n){
	//keep a counter to check how many times modification is done
	int flag=0;
	
	//check for the first element
	if(a[0]>a[1]){
		a[0]=a[1]/2;
		flag++;
	}
	
	//now we go from the 2nd to 2nd last element because the last element does not have any successor,and it has to be
	//checked separately just like we did with the first element
	int i;
	for(i=1 ; i<n-1 ; i++){
		if( (a[i]>a[i-1] && a[i]>a[i+1]) || (a[i]<a[i-1] && a[i]<a[i+1])){
			a[i]=(a[i-1]+a[i+1])/2;//modifying a[i]
		
		//checking if the modified a[i] matches with either its successor/predecessor
		if(a[i]==a[i-1] || a[i]==a[i+1]){
			return 0;
		}
		//increase counter.
		flag++;
		}
	}
	//now we look at the last element and see if it needs modification
	if(a[n-2]>a[n-1]){
		flag++;
	}
	
	//at last we return the value 0/1 according to how many modifications were required(flag's value)
	if(flag>1){
		return 0;
	}
	return 1;
}

int main(){
	int size;
	printf("\nEnter array size : ");
	scanf("%d",&size);
	int arr[size],i;
	printf("\nEnter array elements : \n");
	for(i=0 ; i<size ; i++){
		scanf("%d",&arr[i]);
	}
	printf("\nIs it possible to make the array non-decreasing by modifying at most 1 element to any value?\n");
	
	if(strictlyInc(arr,size)){
		printf("\nPossible");
	}
	else{
		printf("\nNot possible");
	}
	return 0;
}
