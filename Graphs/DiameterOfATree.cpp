/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    public:
    int height(TreeNode* root){
      if(root==nullptr){
         return 0;
      }
      int leftt=1+height(root->left);
      int rightt=1+height(root->right);
      return max(leftt,rightt);
    }
    void solve(TreeNode* root,int &ans){
        if(root==nullptr){
            return;
        }
        ans=max(ans,(height(root->left)+height(root->right)));
        solve(root->left,ans);
        solve(root->right,ans);
    }
        int diameterOfBinaryTree(TreeNode* root) {
     int ans=0;
     solve(root,ans);
    return ans;
        }
    };