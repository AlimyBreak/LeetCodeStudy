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
            TreeNode* left_bak ;
            TreeNode* right_bak;
            if(node==NULL)
            {
                return NULL;
            }
            left_bak  = node->left;
            right_bak = node->right;
            node->left  = __dfs(node->left);
            node->right = __dfs(node->right);
            
            if(left_bak!=node->left)
            {
                free(left_bak);
            }
            if(right_bak!=node->right)
            {
                free(right_bak);
            }
            
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
运行报错,默认不需要释放.
*/