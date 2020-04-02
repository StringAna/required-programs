/*validate balanced paranthesis.

I had this code memorized, as I had solved it before.
One thing that bugs me about this code is that it returns not balanced for strings that have anything other than 
brackets.I will try to fix this in the coming days*/

#include<iostream>
#include<stack>
using namespace std;

bool checkParan(string s){
	stack<char> stk;
	char c;
	
	//Reading the entire string into the stack
	for(int i=0 ; i<s.length() ; i++){
		if(s[i]=='(' || s[i]=='{' || s[i]=='[' ){
			stk.push(s[i]);
		}
		
		/*If no element has been inserted,it means that it is not an opening bracket.Then the string 
		  must be unbalanced*/
		  if(stk.empty()){
		  	return false;
		  }
		
		/*If it is an closing bracket, then we have to check if the top of the stack is its equivalent
		  opening bracket to make a pair.If it is a match, then pop the top of the stack. */
		switch(s[i]){
			case ')': // store the top of the stack in c for comparison 
						 c=stk.top();
						 stk.pop();
						 if(c=='{' || c=='['){
						 	return false;
						 }
						 break;
			
			case ']': // store the top of the stack in c for comparison 
						 c=stk.top();
						 stk.pop();
						 if(c=='(' || c=='{'){
						 	return false;
						 }
						 break;
						 
			case '}': // store the top of the stack in c for comparison 
						 c=stk.top();
						 stk.pop();
						 if(c=='(' || c=='['){
						 	return false;
						 }
						 break;
						 			 			 
		}
	}
	//if the stack is empty, then the string is balanced,else,not balanced.Check for empty stack and return the result
	return (stk.empty());
}

int main(){
	string n;
	cin>>n;
	
	if(checkParan(n)){
		cout<<endl<<"Balanced"<<endl;
	}
	else{
		cout<<endl<<"Not balanced"<<endl;		
	}
	
	return 0;
}
