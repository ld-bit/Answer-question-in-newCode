#include<iostream>
#include<set>
#include<vector>
#include<time.h>
using namespace std;
//给定一个数组，求它的无重复全排列
class Solution
{
  public:
    void dfs(vector<int>& arr,set<vector<int>>&st,int n)
    {
      if(n==arr.size())
      {
        st.insert(arr);
        return;
      }
      else 
      {
        for(int i=n;i<arr.size();i++)
        {
         swap(arr[i],arr[n]);
         dfs(arr,st,n+1);
         swap(arr[i],arr[n]);
        }
      }
    }
    vector<vector<int>>permuteUnique(vector<int>& arr)
    {
      set<vector<int>>st;
      dfs(arr,st,0);
      return vector<vector<int>>(st.begin(),st.end());
    }
};
void DisPlay(vector<vector<int>>&&arr)
{
  for(int i=0;i<arr.size();++i)
  {
    for(int j=0;j<arr[0].size();++j)
    {
      cout << arr[i][j] <<" ";
    }
    cout << endl;
  }
}
int main()
{
  int n=0;
  cin >> n;
  vector<int>arr(n,0);
  srand(time(NULL));
  for(int i=0;i<n;i++)
  {
    arr[i]=rand()%n;
  }
  Solution s;
  DisPlay(s.permuteUnique(arr));
  return 0;
}
