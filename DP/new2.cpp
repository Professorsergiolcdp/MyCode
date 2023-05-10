#include <bits/stdc++.h>
using namespace std;
/*
Write a program to test whether a string and all strings that can be made using the characters of that string are palindrome or not.
Eg:
Input Output
mmo ==> True
yakak ==> True
travel ==> False

*/
int main() {
	// your code goes here
	unordered_map<char,int> u_mp;
	
	string str;
	cin>>str;
	
	for(int i=0;i<(int)str.size();i++)
	{
		//cout<<str[i]<<"..";
	    u_mp[str[i]]++;
	}
	
	int cnt=0;
	
	int n=str.size();
	
	if((n%2)==1)
	{
	    for(auto it:u_mp)
	    {
	        if((it.second)&1)
	        {
	        	cnt+=1;
	        }
	    }
	    if(cnt>1)
	    {
	        cout<<"False\n";
	    }
	    else
	    {
	        cout<<"True\n";
	    }
	}
	else
	{
	    for(auto it:u_mp)
	    {
	        //cnt+=(it.second%2);
	        if(((it.second)%2)!=0)
	        {
	        	cnt+=1;
	        }
	    }
	    if(cnt==0)
	    {
	        cout<<"True\n";
	    }
	    else
	    {
	        cout<<"False\n";
	    }
	}
	
	
	return 0;
}
