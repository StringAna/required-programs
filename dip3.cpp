/*This code is from geeksforgeeks. The logic for this is explained in a YouTube video.I am linking them both down 
here
The video  :  https://youtu.be/UflHuQj6MVA
The code   :  https://www.geeksforgeeks.org/longest-palindrome-substring-set-1/
*/

#include<iostream>
#include<string.h>
using namespace std;

void longestPalinSubstr(string s){
	int len=s.length();
	int maxlen=1;
	/*start stores the starting index so that it can be used to print the output substring*/
	int start=0;
	int i,j,k;
	
	int dp[len][len];
	memset(dp,0,sizeof(dp));
	
	//for substr with length 1
	//a single character is always a plaindrome
	for(i=0 ; i<len ; i++){
		dp[i][i]=1;
	}
	
	//for substr with length 2
	//both characters should be equal
	for(i=0 ; i<len-1 ; i++){
		if(s[i]==s[i+1]){
			dp[i][i+1]=1;
			start=i;
			maxlen=2;
		}
	}
	
	//for substrings with length greater than 2
	/*step 1: compare boundary elements
	  if step 1 is true,then 
	  				step 2: non boundary substring should be palindrome*/
	  				
	//this loop traverses the entire string
	for(k=3 ; k<=len ; ++k){
		//set the starting index of substring by len-k+1
		//starting index = i
		for(i=0 ; i<len-k+1 ; ++i){
			
			//calculate the ending index by starting index i and length of substring k
			j=i+k-1;
			
			//checking the substring from i to j using step 1 and step 2
			if( (s[i]==s[j]) && (dp[i+1][j-1]==1) ){
				dp[i][j]=1;
				
				/*k will give the length of the substring that is being traversed . So we compare it with 
				  maxlen, and store the max of the two*/
				if(k>maxlen){
					/*store the starting index of the max substring till now*/
					start=i;
					maxlen=k;
				}
			}
		}
	}
	/*print the output*/
	cout<<"\n"<<"The longest palindromic substring is"<<endl;
	for(i=start ; i<(start+maxlen) ; ++i){
		cout<<s[i];
	}
	cout<<"\n"<<"the length of this substring is"<<endl;
	cout<<maxlen;
}

int main(){
	string str;
	cin>>str;
	longestPalinSubstr(str);
	return 0;
}
