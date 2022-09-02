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
    void traverse(TreeNode* root, int lvl,vector<vector<int>> &a)
    {
        if(!root)
            return;
        if(a.size()>=lvl)
        {
            vector<int> temp;
            a.push_back(temp);
        }
        a[lvl].push_back(root->val);
        traverse(root->right,lvl+1,a);
        traverse(root->left,lvl+1,a);
    }
    vector<double> averageOfLevels(TreeNode* root) {
        vector<vector<int>> a;
        traverse(root,0,a);
        vector<double> ans;
        for(auto i: a)
        {
            if(i.size()>0)
            {
                double temp=0;
                for(auto j:i)
                {
                    temp+=j;
                }
                temp=temp/i.size();
                ans.push_back(temp);
                }
        }
        return ans;
    }
};