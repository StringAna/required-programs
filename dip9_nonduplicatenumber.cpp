/*Given a list of numbers, where every number shows up twice except for one number, find that one number.
Find a way to do this using O(1) memory.

LOGIC: XOR of a number with itself is 0 and XOR of a number with 0 is the number itself.
*/
#include<iostream>
using namespace std;

int findUnique(int arr[],int arr_size){
	int res;
	for(int i=0 ; i<arr_size ; i++){
		res^=arr[i];
	}
	return res;
}

int main(){
	int size;
	cout<<"\nEnter size of array : ";
	cin>>size;
	int a[size];
	cout<<"\nEnter elements in the array :\n";
	for(int i=0 ; i<size ; i++){
		cin>>a[i];
	}
	cout<<"\nThe unique number is "<<findUnique(a,size);
	return 0;
}
