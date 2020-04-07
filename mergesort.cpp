#include<iostream>
using namespace std;

main()
{
	int i=6,j=4,k=0,c[10];
	int a[6]={5,4,3,2,6,1};
	int b[4]={6,8,1,21};
	while(i<6 && j<4)
	{
		if(a[i]<=b[j])
		{
			c[k++]=a[i++];
		}
		else
		{
			c[k++]=b[j++];
		}
	}
	while(i<6)
	{
		c[k++]=a[i++];
	}
	while(j<4)
	{
		c[k++]=b[j++];
	}
	for(i=0 ; i<10 ; i++)
	{
		cout<<c[i]<<"	";
	}
}
