#include<iostream>
using namespace std;
int jump_stp(int n)
{
  if(n==0)
    return 0;
  int* dp=new int[n+1];
  dp[0]=1;
  dp[1]=1;
  for(int i=2;i<=n;++i)
  {
    for(int j=0;j<i;++j)
    {
      dp[i]+=dp[j];
    }
  }
  return dp[n];
}
int main()
{
  int n;
  cin >> n;
  cout << jump_stp(n) <<endl; 
  return 0;
}
