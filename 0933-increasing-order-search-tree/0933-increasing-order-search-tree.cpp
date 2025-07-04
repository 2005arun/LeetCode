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
    void convert(TreeNode* root,vector<int> &vec){
        if(root==NULL) return;
        vec.push_back(root->val);
        convert(root->left,vec);
        convert(root->right,vec);
        return;
    }
    TreeNode* increasingBST(TreeNode* root) {
        vector<int> vec;
        convert(root,vec);
        sort(vec.begin(),vec.end());
        int i=0;
        // for(auto &i:vec) cout<<i<<" ";
        TreeNode* dummy=new TreeNode(-1);
        TreeNode* head=dummy;
        while(i<vec.size()){
            TreeNode *cur=new TreeNode(vec[i]);
            // cout<<cur->val<<" ";
            dummy->right=cur;
            dummy=dummy->right;
            // cout<<dummy->val<<" ";
            i++;
        }
        // cout<<dummy->val;
        return head->right;
    }
};