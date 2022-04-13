#include <iostream>
#include "/Users/Archi/Documents/stdc++.h"
using namespace std;

int main()
{



    int t;
    cin>>t;
    int CASE=1;
    while(t--)
    {
        string required, typed;
        cin>>required>>typed;
        int deleteCount=0;
        int i=0,j=0,n=required.size(),m=typed.size();
        while(i<n && j<m)
        {
          if(required[i]==typed[j])
          {
            i++;
            j++;
          }else{
            j++;
            deleteCount++;
          }
        }
        if(i<n)
        {
          cout<<"Case #"<<CASE<<": IMPOSSIBLE"<<endl;
        }else
        {
          deleteCount+=m-j;
          cout<<"Case #"<<CASE<<": "<<deleteCount<<endl;
        }


        CASE++;


    }
    return 0;
}
