#include<iostream>
using namespace std;
int main()
{
	int n,temp;
	cout<<"Enter the size of the array\n";
	cin>>n;
	int array[n];
	cout<<"Enter the elements of array\n";
	for(int i=0;i<n;i++)
    {
    	cin>>array[i];
    }
     for (int j = 0; j < n; j++)
	{
        for (int k = j+ 1 ; k < n; k++)
		{
            if (array[j] > array[k])
			{
                temp = array[j];
                array[j] = array[k];
                array[k] = temp;
            }
        }
    }
    cout<<"\nSorted array is:";
    for(int i=0;i<n;i++)
    {
    	cout<<array[i]<<" ";
    }
    return 0;
        
}