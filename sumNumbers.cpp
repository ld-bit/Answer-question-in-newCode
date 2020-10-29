//给定一个二叉树，它的每个结点都存放一个 0-9 的数字，每条从根到叶子节点的路径都代表一个数字。
//例如，从根到叶子节点路径 1->2->3 代表数字 123。
//计算从根到叶子节点生成的所有数字之和。
//说明: 叶子节点是指没有子节点的节点。
struct TreeNode
{
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode()
   :val(0),left(nullptr),right(nullptr)
  {}
};
class Solution {
  public:
    void dfs(TreeNode* root,int num)
    {
      if(root==nullptr)
        return;
      if(root->left==nullptr&&root->right==nullptr)
      {
        num=num*10+root->val;
        res+=num;
        return;
      }
      num=num*10+root->val;
      dfs(root->left,num);
      dfs(root->right,num);
    }
    int sumNumbers(TreeNode* root)
    {
      dfs(root,0);
      return res;
    }
private:
    int res=0;
};

