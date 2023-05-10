#include<iostream>
using namespace std;
int main()
{
    string s =  "AABAACAABAA";
    int n = (unsigned int) s.size();
    int lps[n];
    //lps - longest prefix that if also suffix for the string ending at index i
    lps[0] = 0;
    int j = 0;
    for(int i =  1; i < n; i++)
    {
        // j i
        // A A B A A C A A B A A
        if(s[i] == s[j])
        {
            lps[i] = j + 1;
            j++;
        }
        else
        {
            //   j i
            // A A B A A C A A B A A

            // not matching then we check if the prefix of the previous string is matching 
            while(j > 0 && s[j] != s[i])
            {
                j = lps[j-1];
            }
            lps[i] = j;   
        }   
    }
    for(auto x: lps)
    {
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}