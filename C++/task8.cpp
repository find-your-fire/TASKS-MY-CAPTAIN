#include <bits/stdc++.h>
using namespace std;
void Anagram(char a[100],char b[100])
{   bool flag=0;
	int l1=strlen(a);
	int l2=strlen(b);
	if(l1!=l2)
	{
		cout<<a<<"and"<<b<<"are not Anagram\n";
	}
	sort(a,a+l1);
	sort(b,b+l2);
	
	for(int i=0;i<l1;i++)
        {
          if(a[i]!=b[i])
          {
          	cout<<a<<"and"<<b<<"are not Anagram\n";
          	flag=1;
          	break;
          }
        }
        if(flag=0)
        {
        	cout<<a<<"and"<<b<<"are Anagram\n";
        }
}
int main()
{
   char a[100],b[100];
   cout<<"Enter the first string\n";
   gets(a);
   cout<<"Enter the second string\n";
   gets(b);
   Anagram(a,b);	
   return 0;
}