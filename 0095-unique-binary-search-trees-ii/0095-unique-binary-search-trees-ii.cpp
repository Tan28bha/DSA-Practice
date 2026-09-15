class Solution {
public:

    vector<TreeNode*> build(int start, int end)
    {
        vector<TreeNode*> result;

        if(start > end)
        {
            result.push_back(NULL);
            return result;
        }

        for(int i = start; i <= end; i++)
        {
            vector<TreeNode*> leftTrees = build(start, i-1);
            vector<TreeNode*> rightTrees = build(i+1, end);

            for(auto left : leftTrees)
            {
                for(auto right : rightTrees)
                {
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;

                    result.push_back(root);
                }
            }
        }

        return result;
    }

    vector<TreeNode*> generateTrees(int n) {

        return build(1,n);
    }
};