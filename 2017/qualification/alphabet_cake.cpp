#include "/Users/Archi/Documents/stdc++.h"
#include <iostream>

using namespace std;

/** Considering four cases for this question
1. The current letter in not '?', we move forward simply
2. there is a letter previous to current '?', replace that with the previous letter.
3. If previous is also '?', the we search forward until a letter is found, and replace
all occurence of '?' with that letter.
4. The row could be entirely empty i.e filled with '?', we can do two things.
a) fill it with the elements of above row.
b) if above row is smaller than 0 or is also empty, we add to later set, so that it can
be filled later using the row below it.

Finally we handle the later rows, with filling the row as the elements below it.

**/
int main(){
    int t;
    cin>>t;
    int Case=1;
    while(t--)
    {
        int r,c;
        cin>>r>>c;
        char a[r][c];
        set<int, greater<int> > later;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                cin>>a[i][j];
            }
        }

        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                // If already a word, move forward
                if(a[i][j]!='?')
                {
                    continue;
                }
                // using the previous element
                else if(j-1>=0 && a[i][j-1]!='?')
                {
                    a[i][j] = a[i][j-1];
                }else
                {
                    //search forward for an element
                    int temp = j+1;
                    while(temp<c && a[i][temp]=='?')
                    {
                        temp++;
                    }
                    if(temp!=c)
                    {
                        while(j<temp)
                        {
                            a[i][j] = a[i][temp];
                            j++;
                        }
                    }else
                    {
                        if(i==0)
                        {
                            later.insert(i);
                            continue;
                        }
                        if(later.find(i-1) != later.end())
                        {
                            later.insert(i);
                            continue;
                        }
                        while(j<temp)
                        {
                            a[i][j] = a[i-1][j];
                            j++;
                        }
                    }
                }
            }
        }
            set<int, greater<int> >::iterator itr;

            for ( itr = later.begin(); itr != later.end(); itr++)
            {
                int row = *itr;
                for(int j=0;j<c;j++)
                {
                    a[row][j] = a[row+1][j];
                }
            }

        cout<<"Case #"<<Case<<":"<<endl;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                cout<<a[i][j];
            }
            if(i!=r-1)
              cout<<endl;
        }
        Case++;

      }
  }
