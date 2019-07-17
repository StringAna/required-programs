#include <iostream>
using namespace std;
int main()
{
	int lb,ub,mib,a[10],ele,i;
	cout<<"enter array :	";
	cout<<"\n";
	for (i=0 ; i<10 ; i++)
	{
		cout<<"enter a["<<i<<"] : - ";
		cin>>a[i];
	}
	cout<<"enter element to be searched : ";
	cin>>ele;
	lb=0;
	ub=9;
	while(lb<=ub)
	{
		int mid=(lb+ub)/2;
		if(a[mid]==ele)
		{
			cout<<"element found at index number "<<mid;
			return 0;
		}
		else if(a[mid]<ele)
			lb=mid+1;
		
		else if(a[mid]>ele)
			ub=mid-1;
	}
	cout<<"search unsuccessfull";
	return 1;
}
