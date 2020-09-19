class Solution {
  public:
        /**
         *      * 
         *           * @param root TreeNode类 
         *                * @return int整型
         *                     */
    int maxDepth(TreeNode* root) {
                  if(!root)
                 {
                    return 0;
                 }
                 int left=maxDepth(root->left)+1;
                 int right = maxDepth(root->right)+1;
                   return left > right ? left : right;
                 }
  };
