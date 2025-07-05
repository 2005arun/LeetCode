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
    int countNodes(TreeNode* root) {
        if(root==nullptr) return 0;
        // int lh=findl(root);
        // int rh=findr(root);
        // if(lh==rh) return pow(2,lh)-1;
        // return 1+countNodes(root->left)+countNodes(root->right);

        queue<TreeNode*> q;
        q.push(root);
        int cnt=0;
        while(!q.empty()){
            cnt++;
            TreeNode* node=q.front();
            q.pop();
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        return cnt;
    }
    // int findl(TreeNode* root){
    //     int l=0;
    //     while(root){
    //         l++;
    //         root=root->left;
    //     }
    //     return l;
    // }
    // int findr(TreeNode* root){
    //     int l=0;
    //     while(root){
    //         l++;
    //         root=root->right;
    //     }
    //     return l;
    // }
};