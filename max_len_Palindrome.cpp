#include<iostream>
using namespace std;
class Solution
{
 public:
    bool isPalindrome(string A ,int begin ,int end)
    {
      while(begin < end)
      {
        if(A[begin]!=A[end])
        {
          return false;
        }
        begin++;
        end--;
      }
      return true;
    }
    int getLongestPalindrome(string A, int n) 
    {
      int* dp=new int [A.size()];
      for(int i=0;i<A.size();i++)
      {
         dp[i]=1; 
      }
      for(int i=0;i<A.size();++i)  
      {
        for(int j=0;j<i;++j)
        {
          if(isPalindrome(A,j,i))
          {
            dp[i]=dp[i] >i-j+1?dp[i]:i-j+1;
          }
        }
      }
      int res=-1;
      for(int i=0;i<A.size();i++)
      {
        if(dp[i]>res)
        {
          res=dp[i];
        }
      }
      return res;
    }
};
int main()
{
  Solution s;
  string str;
  while(1)
  {
  cin >> str;
 cout <<  s.getLongestPalindrome(str,str.size()) <<endl;
  }
}
