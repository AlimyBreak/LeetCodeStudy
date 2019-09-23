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
        int i       = 0;
        int kk      = 0;
        int ret_val = 0;
        void __midOrderDfs(TreeNode* node)
        {
            if(node==NULL)
            {
                return ;
            }
            __midOrderDfs(node->left);
            
            if(++i == kk)
            {
                ret_val = node->val;
                return;
            }
            
            __midOrderDfs(node->right);
        }
    
    
    public:
        int kthSmallest(TreeNode* root, int k)
        {
            ret_val = 0;
            i       = 0;
            kk      = k;
            __midOrderDfs(root);
            return ret_val;
        }
};

/*
执行结果：
通过
显示详情
执行用时 :16 ms, 在所有 C++ 提交中击败了99.56% 的用户
内存消耗 :21.2 MB, 在所有 C++ 提交中击败了98.83%的用户
*/