#include<iostream>
#include<queue>
using namespace std;
struct TreeNode
{
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int v=0)
    :val(v)
     ,left(nullptr)
     ,right(nullptr)
  {}
};
class Solution
{
  public:
    bool isExist(TreeNode* p , int val)
    {
      if(p==nullptr)
        return false;
      if(p->val==val)
        return true;
      return isExist(p->left,val)||isExist(p->right,val);
    }
    int nearest_parent(TreeNode* root,int num1,int num2)
    {
      if(root==nullptr)
        return false;
      queue<TreeNode*>qu;
      qu.push(root);
      while(!qu.empty())
      {
        TreeNode* cur = qu.front();
        qu.pop();
        if(cur->val == num1 || cur->val == num2)
          return cur->val;
        if(isExist(cur->left,num1)&&isExist(cur->right,num2))
          return cur->val;
        if(isExist(cur->right,num1)&&isExist(cur->left,num2))
          return cur->val;
        if(cur->left)
          qu.push(cur->left);
        if(cur->right)
          qu.push(cur->right);
      }
      return 0;
    }
};
