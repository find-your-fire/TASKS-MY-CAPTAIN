#include<iostream>
using namespace std;
int main()
{
	int year;
	cout<<"Enter the Year\n";
	cin>>year;
	if(year%4==0)
	{
		cout<<year<<"is leap year.\n";
	}
	else
	{
		cout<<year<<"is not a leap year.\n";
	}
	return 0;
}