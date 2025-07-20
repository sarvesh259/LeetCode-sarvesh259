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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        queue<pair<TreeNode*,long long>> q;
        q.push({root,0});
        int ans=0;
        while(!q.empty())
        {
            long long lmax=q.front().second,rmax=q.back().second;
            long long n=q.size();
            ans=max(ans,(int)(rmax-lmax+1));
            for(int i=0;i<n;i++)
            {
                TreeNode* node=q.front().first;
                long long lvl=q.front().second-lmax;
                q.pop();
                if(node->left)
                {
                    q.push({node->left,((2LL*lvl)+1LL)});
                }
                if(node->right)
                {
                    q.push({node->right,(2LL*lvl)+2LL});
                }
            }
        }
        return ans;
    }
};