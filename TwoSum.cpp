/*

THE QUESTION IS COPIED FROM LEETCODE BECAUSE I AM LAZY :

Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Output: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]
 

Constraints:

2 <= nums.length <= 103
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists

PS: I literally had a dream last night where I was being laughed at and ridiculed because I did not know how to solve 
this problem.

*/

#include<vector>
#include<map>
#include<iostream>
using namespace std;

vector<int> twoSum(vector<int>& a, int target){
	map<int,int> myMap;		//the main guy
	vector<int> res;		//result to be stored here
	
	//entering elements into the hashmap. Nobody talks about this step.
	for(int i=0 ; i<a.size() ; i++){
		myMap[a[i]] = i;
	}
	
	for(int i=0 ; i<a.size() ; i++){
		/*
		
		What happens is, we go to the first key in the hashmap
						 Subtract it's value from the target
						 It gives us the element to be searched in the map
		
		*/
		
		int result = target - a[i];
		
		/*
		
		The if condition will check if "result" is present in the map,and mymap[result]!=i is done to avoid checking the
		current element like an idiot.
				if true :-		push i , since it is the index of the first element of the sum
								push myMap[result], since it is the index of the second element of the sum
								return the resultant vector because we only have to find the first solution (also cz
																			life is complicated enough)
		
		*/
		
		if(myMap.find(result)!=myMap.end() && myMap[result]!=i ){
			res.push_back(i);
			res.push_back(myMap[result]);
			return res;
		}
	}
	return res;
}

int main(){
	int n;
	cout<<"\nEnter the size of array :- ";
	cin>>n;
	cout<<"\nEnter the elements of the array :- ";
	int i,ele;
	vector<int> arr;
	for(i=0 ; i<n ; i++){
		cin>>ele;
		arr.push_back(ele);
		cout<<"\n";
	}
	
	cout<<"\nEnter the target value :- ";
	cin>>ele;
	
	vector<int> resarray = twoSum(arr,ele);
	
	cout<<"\nThe resut is : - [ ";
	for(i=0 ; i<resarray.size() ; i++){
		cout<<resarray.at(i)<<" ";
	}
	cout<<"]";
	
	return 0;
}
