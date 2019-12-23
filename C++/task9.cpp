#include<iostream>
using namespace std;
int main()
{
	int days;
	cout<<"Enter the days\n";
	cin>>days;
	int year=days/365;
	int remain=days%365;
	int weeks=remain/7;
	int day=remain%7;
	cout<<"Years:"<<year<<endl;
	cout<<"Weeks:"<<weeks<<endl;
	cout<<"Days:"<<day<<endl;
	return 0;
}