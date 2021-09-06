#include <iostream>
#include <bits/stdc++.h> 
/**
The initial opening bracket would depend upon the O index elment of the string, let's call it as s. The closing bracket
at the end would be closeCount=s[0].
For later indexes we have to handle 3 major cases:
1. If s[i]==s[i-1]
Then we wouldn't have to add any opening or closing brackets.
2. if s[i]>s[i-1]
Ex -> ((24
we are at 4 currently,
Similar to the example above, we know we already have s[i-1]  open bracket, but we need s[i]-s[i-1] more opening brackets
to satify the opening bracket condition for s[i], also the number of closing bracket at the end have also increased 
from closeCount+s[i]-s[i-1];  
**/
3. If s[i]<s[i-1]
ex=> ((21
we are at 1 currently
we would have to add s[i-1]-s[i] closing brackets now to satisfy the condition for s[i], and also decrease the count of 
closing brackets at the end to closeCount-(s[i-1]-s[i])
**/
using namespace std;

int main()
{
    int t;
    cin>>t;
    int Case=1;
    while(t--)
    {
        string s;
        cin>>s;
        int n = s.size();
        string newString="";
        int open=0;
        for(int i=0;i<n;i++)
        {
            int number=s[i]-'0';
            if(i==0)
            {
                if(number!=0)
                {
                    for(int j=0;j<number;j++)
                    {
                        newString+='(';
                    }
                    open+=number;
                }
            }else
            {
                int curNum = s[i]-'0';
                int prevNum = s[i-1]-'0';
                if(curNum<prevNum)
                {
                    int toBeClosed = prevNum-curNum;
                    open-=toBeClosed;
                    for(int j=0;j<toBeClosed;j++)
                    {
                        newString+=')';
                    }
                }else if(curNum>prevNum)
                {
                    int toBeOpened =  curNum - prevNum;
                    for(int j=0;j<toBeOpened;j++)
                    {
                        newString+='(';
                    }
                    open+=toBeOpened;
                }
            }
            newString+=s[i];
        }

        for(int i=0;i<open;i++)
        {
            newString+=')';
        }
        cout<<"Case #"<<Case<<": "<<newString<<endl;
        Case++;
    }
    
}