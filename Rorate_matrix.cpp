#include<vector>
#include <iostream>
using namespace std;
vector<vector<int>>rorate_maxtrix(vector<vector<int>>arr)
{
  vector<vector<int>>res(arr.size(),vector<int>(arr[0].size(),0));
  for(int i=0;i<arr.size();i++)
  {
    for(int j=0;j<arr[0].size();j++)
    {
      res[j][arr.size()-1-i] = arr[i][j];
    }
  }
  return res;
}
void display(vector<vector<int>>arr)
{
  vector<vector<int>>res =  rorate_maxtrix(arr);
  for(int i=0;i<arr.size();i++)
  {
    for(int j=0;j<arr[i].size();j++)
    {
        cout << res[i][j]<<" ";
    }
    cout << endl;
  }
}
int main()
{
  cout << "row : " << endl;
  int row ;
  cin >> row;
  cout << "col: " << endl;
  int col;
  cin >> col;
  vector<vector<int>>arr(row,vector<int>(col,0));
  for(int i=0;i<row;i++)
  {
    for(int j=0;j<arr[i].size();j++)
    {
      cin >> arr[i][j];
    }
  }
  display(arr);
}
