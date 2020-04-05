/* Given a sorted array, A, with possibly duplicated elements, find the indices of the first and last occurrences 
of a target element, x. Return -1 if the target is not found.

I looked at mycodeschool's video for confirmation of my logic,it was easy to come up with both the niave and the
optimized solution for this,and although I tried to take the user's input,it was just giving -1
as output for first and last occurrence.One issue to fix.

mycodeschool's vide link : https://www.youtube.com/watch?v=OE7wUUpJw6I
*/
#include<stdio.h>

int firstIndex(int arr[],int n,int x){
	int low=0,high=n-1,result=-1;
	
	while(low<=high){
		printf("\nin while firstindex");
		int mid=(low+high)/2;
		if(x==arr[mid]){
			printf("\nin x=a[mid]");
			result=mid;
			high=mid-1;
		}
		else if(x<arr[mid]){
			printf("\nin x<a[mid]");
			high=mid-1;
		}
		else{
			printf("\nin x>a[mid]");
			low=mid+1;
		}
	}printf("\nout of while firstindex");
	return result;
}

int lastIndex(int arr[],int n,int x){
	int low=0,high=n-1,result=-1;
	
	while(low<=high){
		printf("\nin while lastindex");
		int mid=(low+high)/2;
		if(x==arr[mid]){
			printf("\nin x=a[mid]");
			result=mid;
			low=mid+1;
		}
		else if(x<arr[mid]){
			printf("\nin x<a[mid]");
			high=mid-1;
		}
		else {
			printf("\nin x>a[mid]");
			low=mid+1;
		}
	}
	return result;
}

int main(){
	int a[]={2, 5, 5, 5, 6, 6, 8, 9, 9, 9};
	int len = sizeof(a)/sizeof(a[0]);
	int ele=5;
	printf("\nFirst occurence of element at index :  %d",firstIndex(a,len,ele));
	printf("\nLast occurence of element at index :  %d",lastIndex(a,len,ele));
	
	return 0;
}
