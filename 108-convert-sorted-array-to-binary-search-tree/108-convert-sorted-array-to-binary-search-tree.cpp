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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int x=nums.size();
        if(x==0)
        {
            return NULL;
        }
        if(x==1)
        {
            TreeNode* root=new TreeNode(nums[0]);
            return root;
        }
        x=x/2;
        TreeNode* root=new TreeNode(nums[x]);
        vector<int> lefti(nums.begin(),nums.begin()+x);
        vector<int> right(nums.begin()+x+1,nums.end());
        root->left=sortedArrayToBST(lefti);
        root->right=sortedArrayToBST(right);
        return root;
        
    }
};