#include<iostream>
using namespace std;
int main()
{
	int sum=0;
	int n;
	cout<<"Enter the size of the array\n";
	cin>>n;
	int array[n];
	cout<<"Enter the elements of array\n";
	for(int i=0;i<n;i++)
    {
    	cin>>array[i];
    }
    for(int i=0;i<n;i++)
    {
    	sum=sum+array[i];
    }
    cout<<"\nSum of elements of array is: "<<sum;
    return 0;
}