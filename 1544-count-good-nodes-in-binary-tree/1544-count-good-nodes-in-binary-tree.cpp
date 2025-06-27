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
    int findAns(TreeNode* root,int maxi)
    {
        if(!root)
            return 0;
        int ans=0;
        int temp=maxi;
        if(maxi<=root->val)
        {
            temp=root->val;
            ans++;
        }
        if(root->left)
            ans+=findAns(root->left,temp);
        if(root->right)
            ans+=findAns(root->right,temp);
            cout<<root->val<<" "<<maxi<<endl;
        return ans;
    }
    int goodNodes(TreeNode* root) {
        int ans=1;
        if(!root)
            return 0;
        ans+=findAns(root->left,root->val);
        ans+=findAns(root->right,root->val);
        return ans;
    }
};