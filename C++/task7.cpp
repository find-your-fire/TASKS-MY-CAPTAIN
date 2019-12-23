#include<iostream>
using namespace std;
void swap(int &x,int &y)
{
	int t;
	t=x;
	x=y;
	y=t;

}
int main()
{
	int x,y;
	cout<<"Enter value of x and y\n";
	cin>>x>>y;
	swap(x,y);
	cout<<"The swap values are:\n"<<"x: "<<x<<"\ny: "<<y;
	return 0;

}