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
    TreeNode* sol(vector<int> &p,int &i,int u){
        if(i>=p.size() || u<p[i]) return NULL;
        TreeNode* root=new TreeNode(p[i++]);
        root->left=sol(p,i,root->val);
        root->right=sol(p,i,u);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return sol(preorder,i,INT_MAX);
    }
};