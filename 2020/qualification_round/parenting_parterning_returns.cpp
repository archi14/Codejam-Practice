#include <iostream>
#include <bits/stdc++.h> 
/**
I have created a struct wrt to the activity to store the start, end and index of the activity, index because I will
be sorting the activities in increasing order of start time, and while constructing the final ans, I would need 
the original index of the activity.
Firstly, sorting the activities in order of increasing time. I have taken two variable cend and jend for end time
for the current activity Cameron or Jamie are performing currently. Since initially, they are not performing any 
activity, we are setting it to -1.
we are assigning the activity to Cameron if she is free or the ending time of her previous activity is <= to current 
activity starting time. If not, we are checking the similar condition for Jamie, if that is not possible we
have reached to the impossible case.
We can also start with Jamie, but since it is mentioned that there could be multiple answers for a case, we can 
go forward with the choice of our liking. 
**/
using namespace std;
struct Activity{
    int start;
    int end;
    int index;
};

bool comp(Activity a, Activity b)
{
    if(a.start<b.start)
    {
        return true;
    }
    return false;
}
int main()
{
    int t;
    cin>>t;
    int Case=1;
    while(t--)
    {
       int n;
       cin>>n;
       Activity a[n];
       for(int i=0;i<n;i++)
       {
           cin>>a[i].start>>a[i].end;
           a[i].index = i;
       }

        string ans(n,' ');
        
        sort(a,a+n,comp);
        int cend=-1;
        int jend=-1;
        int f=1;
        for(int i=0;i<n;i++)
        {
            if(cend==-1 || cend<=a[i].start)
            {
                cend=a[i].end;
                ans[a[i].index]='C';
            }else if(jend==-1 || jend<=a[i].start)
            {
                jend=a[i].end;
                ans[a[i].index]='J';
            }else{
                f=0;
                break;
            }   
        }
        if(f==0)
        {
            cout<<"Case #"<<Case<<": IMPOSSIBLE"<<endl;
        }else{
            cout<<"Case #"<<Case<<": "<<ans<<endl;
        }
        Case++;
    }
}