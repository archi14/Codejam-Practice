#include <iostream>
#include <bits/stdc++.h> 

using namespace std;

/**
We don't have to do too much, just have to make sure that there is no 4 as digit in the given number, what I am doing is keeping all the digits same except 4, for 4 I am changing it to 2 and adding 2 to the second number, since the length of the string in Test3 can be in range 2^100 so I am taking input as a string and doing the computation in a string too.
**/
int main()
{
    int t;
    cin>>t;
    int Case=1;
    while(t--)
    {
       string a;
       cin>>a;
       int n = a.size();
       string b(n,' ');
       for(int i=0;i<n;i++)
       {
           if(a[i]!='4')
           {
               b[i]='0';
           }else{
               a[i]='2';
               b[i]='2';
           }
       } 
        
        long long int i=0;
        while(b[i]=='0' && b.length()!=1)
        {
            i++;
        }
        b = b.substr(i);
        
        cout<<"Case #"<<Case<<": "<<a<<" "<<b<<endl;
        Case++;
    }
}