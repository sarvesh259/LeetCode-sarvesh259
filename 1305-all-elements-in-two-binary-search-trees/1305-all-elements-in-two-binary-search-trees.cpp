class Solution {
public:
    void allfind(TreeNode* root , vector<int> &list)
    {
        if(root == nullptr)
        {
            return;
        }
        else
        {
            allfind(root->left, list);
            list.push_back(root->val);
            allfind(root->right , list);
        }
        return;
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) 
    {
        vector<int> merge; 
        allfind(root1 , merge);      
        allfind(root2, merge);
        sort(merge.begin(), merge.end());
        return merge;
    }
};
