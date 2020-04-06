/*Given a list of numbers with only 3 unique numbers (1, 2, 3), sort the list in O(n) time.*/

#include <bits/stdc++.h> 
using namespace std; 

/*To sort the array.Pass array and size of array as parameters*/
void sortUnique(int a[], int size) 
{ 
	int lo = 0; 
	int hi = size - 1; 
	int mid = 0; 

	/*We start iterating for the medium ptr,until the medium ptr is greater than the high ptr.This is the 
	condition for the while loop*/
	while (mid <= hi) {
		/*THE LOGIC:
		Take a sample array
			1	2	3	1	2	3
		mid and low point to the 0th index
		and high points at the last element
		
		(case 1)
		The first element is 1.As soon as we look at any element that is 1,we swap mid and low pointer's
		values.
		Then increment mid and low pointer.
		
		(case 2)
		mid and low both point to index value 1,which holds integer value 2.2 should lie between 1's and 3's,
		and mid should point to the group of 2's.Now when we see 2 at index 1, we skip it because it should 
		occur in the middle.
		Increment mid.
		
		(case 3)
		As soon as we see 3, we know that it should form the last part of the group.So we swap 3 with high ptr.
		Decrement high ptr.
		*/ 
		switch (a[mid]) { 
		case 1: 
			swap(a[lo++], a[mid++]); 
			break; 

		// If the element is 1 . 
		case 2: 
			mid++; 
			break; 

		// If the element is 2 
		case 3: 
			swap(a[mid], a[hi--]); 
			break; 
		} 
	} 
} 

// Function to print array arr[] 
void display(int arr[], int size) 
{ 
	// Iterate and print every element 
	for (int i = 0; i < size; i++) 
		cout << arr[i] << " "; 
} 

int main() 
{ 
	int arr[] = { 1, 2, 2, 1, 2, 3, 2, 3, 1, 1, 1, 2 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 

	sortUnique(arr, n); 

	cout << "array after segregation "; 

	display(arr, n); 

	return 0; 
} 
