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
        TreeNode* __dfs(TreeNode* node)
        {
            if(node==NULL)
            {
                return NULL;
            }
            node->left  = __dfs(node->left);
            node->right = __dfs(node->right);
            if(   ( node->left  == NULL  )
                &&( node->right == NULL  )
                &&( node->val   == 0     )
            )
            {
                return NULL;
            }
            return node;
        }
        
    public:
        TreeNode* pruneTree(TreeNode* root)
        {
            root = __dfs(root);
            return root;
        }
};


/*
执行结果：
通过
显示详情
执行用时 :4 ms, 在所有 C++ 提交中击败了88.46% 的用户
内存消耗 :9.7 MB, 在所有 C++ 提交中击败了82.14%的用户
*/