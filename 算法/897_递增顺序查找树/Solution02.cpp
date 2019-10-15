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
        TreeNode*         ret_val = NULL;
        TreeNode*         cur     = NULL;
        /*中序遍历*/
        void __midOrder(TreeNode* node)
        {
            if(node==NULL)
            {
                return;
            }   
            /* 左 根 右*/
            __midOrder(node->left);
            if(ret_val)
            {
                cur->left   =   NULL;
                cur->right  =   node;
                cur         =   cur->right;
            }
            else
            {
                ret_val =   node        ;
                cur     =   ret_val     ;
            }
            __midOrder(node->right);
        }
        
    public:
        TreeNode* increasingBST(TreeNode* root)
        { 
            ret_val =   NULL;
            cur     =   NULL;
            __midOrder(root);
            if(cur)
            {
                cur->left = NULL;
                cur->right = NULL;
            }
            return ret_val;
        
        }
};

/*
执行结果：
通过
显示详情
执行用时 :44 ms, 在所有 cpp 提交中击败了91.46%的用户
内存消耗 :14.7 MB, 在所有 cpp 提交中击败了100.00%的用户
*/