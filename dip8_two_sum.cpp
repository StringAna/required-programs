#include<iostream>
#include<map>
#include<iterator>
#include<vector>
using namespace std;

std::pair<int,int> twoSum(int arr[],int target,int arr_size){
	map<int,int> hTable;
	int i=0,diff=0;
	pair<int,int> res;
	
	//insert the array elements into the map
	for(int i=0 ; i<arr_size ; i++){
		hTable.insert(pair<int,int>(i,arr[i]));
	}
	
	for(i=0 ; i<arr_size ; i++){
		diff=target-arr[i];
		if(hTable.find(diff)!=hTable.end()){
			if(i!=hTable[diff]){
			res.first=hTable[diff];
			res.second=i;
			return res;
		}
		}
		else{
			hTable[arr[i]]=i;
		}
	}
}


int main(){
	int size;
	cout<<"\nEnter array size : ";
	cin>>size;
	int a[size],x;
	cout<<"\nEnter the array values :\n";
	for(int j=0 ; j<size ; j++){
		cin>>a[j];
		cout<<endl;
	}
	cout<<"\nEnter target element : ";
	cin>>x;
	//storing the values returned in a pair
	pair<int,int> p=twoSum(a,x,size);
	
	//printing the values retured
	if(p.first==-1 && p.second==-1){
		cout<<"\nNo 2 elements qualify\n";
	}
	else{
		cout<<"\nThe indices that add up to the target element "<<x<<" are :"<<endl<<p.first<<" and "<<p.second<<"\n";
	}
	return 0;
}
