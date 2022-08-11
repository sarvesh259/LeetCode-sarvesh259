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
    void toadd(vector<int> &a,TreeNode* root)
    {  if(root==NULL)
            return;
        toadd(a,root->left);
        a.push_back(root->val);
        toadd(a,root->right);
        return;
}
    bool isValidBST(TreeNode* root) {
        vector<int> a;
        toadd(a,root);
        for(int i=1;i<a.size();i++)
        {
            if(a[i-1]>=a[i])
                return false;
        }
        return true;
        vector<int> b(a.begin(),a.end());
        sort(b.begin(),b.end());
        return a==b;
    }
};