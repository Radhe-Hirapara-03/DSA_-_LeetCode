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
    int solve(TreeNode* root,int dir,int sum){
        if(!root) return 0;
        int left=0;
        int right=0;
        if(dir==-1){
            left = solve(root->left,-1,1);
            right = solve(root->right,1,sum+1);
        }
        else{
            left = solve(root->left,-1,sum+1);
            right = solve(root->right,1,1);
        }
        return max(sum,max(left,right));
    }
    int longestZigZag(TreeNode* root) {
        return max(solve(root->left,-1,1),solve(root->right,1,1));
    }
};
