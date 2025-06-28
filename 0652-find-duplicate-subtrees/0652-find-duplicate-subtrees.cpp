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
    // int ans=0;
    string ser(TreeNode* root,unordered_map<string,int> &mp,vector<TreeNode*> &ans)
    {
        if(!root) return "/";
        string left=ser(root->left,mp,ans);
        string right=ser(root->right,mp,ans);

        string temp=left+","+right+","+to_string(root->val);
        if(mp[temp]==1) ans.push_back(root);
        mp[temp]++;
        return temp;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        if(!root) return {};
        unordered_map<string,int> mp;
        vector<TreeNode*> ans;
        ser(root,mp,ans);
        return ans;
    }
};