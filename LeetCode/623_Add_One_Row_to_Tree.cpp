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
    void sol(TreeNode *&root,int cur,int dep,int v){
        if(root==NULL) return;
        if(cur==dep){
            TreeNode *d1=new TreeNode(v);
            TreeNode *d2=new TreeNode(v);
            d1->left=root->left;
            d2->right=root->right;
            root->left=d1;
            root->right=d2;
            return;
        }
        sol(root->left,cur+1,dep,v);
        sol(root->right,cur+1,dep,v);
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==0) return root;
        if(depth==1){
            TreeNode *d=new TreeNode(val);
            d->left=root;
            return d;
        }
        sol(root,1,depth-1,val);
        return root;
    }
};