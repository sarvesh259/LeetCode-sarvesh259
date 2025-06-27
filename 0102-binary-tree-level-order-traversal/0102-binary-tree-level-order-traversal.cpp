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
    void findAns(TreeNode* root, int lvl,vector<vector<int>> &ans)
    {
        if(!root) return;
        if(ans.size()<lvl)
            ans.push_back({});
        ans[lvl-1].push_back(root->val);
        findAns(root->left,lvl+1,ans);
        findAns(root->right,lvl+1,ans);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        findAns(root,1,ans);
        return ans;
    }
};