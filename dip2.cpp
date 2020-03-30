//https://youtu.be/mtHelVTLKRQ
//the logic in this video is used here.I loved the use of sets for this problem.Easy and crisp.
#include<iostream>
#include<set>
#include<iterator>
#include<string>
using namespace std;

int lgtOfLongestSubstr(string s){
	if(s.length()==0){
		return 0;
	}
	set<int> mySet;
	
	int left=0,right=0,max=0;
	
	while(right<s.length()){
		if(mySet.insert(s.at(right)).second==true){//expanding the window
			right++;
			max=(right-left)>max?(right-left):max;
		}
		else{//shifting the window
			mySet.erase(s.at(left++));
		}
	}
	return max;
}

int main(){
	string str;
	cin>>str;
	int len=lgtOfLongestSubstr(str);
	cout<<"Max length of substr "<<len<<endl;
	return 0;
}
