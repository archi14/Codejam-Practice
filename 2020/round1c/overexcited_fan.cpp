#include <bits/stdc++.h>
#include <iostream>

using namespace std;
/**
I am only changing Peppurr's(let's call him P), position with time, and then
at each position checking whether we would have been able to reach that position
in the time taken by P to reach that position.  If the time taken by P to reach
(x,y) is greater or equal to time taken by us to reach (x,y) then it would be possible
to reach that position in that time. we are considering greater time here because it
is given then we can wait at a given position i.e not move at all. So the time taken
would be entirely dependent upon P to reach that interesection position.sz
**/
int main(){
   int t;
   cin>>t;
   int Case=1;
   while(t--)
   {
     int x,y;
     string s;
     cin>>x>>y>>s;
     int time=0;
     int f=0;
     for(int i=0;i<s.size();i++)
     {
        if(s[i]=='S')
        {
          y--;
        }else if(s[i]=='N')
        {
          y++;
        }else if(s[i]=='E')
        {
          x++;
        }else
        {
          x--;
        }
        time++;
        if((x==0 && y==0) || (abs(x)+abs(y))<=time)
        {
          f=1;
          break;
        }
     }
     if(f)
     {
       cout<<"Case #"<<Case<<": "<<time<<endl;
     }else
     {
       cout<<"Case #"<<Case<<": "<<"IMPOSSIBLE"<<endl;
     }
     Case++;
   }


}
