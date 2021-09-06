#include <iostream>
#include <bits/stdc++.h> 
/**
We have to check if the given matrix is natural latin square or not, meaning every row and col should have values from
1 to N, we can keep a map corresponding to every row and column and check whether all expected values are present are 
not, that solution is also getting accepted, although it is memory expensive, the time complexity in that case
would be O(n^2). Another approach would be to use the given matrix as a map, I am checking for rows initially and 
at each element I am marking a[a[i]-1]=-a[a[i]-1] to mark the present of ith element. Later we would check that 
if all elements in row are negative, that that row is same and we won't have to add that as an outlier. We also have
to bring the matrix back to original state for further checking the columns, that I am doing during the row check and 
removing the negative sign that we have added.
Similar to rows, for columns we'll repeat the same process and then check for negative values in a column this time
and add the outlier columns to our count.
**/

using namespace std;

int main()
{
    int t;
    cin>>t;
    int Case=1;
    while(t--)
    {
        int n;
        cin>>n;
        int matrix[n][n];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>matrix[i][j];
            }
        }
        int trace=0;
        int numberRow=0,numberCol=0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                
                int t = abs(matrix[i][j]);
                if(i==j)
                {
                    trace+=t;
                }
                if(t<=n && t!=0)
                {
                    matrix[i][t-1] = -matrix[i][t-1]; 
                }
            }
        }
       
        int f=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]>=0 || matrix[i][j]>n)
                {
                    if(f!=1)
                        numberRow++;
                    f=1;                    
                }
                if(matrix[i][j]<0)
                {
                    matrix[i][j] =-matrix[i][j];
                }
                
            }
            f=0;
        }

         for(int j=0;j<n;j++)
        {
            for(int i=0;i<n;i++)
            {
                
                int t = abs(matrix[i][j]);
                if(t<=n && t!=0)
                {
                    matrix[t-1][j] = -matrix[t-1][j]; 
                }
            }
        }
        for(int j=0;j<n;j++)
        {
            for(int i=0;i<n;i++)
            {
                if(matrix[i][j]>=0 || matrix[i][j]>n)
                {
                    numberCol++;
                    break;    
                }
                
            }
        }
        cout<<"Case #"<<Case<<": "<<trace<<" "<<numberRow<<" "<<numberCol<<endl;
        Case++;
    }
    
}