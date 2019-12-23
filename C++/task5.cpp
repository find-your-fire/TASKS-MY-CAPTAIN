#include<iostream>
#include<climits>
using namespace std;
int main()
{
	int l=INT_MIN;
	int s=INT_MAX;
	int n;
	cout<<"Enter the size of the array\n";
	cin>>n;
	int a[n];
	cout<<"Enter the elements of array\n";
	for(int i=0;i<n;i++)
    {
    	cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
    	if(a[i]>l)
    	{
    		l=a[i];
    	}	
    }
    cout<<"Largest element in array is: "<<l;
    for(int i=0;i<n;i++)
    {
    	if(a[i]<s)
    	{
    		s=a[i];
    	}	
    }
    cout<<"\nSmallest element in array is: "<<s;
    return 0;
}