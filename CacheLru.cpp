#include<iostream>
#include<vector>
#include<list>
#include<unordered_map>
#include<utility>
using namespace std;
//设计LRU缓存结构，该结构在构造时确定大小，假设大小为K，并有如下两个功能
//set(key, value)：将记录(key, value)插入该结构
//get(key)：返回key对应的value值
//[要求]
//set和get方法的时间复杂度为O(1)
//某个key的set或get操作一旦发生，认为这个key的记录成了最常使用的。
//当缓存的大小超过K时，移除最不经常使用的记录，即set或get最久远的。
//若opt=1，接下来两个整数x, y，表示set(x, y)
//若opt=2，接下来一个整数x，表示get(x)，若x未出现过或已被移除，则返回-1
//对于每个操作2，输出一个答案
class  CacheLUR
{
public:
  CacheLUR(int n)
    :_capacity(n)
  {}
  int get(int key)
  {
     //如果key在mp里边,直接获取值,然后更新其在链表中的位置
     //如果不在,直接返回-1
     unordered_map<int ,list<pair<int,int>>::iterator>::iterator p=hash_table.find(key);
     if(p==hash_table.end())
     {
       return -1;
     }
     else 
     {
       list<pair<int,int>>::iterator q=p->second;
       pair<int,int>kv=*q;
       lst.erase(q);
       lst.push_front(kv);
       hash_table[kv.first]=lst.begin();
       return  kv.second;
     }
  }
  void set(int key,int value)
  {
    //如果key在哈希表中,更新值和位置
    //key不在,判断大小lst大小是否越界,如果越界,删除最后一个,然后插入
    unordered_map<int,list<pair<int,int>>::iterator>::iterator p=hash_table.find(key);
    if(p==hash_table.end())
    {
      if(lst.size() >=_capacity)
      {
         hash_table.erase(lst.back().first);
         lst.pop_back();
      }
      lst.push_front(make_pair(key,value));
      hash_table[key]=lst.begin();
    }
    else 
    {
      list<pair<int,int>>::iterator q=p->second;
      pair<int,int>kv=*q;
      kv.second=value;
      lst.erase(q);
      lst.push_front(kv);
      hash_table[key]=lst.begin();
    }
  }
private:
  size_t _capacity;
  list<pair<int,int>>lst;
  unordered_map<int , list<pair<int,int>>::iterator > hash_table;
};
void input(vector<vector<int>>& arr)
{
  for(int i=0;i<arr.size();i++)
  {
    for(int j=0;j<arr[i].size();j++)
    {
       cin >> arr[i][j];
    }
  }
}
void display(vector<int> arr)
{
  for(int i=0;i<arr.size();i++)
  {
    cout << arr[i] <<" " ;
  }
  cout << endl;
}
vector<int> Lur(vector<vector<int>>& arr,int k)
{
    vector<int>res;
    CacheLUR lur(k);
    for(int i=0;i<arr.size();i++)
    {
      if(arr[i][0]==1)
      {
        lur.set(arr[i][1],arr[i][2]);
      }
      else 
      {
        res.push_back(lur.get(arr[i][1]));
      }
    }
    return res;
}
int main()
{
  vector<vector<int>>arr; 
  arr.resize(6);
  arr[0].resize(3);
  arr[1].resize(3);
  arr[2].resize(3);
  arr[3].resize(2);
  arr[4].resize(3);
  arr[5].resize(2);
  input(arr);
  display(Lur(arr,3));
  return 0;
}
