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
    TreeNode* lca(TreeNode* p,TreeNode* q,TreeNode* root){
        if(root==nullptr) return nullptr;
        if(root==p || root==q) return root;
        TreeNode* left=lca(p,q,root->left);
        TreeNode* right=lca(p,q,root->right);
        if(left!=nullptr && right!=nullptr) return root;
        if(left==nullptr) return right;
        return left;
    }
    void level(TreeNode* root,vector<TreeNode*> &vec){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            vector<TreeNode*> v;
            // cout<<q.size()<<" ";
            int len=q.size();
            for(int i=0;i<len;i++){
                TreeNode* node=q.front();
                v.push_back(node);
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            if(v.size()==0) continue;
            // for(TreeNode* it:v){
            //     cout<<it->val<<" ";
            // }
            // cout<<endl;
            vec=v;
        }
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if(root==nullptr) return root;
        vector<TreeNode*> vec;
        level(root,vec);
        // cout<<vec[vec.size()-1]->val;
        TreeNode* p=vec[0];
        TreeNode* q=vec[vec.size()-1];
        return lca(p,q,root);
    }
};