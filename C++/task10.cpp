#include<bits/stdc++.h>
using namespace std;
int main()
{
	char s[100];
	gets(s);
	int l=strlen(s);
	for(int i=0;i<l;i++)
	{   
		if(s[i]>=65&&s[i]<=96)
		{s[i]=s[i]+32;}
	}
	cout<<"String in lowercase: "<<s;
	return 0;

}