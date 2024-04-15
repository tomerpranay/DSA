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
    void sol(TreeNode *root,int &ans, int c){
        if(root==NULL) return;
        c=c*10+root->val;
        if(root->left==NULL && root->right==NULL){
            ans+=c;
        }
        sol(root->left,ans,c);
        sol(root->right,ans,c);
    }
    int sumNumbers(TreeNode* root) {
        int ans=0;
        sol(root,ans,0);
        return ans;
    }
};