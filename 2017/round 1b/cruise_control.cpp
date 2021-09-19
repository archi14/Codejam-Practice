#include <bits/stdc++.h>
#include <iostream>


struct horse{
  int pos;
  int speed;
};
using namespace std;

int main(){

  int t;
  cin>>t;
  int Case=1;
  while(t--)
  {
    int d,n;
    cin>>d>>n;
    horse h[n];
    for(int i=0;i<n;i++)
    {
      int a,b;
      cin>>a>>b;
      h[i].pos = a;
      h[i].speed = b;
    }

    double maxTime = INT_MIN;
    for(int i=0;i<n;i++)
    {
      int remDistance = d - h[i].pos;
      double timeTaken = (double)remDistance/(double)h[i].speed;
      maxTime = max(maxTime, timeTaken);
    }

    double speedRequired = (double)d/(double)maxTime;
    printf("Case #%d: %lf\n", Case, speedRequired);
    Case++;
  }
}
