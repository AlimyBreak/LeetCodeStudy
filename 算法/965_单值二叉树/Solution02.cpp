/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
    private:
        bool dfs(TreeNode* node)
        {
            if(node==NULL)
            {
                return true;
            }
            
            if(node->val != val)
            {
                return false;
            }       
            return dfs(node->left) && dfs(node->right);
        }
        int val = 0;
        
    public:
        bool isUnivalTree(TreeNode* root)
        {
            if(root==NULL)
            {
                return true;
            }
            val = root->val;
            return dfs(root);
        }
};

/*
执行结果：
通过
显示详情
执行用时 :8 ms, 在所有 C++ 提交中击败了61.30% 的用户
内存消耗 :10.3 MB, 在所有 C++ 提交中击败了99.64%的用户
*/